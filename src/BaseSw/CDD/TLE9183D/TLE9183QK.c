/**
 * @file    TLE9183QK.c
 * @brief   TLE9183QK 桥驱动器 IC 驱动实现。
 * @details 本文件提供 TLE9183QK 三相桥驱动器的配置、SPI 通信和诊断功能。
 *          驱动基于 TLE9183QK 数据手册和用户手册。
 * @note    SPI 帧格式：24 位，MSB 优先。
 *          CRC3 多项式：x^3 + x^1 + 1，种子 101。
 *          配置签名：CRC8 多项式 x^8 + x^6 + x^3 + x^2 + 1。
 */

#include "TLE9183QK.h"
#include "TLE9183D_HW.h"
#include "Dio.h"
#include "Dio_Cfg.h"

/* ==================== 寄存器地址宏 ==================== */
#define Conf_Sig_ADD        0x00    /**< 配置签名 */
#define Conf_Gen_1_ADD      0x01    /**< 通用配置 1 */
#define Conf_Gen_2_ADD      0x02    /**< 通用配置 2 */
#define Conf_Gen_3_ADD      0x03    /**< 通用配置 3 */
#define Conf_wwd_ADD        0x04    /**< 窗口看门狗 */
#define TL_vs_ADD           0x05    /**< Vs 过压和欠压阈值 */
#define TL_vdh_ADD          0x06    /**< VDHP 过压和欠压阈值 */
#define TL_cbvc_ADD         0x07    /**< CB 欠压和 VCC 欠压/过压阈值 */
#define Fm_1_ADD            0x08    /**< 电荷泵 / 高侧缓冲故障模式 */
#define Fm_2_ADD            0x09    /**< 杂项故障模式 */
#define Fm_3_ADD            0x0A    /**< Vs & VDHP & VCC 欠压故障模式 */
#define Fm_4_ADD            0x0B    /**< Vs & VDHP & VCC 过压故障模式 */
#define Fm_5_ADD            0x0C    /**< 短路检测 & 信号路径监督故障模式 */
#define Dt_hs_ADD           0x0D    /**< 高侧死区时间 */
#define Dt_ls_ADD           0x0E    /**< 低侧死区时间 */
#define Ft_1_ADD            0x0F    /**< 欠压滤波时间 */
#define Ft_2_ADD            0x10    /**< 过压和 VCC 滤波时间 */
#define Ft_3_ADD            0x11    /**< 过温 & 短路检测滤波时间 */
#define Ft_4_ADD            0x12    /**< 过流滤波时间 */
#define Fm_6_ADD            0x13    /**< 过流故障模式 */

#define Op_gain_1_ADD       0x20    /**< 电流采样放大器 1&2 - 增益 1 */
#define Op_gain_2_ADD       0x21    /**< 电流采样放大器 1&2 - 增益 2 */
#define Op_gain_3_ADD       0x22    /**< 电流采样放大器 3 - 增益 1&2 */
#define Op_ocl_ADD          0x23    /**< 电流采样放大器零电流偏移 */
#define Op_con_ADD          0x24    /**< 电流采样放大器配置 */
#define Sc_ls_1_ADD         0x25    /**< 短路检测阈值 低侧 1 */
#define Sc_ls_2_ADD         0x26    /**< 短路检测阈值 低侧 2 */
#define Sc_ls_3_ADD         0x27    /**< 短路检测阈值 低侧 3 */
#define Sc_hs_1_ADD         0x28    /**< 短路检测阈值 高侧 1 */
#define Sc_hs_2_ADD         0x29    /**< 短路检测阈值 高侧 2 */
#define Sc_hs_3_ADD         0x2A    /**< 短路检测阈值 高侧 3 */
#define Li_ctr_ADD          0x2B    /**< Limp Home 激活和半桥禁用 */
#define Misc_ctr_ADD        0x2C    /**< 相位电压反馈和 CSA 增益移位 */
#define art_tlp_ADD         0x2D    /**< 被动整流阈值 */
#define art_tla_ADD         0x2E    /**< 主动整流阈值 */
#define art_fi_ADD          0x2F    /**< 整流滤波时间 */
#define art_acc_ADD         0x30    /**< 整流精度 */
#define art_entry_ADD       0x31    /**< 整流模式进入 */
#define nop_ADD             0x32    /**< 无操作 */
#define Drev_mark_ADD       0x33    /**< 反向二极管测量 */
#define Ds_mark_ADD         0x34    /**< 漏源电压测量 */
#define Sel_st_1_ADD        0x35    /**< 自检选择 1 */
#define Sel_st_2_ADD        0x36    /**< 自检选择 2 */
#define En_st_ADD           0x37    /**< 自检模式进入 */

