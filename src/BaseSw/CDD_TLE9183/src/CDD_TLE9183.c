#include "CDD_TLE9183.h"
#include "CDD_TLE9183_Cfg.h"
#include "Spi.h"

/*
 * TLE9183 SPI 实现。
 * 发送帧：C[23]、Address[22:16]、Data[15:8]、Reserved[7:3]、CRC3[2:0]。
 * 接收帧：Status[23:19]、Address[18:12]、Data[11:4]、R[3]、CRC3[2:0]。
 * 芯片的响应延迟一个帧周期，故任何有返回值的事务都以 NOP 结束。
 */
/* MOSI：C[23]、Address[22:16]、Data[15:8]、Reserved[7:3]、CRC3[2:0]。 */
#define CDD_TLE9183_ADDR_MASK       (0x7FU)
#define CDD_TLE9183_DATA_MASK       (0xFFU)
#define CDD_TLE9183_CRC_MASK        (0x07U)
#define CDD_TLE9183_CRC_INIT        (0x04U)
#define CDD_TLE9183_REG_MAX         (0x67U)

static CDD_TLE9183_ErrorType CDD_TLE9183_LastError = CDD_TLE9183_ERROR_NONE;

static uint8 CDD_TLE9183_Crc3(uint32 value)
{
    uint8 crc = CDD_TLE9183_CRC_INIT;
    uint8 bit;
    uint8 input;
    uint8 feedback;

    /*
     * CRC 覆盖 bit23..bit3；多项式为 x^3 + x + 1，初值为 0b100。
     * value 的低 3 位在调用方保持为 0，因此本函数可同时用于发送和校验。
     */
    for (bit = 0U; bit < 21U; bit++)
    {
        input = (uint8)((value >> (23U - bit)) & 1U);
        feedback = (uint8)(((crc >> 2U) & 1U) ^ input);
        crc = (uint8)((crc << 1U) & CDD_TLE9183_CRC_MASK);
        if (feedback != 0U)
        {
            crc ^= 0x03U;
        }
    }
    return crc;
}

static uint32 CDD_TLE9183_BuildFrame(boolean writeAccess, uint8 address, uint8 data)
{
    uint32 frame = ((uint32)(writeAccess ? 1U : 0U) << 23U) |
                   ((uint32)(address & CDD_TLE9183_ADDR_MASK) << 16U) |
                   ((uint32)data << 8U);
    /* Reserved[7:3] 由零初始化保留；CRC 最后填入 bit[2:0]。 */
    frame |= (uint32)CDD_TLE9183_Crc3(frame);
    return frame;
}

static Std_ReturnType CDD_TLE9183_Transfer(uint32 transmitFrame,
                                           uint32 *receiveFrame)
{
    Std_ReturnType result;
    /*
     * MCAL 通道的一个数据元素即完整的 24 bit SPI 帧。局部变量地址在
     * Spi_SyncTransmit() 返回前有效，符合同步 EB 缓冲区的使用要求。
     */
    result = Spi_SetupEB(CDD_TLE9183_SPI_CHANNEL,
                         (const Spi_DataBufferType *)&transmitFrame,
                         (Spi_DataBufferType *)receiveFrame,
                         (Spi_NumberOfDataType)1U);
    if (result != E_OK)
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_SPI_SETUP;
        return E_NOT_OK;
    }
    result = Spi_SyncTransmit(CDD_TLE9183_SPI_SEQUENCE);
    if (result != E_OK)
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_SPI_TRANSFER;
        return E_NOT_OK;
    }
    return E_OK;
}

static boolean CDD_TLE9183_CheckCrc(uint32 frame)
{
    /* 将接收帧的 CRC 位清零后重算，与原帧低 3 位比较。 */
    return (CDD_TLE9183_Crc3(frame & 0xFFFFF8UL) ==
            (uint8)(frame & CDD_TLE9183_CRC_MASK)) ? TRUE : FALSE;
}

static Std_ReturnType CDD_TLE9183_Decode(uint32 frame,
                                         CDD_TLE9183_ResponseType *response)
{
    if (CDD_TLE9183_CheckCrc(frame) == FALSE)
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_CRC;
        return E_NOT_OK;
    }
    /* MISO：status[23:19]、address[18:12]、data[11:4]、R[3]、CRC3[2:0]。 */
    /* R[3] 仅表示响应类别；当前接口通过地址和数据回显完成事务关联。 */
    response->status = (uint8)((frame >> 19U) & 0x1FU);
    response->address = (uint8)((frame >> 12U) & CDD_TLE9183_ADDR_MASK);
    response->data = (uint8)((frame >> 4U) & CDD_TLE9183_DATA_MASK);
    return E_OK;
}

