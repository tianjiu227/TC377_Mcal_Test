#ifndef CDD_TLE9183_H
#define CDD_TLE9183_H

/*
 * TLE9183QK 三相栅极驱动器 CDD 对外接口。
 *
 * 读取与写入接口都会自动发送 NOP，获取芯片延迟一帧返回的响应。当前版本
 * 仅支持通信、诊断和配置读写，不在 Init() 中写入 0x00..0x1F，防止在电机
 * 与功率级参数未定版时使能不合适的保护或驱动设置。
 */
#include "Std_Types.h"

typedef enum
{
    CDD_TLE9183_ERROR_NONE = 0U,
    CDD_TLE9183_ERROR_PARAMETER,
    CDD_TLE9183_ERROR_SPI_SETUP,
    CDD_TLE9183_ERROR_SPI_TRANSFER,
    CDD_TLE9183_ERROR_CRC,
    CDD_TLE9183_ERROR_RESPONSE,
    CDD_TLE9183_ERROR_STATUS
} CDD_TLE9183_ErrorType;

typedef struct
{
    /* MISO 帧中的状态[23:19]、地址[18:12]和数据[11:4]。 */
    uint8 status;
    uint8 address;
    uint8 data;
} CDD_TLE9183_ResponseType;

/*
 * 配置签名必须在其余配置寄存器全部写完后最后写入。
 * 配置时间窗口内签名不匹配会导致 configuration invalid/timeout 故障。
 */
#define CDD_TLE9183_REG_CONF_SIG       (0x00U)
#define CDD_TLE9183_REG_CONF_GEN_1     (0x01U)
#define CDD_TLE9183_REG_CONF_GEN_2     (0x02U)
#define CDD_TLE9183_REG_CONF_GEN_3     (0x03U)
#define CDD_TLE9183_REG_CONF_WWD       (0x04U)
/* NOP 用于取回前一条 SPI 命令的延迟响应。 */
#define CDD_TLE9183_REG_NOP            (0x32U)
#define CDD_TLE9183_REG_OM_OVER        (0x40U)
#define CDD_TLE9183_REG_ERR_OVER       (0x41U)
#define CDD_TLE9183_REG_SER            (0x42U)
#define CDD_TLE9183_REG_ERR_SPICONF    (0x4AU)

/*
 * 初始化通信检查：读取 ERR_OVER（0x41）。
 * 返回 E_OK 不等于功率桥已使能，也不表示所有诊断位均为无故障。
 */
Std_ReturnType CDD_TLE9183_Init(void);
/*
 * 单寄存器读取：内部依次发送读请求和 NOP，并校验响应 CRC3/地址。
 * status 可传 NULL_PTR；data 必须非空，address 范围为 0x00..0x67。
 */
Std_ReturnType CDD_TLE9183_ReadRegister(uint8 address, uint8 *data,
                                        uint8 *status);
/*
 * 单寄存器写入：内部发送写请求和 NOP，并核对响应地址/数据。
 * 写配置区前须由上层保证时序、配置顺序和功率级参数均已完成审查。
 */
Std_ReturnType CDD_TLE9183_WriteRegister(uint8 address, uint8 data,
                                         uint8 *status);
/* 读取 ERR_OVER 原始字节及其响应状态，位级故障解释由上层诊断模块完成。 */
Std_ReturnType CDD_TLE9183_ReadDiagnostics(CDD_TLE9183_ResponseType *diagnostic);
/* 返回最近一次本模块检测到的通信、CRC、响应或状态错误。 */
CDD_TLE9183_ErrorType CDD_TLE9183_GetLastError(void);

#endif