#define Om_over_ADD         0x40    /**< 操作模式总览 */
#define Err_over_ADD        0x41    /**< 错误总览 */
#define Ser_ADD             0x42    /**< 特殊事件寄存器 */
#define Err_i_1_ADD         0x43    /**< 内部错误 1 */
#define Err_i_2_ADD         0x44    /**< 内部错误 2 */
#define Err_e_ADD           0x45    /**< 外部错误 */
#define Err_sd_ADD          0x46    /**< 关断错误 */
#define Err_scd_ADD         0x47    /**< 短路错误 */
#define Err_indiag_ADD      0x48    /**< 输入模式违规 */
#define Err_osf_ADD         0x49    /**< 输出级反馈错误 */
#define Err_spiconf_ADD     0x4A    /**< SPI 通信和配置错误 */
#define Err_op_12_ADD       0x4B    /**< 电流采样放大器 1 & 2 错误 */
#define Err_op_3_ADD        0x4C    /**< 电流采样放大器 3 错误 */
#define Err_outp_ADD        0x4D    /**< 数字输出引脚错误 */

/* ==================== 配置数组 ==================== */
/**
 * @brief   地址 0x01 到 0x13 的配置寄存器值。
 * @details 这些值在初始化期间写入。它们基于数据手册的复位值，
 *          并根据应用需求进行了调整（例如在 Conf_Gen_2 中使能 CSA3）。
 */
static volatile uint8 cfg_reg_data[19] = {
    0x80,   /**< 0x01 Conf_Gen_1 */
    0x07,   /**< 0x02 Conf_Gen_2：使能 CSA3 */
    0x1C,   /**< 0x03 Conf_Gen_3 */
    0x56,   /**< 0x04 Conf_wwd */
    0x07,   /**< 0x05 TL_vs */
    0xA0,   /**< 0x06 TL_vdh */
    0x95,   /**< 0x07 TL_cbvc */
    0x30,   /**< 0x08 Fm_1 */
    0x70,   /**< 0x09 Fm_2 */
    0x10,   /**< 0x0A Fm_3 */
    0x20,   /**< 0x0B Fm_4 */
    0x60,   /**< 0x0C Fm_5 */
    0x35,   /**< 0x0D Dt_hs：约 2µs 死区 */
    0x35,   /**< 0x0E Dt_ls */
    0x85,   /**< 0x0F Ft_1 */
    0x50,   /**< 0x10 Ft_2 */
    0x0E,   /**< 0x11 Ft_3 */
    0x02,   /**< 0x12 Ft_4 */
    0x00    /**< 0x13 Fm_6 */
};

/* ==================== 函数原型 ==================== */
static uint8 TLE9183QK_initCfg(void);
static uint8 CRC8_Calculation(void);
static void TLE9183QK_Write_Configuration(void);

/* ==================== 全局变量 ==================== */
/**
 * @brief   指示 TLE9183QK 是否成功进入正常模式。
 * @details 0 = 未初始化或失败，1 = 进入正常模式，2 = 其他模式，
 *          8 = SPI 通信失败，等等。详见 TLE9183QK_initCfg()。
 */
uint8 Normal_Mode_OK = 0;

/* ==================== 硬件抽象 ==================== */
#define TLE9183QK_HW_SPISYNCTRANSMIT    TLE9183D_HW_SPISYNCTRANSMIT
#define TLE9183QK_HW_SPI_TRANSFER_LENGTH TLE9183D_HW_SPI_TRANSFER_LENGTH

/* ==================== 引脚控制 ==================== */
/**
 * @brief   将 ENA 引脚置为高电平。
 */
void TLE9183QK_ENA_HIGH(void)  { Dio_WriteChannel(DioConf_DioChannel_DioChannel_GD_ENA1_P00_0, STD_HIGH); }

/**
 * @brief   将 ENA 引脚置为低电平。
 */
void TLE9183QK_ENA_LOW(void)   { Dio_WriteChannel(DioConf_DioChannel_DioChannel_GD_ENA1_P00_0, STD_LOW); }

/**
 * @brief   将 SOFF_N 引脚置为高电平。
 */
void TLE9183QK_SOFF_N_HIGH(void){ Dio_WriteChannel(DioConf_DioChannel_DioChannel_P33_9, STD_HIGH); }