Std_ReturnType CDD_TLE9183_ReadRegister(uint8 address, uint8 *data,
                                        uint8 *status)
{
    uint32 request;
    uint32 responseFrame = 0U;
    CDD_TLE9183_ResponseType response;

    if ((address > CDD_TLE9183_REG_MAX) || (data == NULL_PTR))
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_PARAMETER;
        return E_NOT_OK;
    }
    /* 第一帧仅提交读请求，其 MISO 内容属于前一条命令，故不可直接使用。 */
    request = CDD_TLE9183_BuildFrame(FALSE, address, 0U);
    if (CDD_TLE9183_Transfer(request, &responseFrame) != E_OK)
    {
        return E_NOT_OK;
    }
    /* 芯片延迟一帧返回读结果，因此第二帧必须发送 NOP。 */
    if (CDD_TLE9183_Transfer(CDD_TLE9183_BuildFrame(FALSE, CDD_TLE9183_REG_NOP, 0U),
                             &responseFrame) != E_OK)
    {
        return E_NOT_OK;
    }
    if (CDD_TLE9183_Decode(responseFrame, &response) != E_OK)
    {
        return E_NOT_OK;
    }
    /* 地址回显不一致说明响应错位、片选/时序异常或总线被其他主机干扰。 */
    if (response.address != address)
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_RESPONSE;
        return E_NOT_OK;
    }
    *data = response.data;
    if (status != NULL_PTR)
    {
        *status = response.status;
    }
    CDD_TLE9183_LastError = CDD_TLE9183_ERROR_NONE;
    return E_OK;
}

Std_ReturnType CDD_TLE9183_WriteRegister(uint8 address, uint8 data,
                                         uint8 *status)
{
    uint32 responseFrame = 0U;
    CDD_TLE9183_ResponseType response;

    if (address > CDD_TLE9183_REG_MAX)
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_PARAMETER;
        return E_NOT_OK;
    }
    /* 写入确认同样在紧随其后的 NOP 响应中返回。 */
    if (CDD_TLE9183_Transfer(CDD_TLE9183_BuildFrame(TRUE, address, data),
                             &responseFrame) != E_OK)
    {
        return E_NOT_OK;
    }
    if (CDD_TLE9183_Transfer(CDD_TLE9183_BuildFrame(FALSE, CDD_TLE9183_REG_NOP, 0U),
                             &responseFrame) != E_OK)
    {
        return E_NOT_OK;
    }
    if (CDD_TLE9183_Decode(responseFrame, &response) != E_OK)
    {
        return E_NOT_OK;
    }
    /* 写入响应应回显地址和数据；任一不一致均不得认为寄存器已写成功。 */
    if ((response.address != address) || (response.data != data))
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_RESPONSE;
        return E_NOT_OK;
    }
    if (status != NULL_PTR)
    {
        *status = response.status;
    }
    CDD_TLE9183_LastError = CDD_TLE9183_ERROR_NONE;
    return E_OK;
}

Std_ReturnType CDD_TLE9183_ReadDiagnostics(CDD_TLE9183_ResponseType *diagnostic)
{
    if (diagnostic == NULL_PTR)
    {
        CDD_TLE9183_LastError = CDD_TLE9183_ERROR_PARAMETER;
        return E_NOT_OK;
    }
    /* ERR_OVER 是上电通信自检的最小诊断读取，不会改变任何芯片状态。 */
    if (CDD_TLE9183_ReadRegister(CDD_TLE9183_REG_ERR_OVER,
                                 &diagnostic->data, &diagnostic->status) != E_OK)
    {
        return E_NOT_OK;
    }
    diagnostic->address = CDD_TLE9183_REG_ERR_OVER;
    return E_OK;
}

Std_ReturnType CDD_TLE9183_Init(void)
{
    CDD_TLE9183_ResponseType diagnostic;
    return CDD_TLE9183_ReadDiagnostics(&diagnostic);
}

CDD_TLE9183_ErrorType CDD_TLE9183_GetLastError(void)
{
    return CDD_TLE9183_LastError;
}
