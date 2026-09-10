#include "CDD_SBC.h"
#include "CDD_SBC_Cfg.h"
#include "Spi.h"

/*
 * TLF35584 SPI 实现。
 * 写帧：CMD=1、ADDR[14:9]、DATA[8:1]、PAR[0]。
 * 读帧：CMD=0；返回帧的 CMD=1，DATA 仍位于 [8:1]。
 * 本文件所有帧均使用 uint16，对应 MCAL QSPI2 的一个 16 bit 数据元素。
 */
/* TLF35584 SPI：bit15 为读写位，bit0 为全帧偶校验。 */
#define CDD_SBC_SPI_WRITE_MASK          (0x8000U)
#define CDD_SBC_SPI_ADDRESS_SHIFT       (9U)
#define CDD_SBC_SPI_DATA_SHIFT          (1U)
#define CDD_SBC_SPI_ADDRESS_MAX         (0x3FU)
#define CDD_SBC_SPI_RESPONSE_CMD_MASK   (0x8000U)

#define CDD_SBC_REG_PROTCFG             (0x03U)
#define CDD_SBC_REG_SYSPCFG0            (0x04U)
#define CDD_SBC_REG_SYSPCFG1            (0x05U)
#define CDD_SBC_REG_WDCFG0              (0x06U)
#define CDD_SBC_REG_WDCFG1              (0x07U)
#define CDD_SBC_REG_FWDCFG              (0x08U)
#define CDD_SBC_REG_WWDCFG0             (0x09U)
#define CDD_SBC_REG_WWDCFG1             (0x0AU)
#define CDD_SBC_REG_RSYSPCFG0           (0x0BU)
#define CDD_SBC_REG_DEVCTRL             (0x15U)
#define CDD_SBC_REG_DEVCTRLN            (0x16U)
#define CDD_SBC_REG_WWDSCMD             (0x17U)
#define CDD_SBC_REG_SYSFAIL             (0x1AU)
#define CDD_SBC_REG_INITERR             (0x1BU)
#define CDD_SBC_REG_IF                  (0x1CU)
#define CDD_SBC_REG_SYSSF               (0x1DU)
#define CDD_SBC_REG_SPISF               (0x1FU)
#define CDD_SBC_REG_VMONSTAT            (0x26U)
#define CDD_SBC_REG_DEVSTAT             (0x27U)
#define CDD_SBC_REG_PROTSTAT            (0x28U)
#define CDD_SBC_REG_WWDSTAT             (0x29U)

#define CDD_SBC_PROTECTED_REG_COUNT      (7U)
#define CDD_SBC_PROTECTION_KEY_COUNT     (4U)

#define CDD_SBC_DEVCTRL_TRACKER2_MASK    (0x80U)
#define CDD_SBC_DEVCTRL_TRACKER1_MASK    (0x40U)
#define CDD_SBC_DEVCTRL_COM_MASK         (0x20U)
#define CDD_SBC_DEVCTRL_VREF_MASK        (0x08U)
#define CDD_SBC_DEVCTRL_STATE_MASK       (0x07U)

#define CDD_SBC_PROTSTAT_LOCK_MASK       (0x01U)
#define CDD_SBC_WDCFG0_WWD_ENABLE_MASK   (0x08U)
#define CDD_SBC_WDCFG0_FWD_ENABLE_MASK   (0x04U)
#define CDD_SBC_WDCFG0_SPI_TRIGGER_MASK  (0x02U)
#define CDD_SBC_WDCFG0_CYCLE_1MS_MASK    (0x01U)

static CDD_SBC_ErrorType CDD_SBC_LastError = CDD_SBC_ERROR_NONE;

/* 受保护配置寄存器 0x04..0x0A 的固定解锁/重新锁定序列。 */
static const uint8 CDD_SBC_UnlockKeys[CDD_SBC_PROTECTION_KEY_COUNT] =
{
    0xABU, 0xEFU, 0x56U, 0x12U
};

static const uint8 CDD_SBC_LockKeys[CDD_SBC_PROTECTION_KEY_COUNT] =
{
    0xDFU, 0x34U, 0xBEU, 0xCAU
};

static uint8 CDD_SBC_CalculateParity(uint16 frameWithoutParity)
{
    uint16 value = frameWithoutParity;
    uint8 parity = 0U;

    /* 异或所有置位位；返回 1 表示需置 bit0 才能形成偶校验。 */
    while (value != 0U)
    {
        parity ^= (uint8)(value & 1U);
        value >>= 1U;
    }

    return parity;
}