/**
 * @brief   将 SOFF_N 引脚置为低电平。
 */
void TLE9183QK_SOFF_N_LOW(void) { Dio_WriteChannel(DioConf_DioChannel_DioChannel_P33_9, STD_LOW); }

/**
 * @brief   将 INH_N 引脚置为高电平。
 */
void TLE9183QK_INH_N_HIGH(void){ Dio_WriteChannel(DioConf_DioChannel_DioChannel_P33_11, STD_HIGH); }

/**
 * @brief   将 INH_N 引脚置为低电平。
 */
void TLE9183QK_INH_N_LOW(void) { Dio_WriteChannel(DioConf_DioChannel_DioChannel_P33_11, STD_LOW); }

/* ==================== 初始化 ==================== */
/**
 * @brief   初始化 TLE9183QK 设备。
 * @details 使设备进入空闲模式，等待电源稳定，然后尝试配置。
 *          如果配置失败，执行完整复位序列并重试配置，最多 2 次。
 *          最后使能输出级。
 * @note    结果存储在全局变量 Normal_Mode_OK 中。
 */
void TLE9183QK_init(void)
{
    uint8 retry = 0;
    Normal_Mode_OK = 0;

    /* 确保 INH 高、SOFF 高、ENA 低 -> 进入空闲模式并准备配置 */
    TLE9183QK_INH_N_HIGH();
    TLE9183QK_SOFF_N_HIGH();
    TLE9183QK_ENA_LOW();

    /* 等待电源稳定（至少 5ms，根据 CPU 频率调整循环次数） */
    for (volatile uint32 d = 0; d < 500000; d++);

    Normal_Mode_OK = TLE9183QK_initCfg();

    while ((Normal_Mode_OK != 1) && (retry < 2))
    {
        /* 重试前完整复位：拉低 INH 至少 5ms，再拉高 */
        TLE9183QK_INH_N_LOW();
        for (volatile uint32 d = 0; d < 500000; d++);
        TLE9183QK_INH_N_HIGH();
        TLE9183QK_SOFF_N_HIGH();
        TLE9183QK_ENA_LOW();
        for (volatile uint32 d = 0; d < 500000; d++);

        Normal_Mode_OK = TLE9183QK_initCfg();
        retry++;
    }

    /* 最后使能输出级 */
    TLE9183QK_SOFF_N_HIGH();
    TLE9183QK_ENA_HIGH();
}

/**
 * @brief   执行 TLE9183QK 的配置序列。
 * @details 检查 SPI 通信，读取错误总览，写入配置寄存器和配置签名，
 *          写入控制寄存器，最后验证是否进入正常模式。
 * @return  配置结果。
 * @retval  1  进入正常模式。
 * @retval  2  未进入正常模式。
 * @retval  8  SPI 通信失败。
 */
static uint8 TLE9183QK_initCfg(void)
{
    uint8 rtn = 0;

    /* 1. 检查 SPI 通信：读取 NOP 寄存器 0x32 */
    if (TLE9183QK_Read_No_Operation_0x32() != 0)
    {
        return 8;   /* SPI 通信失败 */
    }

    /* 2. 可选：读取错误总览，确保没有不可接受的错误 */
    if (TLE9183QK_Read_Err_over_0x41() == 2)
    {
        /* 存在错误；可在此读取具体错误寄存器。
           目前仅继续，由上层决定是否重试。 */
        // return 3;
    }

    /* 3. 写入配置寄存器和配置签名 */
    TLE9183QK_Write_Configuration();

    /* 4. 写入控制寄存器（增益、偏移等） */
    TLE9183QK_WriteFunction(Op_gain_1_ADD, 0x66);   /* CSA1&2 增益 38.13 */
    TLE9183QK_WriteFunction(Op_gain_2_ADD, 0x66);
    TLE9183QK_WriteFunction(Op_gain_3_ADD, 0x66);
    TLE9183QK_WriteFunction(Op_ocl_ADD,   0x9F);    /* 零电流偏移 2.5V */
    TLE9183QK_WriteFunction(Op_con_ADD,   0x07);    /* 不校准 */

    /* 5. 读取操作模式以确认正常模式 */
    if (TLE9183QK_Read_Operation_Mode_0x40() == norm_mode)
    {
        rtn = 1;
    }
    else
    {
        rtn = 2;
    }

    return rtn;
}

