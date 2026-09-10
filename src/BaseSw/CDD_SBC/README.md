# TLF35584 CDD_SBC

This module uses the existing AUTOSAR MCAL QSPI2 configuration:

- Channel: `SpiChannel_QSPI2_TLF35584`
- Sequence: `SpiSequence_QSPI2_35584`
- Frame width: 16 bits, MSB first
- Clock: 1 MHz, SPI mode 0
- Chip select: hardware controlled, active low

## Integration

1. Add `CDD_SBC/inc` to the compiler include paths.
2. Add `CDD_SBC/src/CDD_SBC.c` to the build.
3. Initialize `Mcu`, `Port`, and `Spi` before calling `CDD_SBC_Init()`.
4. Call `CDD_SBC_WD_Service()` only in the configured watchdog open window.

The compatibility aliases in `CDD_SBC.h` support the existing disabled sample
for mode change, VCC2 control, and timeout watchdog setup. The name `VCC2` is
mapped to the TLF35584 communication LDO (`QCO`/`COMEN`). Confirm this mapping
against the board-level power naming before enabling it.

## Important correction to the existing sample

`CDD_SBC_ReadProductId()` is intentionally not provided. The supplied
TLF35584 data sheet does not define a public product-ID register. Use
`CDD_SBC_Init()` for an SPI communication/parity check and
`CDD_SBC_GetDeviceStatus()` to read the current device state.

## Watchdog periods

`CDD_SBC_WD_PERIOD_200MS` configures a 100 ms closed window followed by a
100 ms open window. A service call at exactly 200 ms is not safe because it
falls on a tolerance boundary. Schedule the service inside the open window
with timing margin.

Protected watchdog configuration follows the TLF35584 requirement to read,
rewrite, and verify all seven protected configuration registers before the
lock sequence is applied.