static boolean CDD_SBC_IsEvenParity(uint16 frame)
{
    return (CDD_SBC_CalculateParity(frame) == 0U) ? TRUE : FALSE;
}

static uint16 CDD_SBC_BuildFrame(boolean writeAccess, uint8 address, uint8 data)
{
    uint16 frame = ((uint16)address << CDD_SBC_SPI_ADDRESS_SHIFT) |
                   ((uint16)data << CDD_SBC_SPI_DATA_SHIFT);

    if (writeAccess == TRUE)
    {
        frame |= CDD_SBC_SPI_WRITE_MASK;
    }

    /* 校验位最后加入，保证包含命令、地址、数据在内的全帧为偶校验。 */
    frame |= (uint16)CDD_SBC_CalculateParity(frame);
    return frame;
}

static Std_ReturnType CDD_SBC_Transfer(boolean writeAccess,
                                       uint8 address,
                                       uint8 transmitData,
                                       uint8 *receiveData)
{
    uint16 transmitFrame;
    uint16 receiveFrame = 0U;
    Std_ReturnType result;

    /* 读请求必须提供接收地址；写请求只校验回环响应，不接收数据。 */
    if ((address > CDD_SBC_SPI_ADDRESS_MAX) ||
        ((writeAccess == FALSE) && (receiveData == NULL_PTR)))
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
        return E_NOT_OK;
    }

    transmitFrame = CDD_SBC_BuildFrame(writeAccess, address, transmitData);
    /* 本地变量在 Spi_SyncTransmit 返回前保持有效，符合 EB 缓冲区使用要求。 */
    result = Spi_SetupEB(CDD_SBC_SPI_CHANNEL,
                         (const Spi_DataBufferType *)&transmitFrame,
                         (Spi_DataBufferType *)&receiveFrame,
                         (Spi_NumberOfDataType)1U);
    if (result != E_OK)
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_SPI_SETUP;
        return E_NOT_OK;
    }

    result = Spi_SyncTransmit(CDD_SBC_SPI_SEQUENCE);
    if (result != E_OK)
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_SPI_TRANSFER;
        return E_NOT_OK;
    }

    /* 写命令回环；读命令的有效响应带 CMD=1 且须通过偶校验。 */
    if (writeAccess == TRUE)
    {
        if (receiveFrame != transmitFrame)
        {
            CDD_SBC_LastError = CDD_SBC_ERROR_SPI_RESPONSE;
            return E_NOT_OK;
        }
    }
    else
    {
        if (CDD_SBC_IsEvenParity(receiveFrame) == FALSE)
        {
            CDD_SBC_LastError = CDD_SBC_ERROR_SPI_PARITY;
            return E_NOT_OK;
        }

        if ((receiveFrame & CDD_SBC_SPI_RESPONSE_CMD_MASK) == 0U)
        {
            CDD_SBC_LastError = CDD_SBC_ERROR_SPI_RESPONSE;
            return E_NOT_OK;
        }

        *receiveData = (uint8)((receiveFrame >> CDD_SBC_SPI_DATA_SHIFT) & 0xFFU);
    }

    CDD_SBC_LastError = CDD_SBC_ERROR_NONE;
    return E_OK;
}

static Std_ReturnType CDD_SBC_WriteProtectionSequence(const uint8 *keys)
{
    uint8 index;

    /* 四个密钥必须连续写入 PROTCFG，失败时不得继续后续受保护操作。 */
    for (index = 0U; index < CDD_SBC_PROTECTION_KEY_COUNT; index++)
    {
        if (CDD_SBC_WriteRegister(CDD_SBC_REG_PROTCFG, keys[index]) != E_OK)
        {
            CDD_SBC_LastError = CDD_SBC_ERROR_PROTECTION;
            return E_NOT_OK;
        }
    }

    return E_OK;
}

static Std_ReturnType CDD_SBC_ReadProtectedRequest(uint8 address, uint8 *data)
{
    uint8 invertedData;

    if (CDD_SBC_ReadRegister(address, &invertedData) != E_OK)
    {
        return E_NOT_OK;
    }

    /* 芯片对保护配置的读回值逐位取反；输出恢复为待写入的真实配置。 */
    *data = (uint8)(~invertedData);
    return E_OK;
}