/* ==================== 写配置 + 签名 ==================== */
/**
 * @brief   写入所有配置寄存器和配置签名。
 * @details 将 cfg_reg_data[] 中的值写入寄存器 0x01 到 0x13，
 *          然后计算 CRC8 并写入配置签名寄存器（0x00）。
 *          这完成配置并进入正常模式。
 */
static void TLE9183QK_Write_Configuration(void)
{
    uint8 i;
    uint8 crc;

    /* 写入所有配置寄存器 0x01 到 0x13 */
    for (i = 0; i < 19; i++)
    {
        TLE9183QK_WriteFunction(Conf_Gen_1_ADD + i, cfg_reg_data[i]);
    }

    /* 计算 CRC8 并写入配置签名寄存器 0x00 */
    crc = CRC8_Calculation();
    TLE9183QK_WriteFunction(Conf_Sig_ADD, crc);
}

/* ==================== CRC8 计算 ==================== */
/**
 * @brief   计算配置寄存器值的 CRC8。
 * @details 使用多项式 x^8 + x^6 + x^3 + x^2 + 1 (0x4D)。
 * @return  计算得到的 CRC8 值。
 */
static uint8 CRC8_Calculation(void)
{
    uint8 data = 0;
    uint8 crc = 0;
    uint8 i, j;

    for (j = 0; j < 19; j++)
    {
        data = cfg_reg_data[j] ^ crc;
        for (i = 0; i < 8; i++)
        {
            if (data >= 128)
            {
                data = data << 1;
                data = data ^ 0x4D;   /* x^8 + x^6 + x^3 + x^2 + 1 */
            }
            else
            {
                data = data << 1;
            }
        }
        crc = data;
    }
    return crc;
}

/* ==================== SPI 读写函数 ==================== */
/**
 * @brief   通过 SPI 从 TLE9183QK 读取寄存器。
 * @param[in]  reg_address  寄存器地址（7 位，不含读写位）。
 * @param[out] reg_data     指向存储读取数据的指针。
 * @return  读取操作的状态。
 * @retval  0     读取成功。
 * @retval  0xFF  CRC 错误。
 * @retval  0xFE  地址不匹配错误。
 */
uint8 TLE9183QK_ReadFunction(uint8 reg_address, uint8 *reg_data)
{
    uint32 read_command_noCRC = 0;
    uint32 read_command = 0;
    uint32 CRC_R = 0;
    uint32 read_feedbackDrv = 0;
    uint8  SPI_status = 0;
    uint8  CRC_feedback = 0;
    uint8  CRC_cal_read = 0;
    uint8  addr_feedback = 0;
    uint8  reg_status = 0;
    uint8  result_u8;

    reg_address &= 0x7F;
    read_command_noCRC = ((uint32)reg_address) << 16;
    CRC_R = CRC3_Calculation(read_command_noCRC);
    CRC_R &= 0x00000007;
    read_command = read_command_noCRC | CRC_R;

    TLE9183D_SpiTxBuffer_u32 = read_command;
    result_u8 = TLE9183QK_HW_SPISYNCTRANSMIT(SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK);
    result_u8 = TLE9183QK_HW_SPISYNCTRANSMIT(SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK);

    read_feedbackDrv = TLE9183D_SpiRxBuffer_u32;

    SPI_status   = ((uint8)(read_feedbackDrv >> 19)) & 0x1F;
    CRC_feedback = ((uint8)(read_feedbackDrv)) & 0x07;
    CRC_cal_read = (uint8)CRC3_Calculation(read_feedbackDrv);
    CRC_cal_read &= 0x07;
    addr_feedback = ((uint8)(read_feedbackDrv >> 12)) & 0x7F;

    if (CRC_feedback != CRC_cal_read)
    {
        reg_status = 0xFF;
    }
    else if (addr_feedback != reg_address)
    {
        reg_status = 0xFE;
    }
    else
    {
        reg_status = 0;
    }

    if (reg_status == 0)
    {
        *reg_data = (uint8)(read_feedbackDrv >> 4);
    }
    else
    {
        *reg_data = 0;
    }

    return reg_status;
}

/**
 * @brief   通过 SPI 向 TLE9183QK 写入寄存器。
 * @param[in] reg_address  寄存器地址（7 位，不含读写位）。
 * @param[in] reg_data     要写入的数据。
 */
