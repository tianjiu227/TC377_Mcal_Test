#ifndef CDD_TLE9183_CFG_H
#define CDD_TLE9183_CFG_H

/*
 * TLE9183 CDD 的 MCAL 适配配置。
 * QSPI4 的 24 bit 帧宽、模式 0、SLSO3 低有效片选均由 EB 生成代码管理；
 * 本 CDD 不直接写 QSPI 寄存器，避免与 MCAL 的所有权冲突。
 */
#include "Spi_Cfg.h"

/* TLE9183 使用 QSPI4：24 bit、MSB-first、模式 0、硬件低有效片选。 */
#define CDD_TLE9183_SPI_CHANNEL \
    SpiConf_SpiChannel_SpiChannel_QSPI4_TLE9183QK
#define CDD_TLE9183_SPI_SEQUENCE \
    SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK

#endif