static Std_ReturnType CDD_SBC_ReconfigureWatchdog(boolean enabled,
                                                   uint8 halfPeriodSteps)
{
    uint8 protectedData[CDD_SBC_PROTECTED_REG_COUNT];
    uint8 readData;
    uint8 index;
    Std_ReturnType configurationResult = E_OK;
    CDD_SBC_ErrorType configurationError = CDD_SBC_ERROR_NONE;
    static const uint8 verifyMasks[CDD_SBC_PROTECTED_REG_COUNT] =
    {
        0x01U, 0xFFU, 0xFFU, 0x1FU, 0x1FU, 0x1FU, 0x1FU
    };

    /* 受保护寄存器读取值按芯片协议取反，先完整读取以保留无关配置位。 */
    for (index = 0U; index < CDD_SBC_PROTECTED_REG_COUNT; index++)
    {
        if (CDD_SBC_ReadProtectedRequest((uint8)(CDD_SBC_REG_SYSPCFG0 + index),
                                         &protectedData[index]) != E_OK)
        {
            return E_NOT_OK;
        }
    }

    /* 仅修改 WDCFG0 的 WWD/FWD/SPI trigger/cycle 字段，其他保护设置保留。 */
    protectedData[2] &= (uint8)(~(CDD_SBC_WDCFG0_WWD_ENABLE_MASK |
                                  CDD_SBC_WDCFG0_FWD_ENABLE_MASK |
                                  CDD_SBC_WDCFG0_SPI_TRIGGER_MASK |
                                  CDD_SBC_WDCFG0_CYCLE_1MS_MASK));
    protectedData[2] |= CDD_SBC_WDCFG0_CYCLE_1MS_MASK;
    if (enabled == TRUE)
    {
        protectedData[2] |= CDD_SBC_WDCFG0_WWD_ENABLE_MASK |
                            CDD_SBC_WDCFG0_SPI_TRIGGER_MASK;
    }
    protectedData[5] = (uint8)(halfPeriodSteps - 1U);
    protectedData[6] = (uint8)(halfPeriodSteps - 1U);

    if (CDD_SBC_WriteProtectionSequence(CDD_SBC_UnlockKeys) != E_OK)
    {
        return E_NOT_OK;
    }

    if ((CDD_SBC_ReadRegister(CDD_SBC_REG_PROTSTAT, &readData) != E_OK) ||
        ((readData & CDD_SBC_PROTSTAT_LOCK_MASK) != 0U))
    {
        (void)CDD_SBC_WriteProtectionSequence(CDD_SBC_LockKeys);
        CDD_SBC_LastError = CDD_SBC_ERROR_PROTECTION;
        return E_NOT_OK;
    }

    /* 解锁后必须把全部 7 个保护寄存器写回，再执行锁定序列。 */
    for (index = 0U; index < CDD_SBC_PROTECTED_REG_COUNT; index++)
    {
        if (CDD_SBC_WriteRegister((uint8)(CDD_SBC_REG_SYSPCFG0 + index),
                                  protectedData[index]) != E_OK)
        {
            configurationResult = E_NOT_OK;
            configurationError = CDD_SBC_LastError;
            break;
        }
    }

    /* 锁定前的读回仍是反码，故与软件镜像异或后应得到 0xFF。 */
    for (index = 0U;
         (index < CDD_SBC_PROTECTED_REG_COUNT) && (configurationResult == E_OK);
         index++)
    {
        if ((CDD_SBC_ReadRegister((uint8)(CDD_SBC_REG_SYSPCFG0 + index),
                                  &readData) != E_OK) ||
            (((uint8)(readData ^ protectedData[index])) != 0xFFU))
        {
            configurationResult = E_NOT_OK;
            configurationError = CDD_SBC_ERROR_VERIFY;
        }
    }

    if (CDD_SBC_WriteProtectionSequence(CDD_SBC_LockKeys) != E_OK)
    {
        return E_NOT_OK;
    }

    if (configurationResult != E_OK)
    {
        CDD_SBC_LastError = configurationError;
        return E_NOT_OK;
    }

    if ((CDD_SBC_ReadRegister(CDD_SBC_REG_PROTSTAT, &readData) != E_OK) ||
        ((readData & CDD_SBC_PROTSTAT_LOCK_MASK) == 0U))
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PROTECTION;
        return E_NOT_OK;
    }

    /* 重新锁定后等待芯片搬运新配置，再使用 RSYSPCFGx 做最终确认。 */
    CDD_SBC_DELAY_US(CDD_SBC_CONFIG_APPLY_DELAY_US);

    for (index = 0U; index < CDD_SBC_PROTECTED_REG_COUNT; index++)
    {
        if ((CDD_SBC_ReadRegister((uint8)(CDD_SBC_REG_RSYSPCFG0 + index),
                                  &readData) != E_OK) ||
            ((readData & verifyMasks[index]) !=
             (protectedData[index] & verifyMasks[index])))
        {
            CDD_SBC_LastError = CDD_SBC_ERROR_VERIFY;
            return E_NOT_OK;
        }
    }

    CDD_SBC_LastError = CDD_SBC_ERROR_NONE;
    return E_OK;
}