void TLE9183QK_WriteFunction(uint8 reg_address, uint8 reg_data)
{
    uint32 write_command_noCRC = 0;
    uint32 write_command = 0;
    uint32 CRC_W = 0;
    uint8  result_u8;

    reg_address |= 0x80;
    write_command_noCRC = (((uint32)reg_address) << 16) | (((uint32)reg_data) << 8);
    CRC_W = CRC3_Calculation(write_command_noCRC);
    CRC_W &= 0x00000007;
    write_command = write_command_noCRC | CRC_W;

    TLE9183D_SpiTxBuffer_u32 = write_command;
    result_u8 = TLE9183QK_HW_SPISYNCTRANSMIT(SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK);
}

/* ==================== CRC3 计算 ==================== */
/**
 * @brief   计算 SPI 帧的 CRC3。
 * @details 使用多项式 x^3 + x^1 + 1，种子 101。
 * @param[in] dataframe  24 位 SPI 帧（CRC 位已清零）。
 * @return  计算得到的 3 位 CRC。
 */
uint32 CRC3_Calculation(uint32 dataframe)
{
    uint32 datafield = 0;
    uint32 MSBbit = 0;
    uint32 crc = 0;
    uint8  i;

    datafield = dataframe & 0x00FFFFF8;
    datafield = datafield ^ 0x00800000;
    for (i = 0; i < 21; i++)
    {
        MSBbit = (datafield & 0x00800000) >> 23;
        if (MSBbit == 1)
        {
            datafield ^= 0x00B00000;
        }
        datafield <<= 1;
    }
    crc = (datafield & 0x00E00000) >> 21;
    return crc;
}

/* ==================== 读取 NOP ==================== */
/**
 * @brief   读取 No Operation 寄存器（0x32）以检查 SPI 通信。
 * @return  如果 SPI 通信成功返回 0，否则返回错误码。
 */
uint8 TLE9183QK_Read_No_Operation_0x32(void)
{
    uint8 data_0x32;
    return TLE9183QK_ReadFunction(nop_ADD, &data_0x32);
}

/* ==================== 读取操作模式 ==================== */
/**
 * @brief   读取操作模式总览寄存器（0x40）。
 * @return  当前操作模式，类型为 Operation_ModeType。
 */
Operation_ModeType TLE9183QK_Read_Operation_Mode_0x40(void)
{
    static Operation_ModeType mode = No_mode;
    uint8 data_0x40 = 0;
    TLE9183QK_ReadFunction(Om_over_ADD, &data_0x40);

    switch (data_0x40)
    {
        case 0x00: mode = No_mode;        break;
        case 0x01: mode = idle_mode;      break;
        case 0x02: mode = conf_mode;      break;
        case 0x04: mode = conf_lock_mode; break;
        case 0x08: mode = self_test_mode; break;
        case 0x10: mode = soff_mode;      break;
        case 0x20: mode = err_mode;       break;
        case 0x40: mode = rect_mode;      break;
        case 0x80: mode = norm_mode;      break;
        default:   mode = No_mode;        break;
    }
    return mode;
}

/* ==================== 错误寄存器读取函数 ==================== */
/**
 * @brief   读取错误总览寄存器（0x41）。
 * @return  0 = 无错误，1 = SPI 错误，2 = 存在错误。
 */
uint8 TLE9183QK_Read_Err_over_0x41(void)
{
    uint8 data_0x41 = 0;
    uint8 rtn = TLE9183QK_ReadFunction(Err_over_ADD, &data_0x41);
    if (rtn != 0) return 1;
    return (data_0x41 == 0) ? 0 : 2;
}

