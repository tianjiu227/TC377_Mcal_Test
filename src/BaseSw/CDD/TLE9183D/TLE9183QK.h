/**
 * @file    TLE9183QK.h
 * @brief   TLE9183QK 桥驱动器 IC 头文件。
 * @details 本文件包含 TLE9183QK 三相桥驱动器的公共接口、类型定义和函数原型。
 *          该驱动提供基于 SPI 的配置和诊断功能。
 * @note    寄存器地址和位定义基于 TLE9183QK 数据手册和用户手册。
 */

#ifndef TLE9183QK_H_
#define TLE9183QK_H_

#include "Std_Types.h"

/**
 * @brief   TLE9183QK 的操作模式。
 * @details 对应操作模式总览寄存器（0x40）。
 */
typedef enum Oper_Mode
{
    No_mode         = 0x00, /**< 无模式 / 默认值 */
    idle_mode       = 0x01, /**< 空闲模式 */
    conf_mode       = 0x02, /**< 配置模式激活 */
    conf_lock_mode  = 0x04, /**< 配置锁定模式激活 */
    self_test_mode  = 0x08, /**< 自检模式 */
    soff_mode       = 0x10, /**< 安全关断模式 */
    err_mode        = 0x20, /**< 错误模式 */
    rect_mode       = 0x40, /**< 正常操作模式（整流） */
    norm_mode       = 0x80  /**< 正常操作模式（电机驱动） */
} Operation_ModeType;

/**
 * @brief   初始化 TLE9183QK 设备。
 * @details 配置设备、写入配置签名，并尝试使设备进入正常操作模式。
 *          全局变量 Normal_Mode_OK 指示结果。
 */
extern void TLE9183QK_init(void);

/**
 * @brief   通过 SPI 从 TLE9183QK 读取寄存器。
 * @param[in]  reg_address  寄存器地址（7 位，不含读写位）。
 * @param[out] reg_data     指向存储读取数据的指针。
 * @return  读取操作的状态。
 * @retval  0     读取成功。
 * @retval  0xFF  CRC 错误。
 * @retval  0xFE  地址不匹配错误。
 */
extern uint8 TLE9183QK_ReadFunction(uint8 reg_address, uint8* reg_data);

/**
 * @brief   通过 SPI 向 TLE9183QK 写入寄存器。
 * @param[in] reg_address  寄存器地址（7 位，不含读写位）。
 * @param[in] reg_data     要写入的数据。
 */
extern void TLE9183QK_WriteFunction(uint8 reg_address, uint8 reg_data);

/**
 * @brief   计算 SPI 帧的 CRC3。
 * @param[in] dataframe  24 位 SPI 帧（CRC 位已清零）。
 * @return  计算得到的 3 位 CRC。
 */
extern uint32 CRC3_Calculation(uint32 dataframe);

/**
 * @brief   读取 No Operation 寄存器（0x32）以检查 SPI 通信。
 * @return  如果 SPI 通信成功返回 0，否则返回错误码。
 */
extern uint8 TLE9183QK_Read_No_Operation_0x32(void);

/**
 * @brief   读取操作模式总览寄存器（0x40）。
 * @return  当前操作模式，类型为 Operation_ModeType。
 */
extern Operation_ModeType TLE9183QK_Read_Operation_Mode_0x40(void);

/**
 * @brief   读取错误总览寄存器（0x41）。
 * @return  0 = 无错误，1 = SPI 错误，2 = 存在错误。
 */
extern uint8 TLE9183QK_Read_Err_over_0x41(void);

/**
 * @brief   读取特殊事件寄存器（0x42）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Special_Event_0x42(void);

/**
 * @brief   读取内部错误 1 寄存器（0x43）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Internal_Errors1_0x43(void);

/**
 * @brief   读取内部错误 2 寄存器（0x44）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Internal_Errors2_0x44(void);

/**
 * @brief   读取外部错误寄存器（0x45）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_External_Errors_0x45(void);

/**
 * @brief   读取关断错误寄存器（0x46）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Shutdown_Errors_0x46(void);

/**
 * @brief   读取短路错误寄存器（0x47）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Short_Circuit_Errors_0x47(void);

/**
 * @brief   读取输入模式违规寄存器（0x48）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Input_Pattern_Violations_0x48(void);

/**
 * @brief   读取输出级反馈错误寄存器（0x49）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Output_Stage_Feedback_Errors_0x49(void);

/**
 * @brief   读取 SPI 通信和配置错误寄存器（0x4A）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_SPI_Communication_Configuration_Errors_0x4A(void);

/**
 * @brief   读取电流采样放大器 1 和 2 错误寄存器（0x4B）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Current_Sense_Amplifiers_1_2_Errors_0x4B(void);

/**
 * @brief   读取电流采样放大器 3 错误寄存器（0x4C）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Current_Sense_Amplifiers_3_Errors_0x4C(void);

/**
 * @brief   读取数字输出引脚错误寄存器（0x4D）。
 * @return  寄存器值。
 */
extern uint8 TLE9183QK_Read_Digital_Output_Pin_Errors_0x4D(void);

/**
 * @brief   将 ENA 引脚置为高电平。
 */
extern void TLE9183QK_ENA_HIGH(void);

/**
 * @brief   将 ENA 引脚置为低电平。
 */
extern void TLE9183QK_ENA_LOW(void);

/**
 * @brief   将 SOFF_N 引脚置为高电平。
 */
extern void TLE9183QK_SOFF_N_HIGH(void);

/**
 * @brief   将 SOFF_N 引脚置为低电平。
 */
extern void TLE9183QK_SOFF_N_LOW(void);

/**
 * @brief   将 INH_N 引脚置为高电平。
 */
extern void TLE9183QK_INH_N_HIGH(void);

/**
 * @brief   将 INH_N 引脚置为低电平。
 */
extern void TLE9183QK_INH_N_LOW(void);

/* ==================== 示例集成函数声明 ==================== */
/**
 * @brief   示例 ECU 初始化函数。
 * @details 初始化 SPI 底层驱动和 TLE9183QK 设备。
 *          检查全局 Normal_Mode_OK 标志以确认成功。
 * @note    该函数为示例集成代码，实际项目中建议放在应用层。
 */
extern void Ecu_Init(void);

/**
 * @brief   TLE9183QK 示例诊断任务。
 * @details 周期性读取错误总览寄存器并处理错误。
 * @note    该函数为示例集成代码，实际项目中建议放在任务调度层。
 */
extern void TLE9183QK_Diag_Task(void);

/**
 * @brief   执行 TLE9183QK 简要测试。
 * @details 依次检查 SPI 通信、读取操作模式、读取错误总览寄存器。
 *          主要用于快速验证设备是否正常工作，无需完整初始化流程。
 * @return  测试结果。
 * @retval  0  测试通过（SPI 正常，无错误，且处于正常或空闲模式）。
 * @retval  1  SPI 通信失败。
 * @retval  2  操作模式异常（非正常模式且非空闲模式）。
 * @retval  3  存在错误标志（错误总览寄存器非零）。
 */
extern uint8 TLE9183QK_BriefTest(void);

#endif /* TLE9183QK_H_ */