Std_ReturnType CDD_SBC_Init(void)
{
    CDD_SBC_DeviceStatusType status;
    return CDD_SBC_GetDeviceStatus(&status);
}

Std_ReturnType CDD_SBC_ReadRegister(uint8 address, uint8 *data)
{
    return CDD_SBC_Transfer(FALSE, address, 0U, data);
}

Std_ReturnType CDD_SBC_WriteRegister(uint8 address, uint8 data)
{
    return CDD_SBC_Transfer(TRUE, address, data, NULL_PTR);
}

Std_ReturnType CDD_SBC_GetDeviceStatus(CDD_SBC_DeviceStatusType *status)
{
    uint8 raw;

    if (status == NULL_PTR)
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
        return E_NOT_OK;
    }

    if (CDD_SBC_ReadRegister(CDD_SBC_REG_DEVSTAT, &raw) != E_OK)
    {
        return E_NOT_OK;
    }

    status->raw = raw;
    status->tracker2Enabled = ((raw & 0x80U) != 0U) ? TRUE : FALSE;
    status->tracker1Enabled = ((raw & 0x40U) != 0U) ? TRUE : FALSE;
    status->communicationLdoEnabled = ((raw & 0x20U) != 0U) ? TRUE : FALSE;
    status->standbyLdoEnabled = ((raw & 0x10U) != 0U) ? TRUE : FALSE;
    status->voltageReferenceEnabled = ((raw & 0x08U) != 0U) ? TRUE : FALSE;
    status->state = (CDD_SBC_StateType)(raw & CDD_SBC_DEVCTRL_STATE_MASK);

    return E_OK;
}

Std_ReturnType CDD_SBC_GetDiagnostics(CDD_SBC_DiagnosticType *diagnostic)
{
    if (diagnostic == NULL_PTR)
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
        return E_NOT_OK;
    }

    if ((CDD_SBC_ReadRegister(CDD_SBC_REG_SPISF, &diagnostic->spiStatus) != E_OK) ||
        (CDD_SBC_ReadRegister(CDD_SBC_REG_SYSFAIL, &diagnostic->systemFailure) != E_OK) ||
        (CDD_SBC_ReadRegister(CDD_SBC_REG_INITERR, &diagnostic->initError) != E_OK) ||
        (CDD_SBC_ReadRegister(CDD_SBC_REG_IF, &diagnostic->interruptFlags) != E_OK) ||
        (CDD_SBC_ReadRegister(CDD_SBC_REG_SYSSF, &diagnostic->systemStatus) != E_OK) ||
        (CDD_SBC_ReadRegister(CDD_SBC_REG_VMONSTAT, &diagnostic->voltageMonitorStatus) != E_OK) ||
        (CDD_SBC_ReadRegister(CDD_SBC_REG_WWDSTAT, &diagnostic->windowWatchdogStatus) != E_OK))
    {
        return E_NOT_OK;
    }

    return E_OK;
}