/**
 * @brief   读取特殊事件寄存器（0x42）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Special_Event_0x42(void)
{
    uint8 data_0x42 = 0;
    TLE9183QK_ReadFunction(Ser_ADD, &data_0x42);
    return data_0x42;
}

/**
 * @brief   读取内部错误 1 寄存器（0x43）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Internal_Errors1_0x43(void)
{
    uint8 data_0x43 = 0;
    TLE9183QK_ReadFunction(Err_i_1_ADD, &data_0x43);
    return data_0x43;
}

/**
 * @brief   读取内部错误 2 寄存器（0x44）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Internal_Errors2_0x44(void)
{
    uint8 data_0x44 = 0;
    TLE9183QK_ReadFunction(Err_i_2_ADD, &data_0x44);
    return data_0x44;
}

/**
 * @brief   读取外部错误寄存器（0x45）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_External_Errors_0x45(void)
{
    uint8 data_0x45 = 0;
    TLE9183QK_ReadFunction(Err_e_ADD, &data_0x45);
    return data_0x45;
}

/**
 * @brief   读取关断错误寄存器（0x46）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Shutdown_Errors_0x46(void)
{
    uint8 data_0x46 = 0;
    TLE9183QK_ReadFunction(Err_sd_ADD, &data_0x46);
    return data_0x46;
}

/**
 * @brief   读取短路错误寄存器（0x47）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Short_Circuit_Errors_0x47(void)
{
    uint8 data_0x47 = 0;
    TLE9183QK_ReadFunction(Err_scd_ADD, &data_0x47);
    return data_0x47;
}

/**
 * @brief   读取输入模式违规寄存器（0x48）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Input_Pattern_Violations_0x48(void)
{
    uint8 data_0x48 = 0;
    TLE9183QK_ReadFunction(Err_indiag_ADD, &data_0x48);
    return data_0x48;
}

/**
 * @brief   读取输出级反馈错误寄存器（0x49）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Output_Stage_Feedback_Errors_0x49(void)
{
    uint8 data_0x49 = 0;
    TLE9183QK_ReadFunction(Err_osf_ADD, &data_0x49);
    return data_0x49;
}

/**
 * @brief   读取 SPI 通信和配置错误寄存器（0x4A）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_SPI_Communication_Configuration_Errors_0x4A(void)
{
    uint8 data_0x4A = 0;
    TLE9183QK_ReadFunction(Err_spiconf_ADD, &data_0x4A);
    return data_0x4A;
}

/**
 * @brief   读取电流采样放大器 1 和 2 错误寄存器（0x4B）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Current_Sense_Amplifiers_1_2_Errors_0x4B(void)
{
    uint8 data_0x4B = 0;
    TLE9183QK_ReadFunction(Err_op_12_ADD, &data_0x4B);
    return data_0x4B;
}

/**
 * @brief   读取电流采样放大器 3 错误寄存器（0x4C）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Current_Sense_Amplifiers_3_Errors_0x4C(void)
{
    uint8 data_0x4C = 0;
    TLE9183QK_ReadFunction(Err_op_3_ADD, &data_0x4C);
    return data_0x4C;
}

/**
 * @brief   读取数字输出引脚错误寄存器（0x4D）。
 * @return  寄存器值。
 */
uint8 TLE9183QK_Read_Digital_Output_Pin_Errors_0x4D(void)
{
    uint8 data_0x4D = 0;
    TLE9183QK_ReadFunction(Err_outp_ADD, &data_0x4D);
    return data_0x4D;
}

/* ==================== 示例集成函数 ==================== */
#if 0
/**
 * @brief   示例 ECU 初始化函数。
 * @details 初始化 SPI 底层驱动和 TLE9183QK 设备。
 *          检查全局 Normal_Mode_OK 标志以确认成功。
 */
void Ecu_Init(void)
{
    TLE9183D_HW_Init();      /* 初始化 SPI 底层驱动 */
    TLE9183QK_init();        /* 初始化 TLE9183QK */

    if (Normal_Mode_OK == 1)
    {
        /* 初始化成功，可以开始 PWM 输出 */
    }
    else
    {
        /* 初始化失败，检查硬件、SPI、电源等 */
    }
}

/**
 * @brief   TLE9183QK 示例诊断任务。
 * @details 周期性读取错误总览寄存器并处理错误。
 */
void TLE9183QK_Diag_Task(void)
{
    uint8 err = TLE9183QK_Read_Err_over_0x41();
    if (err == 1) { /* SPI 错误 */ }
    else if (err == 2) { /* 存在错误，可进一步读取具体寄存器 */ }
}  
#endif

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
uint8 TLE9183QK_BriefTest(void)
{
    uint8 data = 0;
    Operation_ModeType mode;

    TLE9183D_HW_Init();
    TLE9183QK_ENA_LOW();
    TLE9183QK_SOFF_N_LOW();
    TLE9183QK_INH_N_HIGH();

    /* 1. 检查 SPI 通信：读取 NOP 寄存器 0x32 */
    if (TLE9183QK_Read_No_Operation_0x32() != 0)
    {
        return 1;   /* SPI 通信失败 */
    }

    /* 2. 读取操作模式 */
    mode = TLE9183QK_Read_Operation_Mode_0x40();
    if ((mode != norm_mode) && (mode != idle_mode))
    {
        return 2;   /* 操作模式异常 */
    }

    /* 3. 读取错误总览寄存器 0x41，检查是否有错误 */
    if (TLE9183QK_Read_Err_over_0x41() == 2)
    {
        return 3;   /* 存在错误 */
    }

    /* 所有检查通过 */
    return 0;
}
