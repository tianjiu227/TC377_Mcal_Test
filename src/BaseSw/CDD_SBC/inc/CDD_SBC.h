#ifndef CDD_SBC_H
#define CDD_SBC_H

/*
 * TLF35584 系统基础芯片（SBC）CDD 对外接口。
 *
 * 所有寄存器读写均经 QSPI2 完成。调用者必须先完成 Spi_Init()；本模块
 * 不负责初始化 MCAL SPI，也不在 Init() 中改变电源轨、工作模式或看门狗。
 */
#include "Std_Types.h"

#define CDD_SBC_VENDOR_ID               (17U)
#define CDD_SBC_MODULE_ID               (255U)

#define CDD_SBC_SW_MAJOR_VERSION        (1U)
#define CDD_SBC_SW_MINOR_VERSION        (0U)
#define CDD_SBC_SW_PATCH_VERSION        (0U)

typedef enum
{
    CDD_SBC_STATE_NONE = 0U,
    CDD_SBC_STATE_INIT = 1U,
    CDD_SBC_STATE_NORMAL = 2U,
    CDD_SBC_STATE_SLEEP = 3U,
    CDD_SBC_STATE_STANDBY = 4U,
    CDD_SBC_STATE_WAKE = 5U
} CDD_SBC_StateType;

/*
 * 历史接口名保留以兼容现有调用；实际控制的是 TLF35584 的
 * DEVCTRL.COMEN 位，即 QCO 通信 LDO。当前原理图未证明存在 VCC2 网。
 */
typedef enum
{
    CDD_SBC_VCC2_OFF = 0U,
    CDD_SBC_VCC2_ON = 1U
} CDD_SBC_Vcc2StateType;

typedef enum
{
    CDD_SBC_WD_DISABLED = 0U,
    CDD_SBC_WD_TYPE_TIMEOUT = 1U
} CDD_SBC_WatchdogType;

typedef enum
{
    CDD_SBC_WD_PERIOD_100MS = 0U,
    CDD_SBC_WD_PERIOD_200MS,
    CDD_SBC_WD_PERIOD_500MS,
    CDD_SBC_WD_PERIOD_1000MS
} CDD_SBC_WatchdogPeriodType;

typedef enum
{
    CDD_SBC_ERROR_NONE = 0U,
    CDD_SBC_ERROR_PARAMETER,
    CDD_SBC_ERROR_SPI_SETUP,
    CDD_SBC_ERROR_SPI_TRANSFER,
    CDD_SBC_ERROR_SPI_PARITY,
    CDD_SBC_ERROR_SPI_RESPONSE,
    CDD_SBC_ERROR_PROTECTION,
    CDD_SBC_ERROR_VERIFY,
    CDD_SBC_ERROR_TIMEOUT
} CDD_SBC_ErrorType;

typedef struct
{
    /* DEVSTAT 原始值，保留用于故障定位和追溯。 */
    uint8 raw;
    /* 下列布尔量由 DEVSTAT 位解码得到，不表示软件请求值。 */
    boolean tracker2Enabled;
    boolean tracker1Enabled;
    boolean communicationLdoEnabled;
    boolean standbyLdoEnabled;
    boolean voltageReferenceEnabled;
    CDD_SBC_StateType state;
} CDD_SBC_DeviceStatusType;

typedef struct
{
    /* 各成员是芯片诊断寄存器的原始值，位定义请按 TLF35584 数据手册解码。 */
    uint8 spiStatus;
    uint8 systemFailure;
    uint8 initError;
    uint8 interruptFlags;
    uint8 systemStatus;
    uint8 voltageMonitorStatus;
    uint8 windowWatchdogStatus;
} CDD_SBC_DiagnosticType;

/*
 * 初始化通信检查：仅读取 DEVSTAT。
 * 返回 E_OK 仅说明当前 SPI 读事务及响应校验成功，不等于 SBC 已处于 NORMAL。
 */
Std_ReturnType CDD_SBC_Init(void);
/* 原始寄存器接口。address 必须在 0x00..0x3F，data 不能为 NULL_PTR。 */
Std_ReturnType CDD_SBC_ReadRegister(uint8 address, uint8 *data);
/* 原始写接口。写事务的回读帧必须与发送帧完全一致，否则返回 E_NOT_OK。 */
Std_ReturnType CDD_SBC_WriteRegister(uint8 address, uint8 data);
/* 读取并解码 DEVSTAT，适合用于上电流程和状态切换后的确认。 */
Std_ReturnType CDD_SBC_GetDeviceStatus(CDD_SBC_DeviceStatusType *status);
/* 连续读取 SPI/SYS/VMON/WWD 诊断寄存器；任一读失败即整体失败。 */
Std_ReturnType CDD_SBC_GetDiagnostics(CDD_SBC_DiagnosticType *diagnostic);
/*
 * 状态切换按 DEVCTRL/DEVCTRLN 互补写入，并轮询 DEVSTAT。
 * 该接口保留当前 LDO 使能状态，只更新状态请求字段。
 */
Std_ReturnType CDD_SBC_ModeChange(CDD_SBC_StateType requestedState);
/* 兼容接口：实际使能/关闭 QCO（DEVCTRL.COMEN），不是已验证的 VCC2 网。 */
Std_ReturnType CDD_SBC_VCC2_Ctrl(CDD_SBC_Vcc2StateType requestedState);
/*
 * 超时看门狗配置。函数会解锁、读回、完整重写和重新锁定 0x04..0x0A。
 * 不应在中断上下文调用；配置期间不得有其他任务访问受保护寄存器。
 */
Std_ReturnType CDD_SBC_WD_Init(CDD_SBC_WatchdogType watchdogType,
                               CDD_SBC_WatchdogPeriodType period);
Std_ReturnType CDD_SBC_WD_Service(void);
/* 返回最近一次本模块检测到的错误原因；成功事务会清除该错误码。 */
CDD_SBC_ErrorType CDD_SBC_GetLastError(void);

/* Compatibility names used by the disabled sample in Cpu0_Main.c. */
#define Normal_Mode        CDD_SBC_STATE_NORMAL
#define VCC2_OFF           CDD_SBC_VCC2_OFF
#define VCC2_ON            CDD_SBC_VCC2_ON
#define WD_TYPE_TIMEOUT    CDD_SBC_WD_TYPE_TIMEOUT
#define WD_PERIOD_100MS    CDD_SBC_WD_PERIOD_100MS
#define WD_PERIOD_200MS    CDD_SBC_WD_PERIOD_200MS
#define WD_PERIOD_500MS    CDD_SBC_WD_PERIOD_500MS
#define WD_PERIOD_1000MS   CDD_SBC_WD_PERIOD_1000MS

#endif /* CDD_SBC_H */