Std_ReturnType CDD_SBC_ModeChange(CDD_SBC_StateType requestedState)
{
    CDD_SBC_DeviceStatusType status;
    uint8 control;
    uint16 poll;

    if ((requestedState < CDD_SBC_STATE_INIT) ||
        (requestedState > CDD_SBC_STATE_WAKE))
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
        return E_NOT_OK;
    }

    if (CDD_SBC_GetDeviceStatus(&status) != E_OK)
    {
        return E_NOT_OK;
    }

    /* 先从实际 DEVSTAT 保留 LDO 位，避免模式切换意外关闭既有供电轨。 */
    control = status.raw & (CDD_SBC_DEVCTRL_TRACKER2_MASK |
                            CDD_SBC_DEVCTRL_TRACKER1_MASK |
                            CDD_SBC_DEVCTRL_COM_MASK |
                            CDD_SBC_DEVCTRL_VREF_MASK);
    control |= (uint8)requestedState;

    if ((CDD_SBC_WriteRegister(CDD_SBC_REG_DEVCTRL, control) != E_OK) ||
        (CDD_SBC_WriteRegister(CDD_SBC_REG_DEVCTRLN, (uint8)(~control)) != E_OK))
    {
        return E_NOT_OK;
    }

    /* DEVCTRL/DEVCTRLN 配对写入成功后，仍须以 DEVSTAT 为准确认状态。 */
    for (poll = 0U; poll < CDD_SBC_STATE_POLL_COUNT; poll++)
    {
        CDD_SBC_DELAY_US(CDD_SBC_STATE_POLL_DELAY_US);
        if ((CDD_SBC_GetDeviceStatus(&status) == E_OK) &&
            (status.state == requestedState))
        {
            return E_OK;
        }
    }

    CDD_SBC_LastError = CDD_SBC_ERROR_TIMEOUT;
    return E_NOT_OK;
}

Std_ReturnType CDD_SBC_VCC2_Ctrl(CDD_SBC_Vcc2StateType requestedState)
{
    CDD_SBC_DeviceStatusType status;
    uint8 control;

    if ((requestedState != CDD_SBC_VCC2_OFF) &&
        (requestedState != CDD_SBC_VCC2_ON))
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
        return E_NOT_OK;
    }

    if (CDD_SBC_GetDeviceStatus(&status) != E_OK)
    {
        return E_NOT_OK;
    }

    control = status.raw & (CDD_SBC_DEVCTRL_TRACKER2_MASK |
                            CDD_SBC_DEVCTRL_TRACKER1_MASK |
                            CDD_SBC_DEVCTRL_VREF_MASK |
                            CDD_SBC_DEVCTRL_STATE_MASK);
    /* COMEN 对应 QCO 通信 LDO；VCC2 仅为历史接口命名。 */
    if (requestedState == CDD_SBC_VCC2_ON)
    {
        control |= CDD_SBC_DEVCTRL_COM_MASK;
    }

    if ((CDD_SBC_WriteRegister(CDD_SBC_REG_DEVCTRL, control) != E_OK) ||
        (CDD_SBC_WriteRegister(CDD_SBC_REG_DEVCTRLN, (uint8)(~control)) != E_OK))
    {
        return E_NOT_OK;
    }

    return E_OK;
}

Std_ReturnType CDD_SBC_WD_Init(CDD_SBC_WatchdogType watchdogType,
                               CDD_SBC_WatchdogPeriodType period)
{
    uint8 halfPeriodSteps;

    if ((watchdogType != CDD_SBC_WD_DISABLED) &&
        (watchdogType != CDD_SBC_WD_TYPE_TIMEOUT))
    {
        CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
        return E_NOT_OK;
    }

    switch (period)
    {
        case CDD_SBC_WD_PERIOD_100MS:
            halfPeriodSteps = 1U;
            break;
        case CDD_SBC_WD_PERIOD_200MS:
            halfPeriodSteps = 2U;
            break;
        case CDD_SBC_WD_PERIOD_500MS:
            halfPeriodSteps = 5U;
            break;
        case CDD_SBC_WD_PERIOD_1000MS:
            halfPeriodSteps = 10U;
            break;
        default:
            CDD_SBC_LastError = CDD_SBC_ERROR_PARAMETER;
            return E_NOT_OK;
    }

    return CDD_SBC_ReconfigureWatchdog(
        (watchdogType == CDD_SBC_WD_TYPE_TIMEOUT) ? TRUE : FALSE,
        halfPeriodSteps);
}

Std_ReturnType CDD_SBC_WD_Service(void)
{
    uint8 triggerStatus;
    uint8 triggerValue;

    if (CDD_SBC_ReadRegister(CDD_SBC_REG_WWDSCMD, &triggerStatus) != E_OK)
    {
        return E_NOT_OK;
    }

    /* WWDSCMD 的触发位需交替翻转，重复同一值不构成有效喂狗。 */
    triggerValue = ((triggerStatus & 0x80U) != 0U) ? 0U : 1U;
    return CDD_SBC_WriteRegister(CDD_SBC_REG_WWDSCMD, triggerValue);
}

CDD_SBC_ErrorType CDD_SBC_GetLastError(void)
{
    return CDD_SBC_LastError;
}
