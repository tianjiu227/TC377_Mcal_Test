# CDD_TLE9183

本 CDD 使用现有 TASKING 工程的 `QSPI4 / SpiSequence_QSPI4_9183QK`，按 TLE9183QK User Manual 实现 24 bit SPI、延迟响应和 CRC3 校验。

注意：TLE9183 的响应不是同一帧返回，而是下一帧返回，因此读写接口内部都会自动发送一次 NOP（地址 `0x32`）。配置寄存器 `0x00..0x1F` 的写入必须按实际电机、MOSFET、电流采样和保护策略填写；配置签名 `0x00` 必须在完整配置后最后写入。

集成：加入 `CDD_TLE9183/inc` include path，加入 `CDD_TLE9183/src/CDD_TLE9183.c`，并在 MCU 初始化后调用 `CDD_TLE9183_Init()`。实际下载前必须通过示波器/逻辑分析仪确认 CSN、24 个时钟、MSB-first、CRC3 和地址回显。
