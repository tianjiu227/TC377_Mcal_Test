#ifndef CDD_SBC_CFG_H
#define CDD_SBC_CFG_H

/*
 * TLF35584 CDD 的工程适配层。
 *
 * 本文件不直接配置 QSPI 寄存器，而是引用 EB tresos 已生成的 SPI
 * 通道和序列。若 QSPI2 的位宽、片选或序列名称发生变化，必须同时更新
 * 这里的映射，并用逻辑分析仪复核 16 bit 帧和偶校验位。
 */
#include "Spi_Cfg.h"
#include "Delay.h"

/* TLF35584 使用工程既有的 QSPI2，帧宽由 MCAL 配置为 16 bit。 */
#define CDD_SBC_SPI_CHANNEL \
    SpiConf_SpiChannel_SpiChannel_QSPI2_TLF35584
#define CDD_SBC_SPI_SEQUENCE \
    SpiConf_SpiSequence_SpiSequence_QSPI2_35584

/*
 * 状态切换后最多等待 3 ms；每轮轮询间隔为 10 us。
 * 超时并不重试写 DEVCTRL，以免在总线故障时重复触发状态切换。
 */
#define CDD_SBC_STATE_POLL_COUNT        (300U)
#define CDD_SBC_STATE_POLL_DELAY_US     (10U)
/*
 * 受保护配置重新锁定后，按芯片要求等待配置生效。
 * 该延时结束前读取 RSYSPCFGx 可能得到尚未生效的旧值。
 */
#define CDD_SBC_CONFIG_APPLY_DELAY_US   (60U)

#define CDD_SBC_DELAY_US(delayUs)       delay_us((uint32)(delayUs))

#endif /* CDD_SBC_CFG_H */
