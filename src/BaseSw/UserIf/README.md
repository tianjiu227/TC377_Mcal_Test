# TLE9183D AUTOSAR CDD skeleton

This package keeps the user's existing low-level AUTOSAR MCAL SPI access pattern:

```c
uint32 TLE9183D_SpiTxBuffer_u32;
uint32 TLE9183D_SpiRxBuffer_u32;

Spi_SetupEB(...,
    (Spi_DataBufferType *)&TLE9183D_SpiTxBuffer_u32,
    (Spi_DataBufferType *)&TLE9183D_SpiRxBuffer_u32,
    1u);
```

## Included

- TLE9183D.c / .h
- TLE9183D_Hw.c / .h
- TLE9183D_Cfg.h
- TLE9183D_Reg.h
- TLE9183D_Types.h

## Implemented

- MCAL SPI wrapper
- synchronous transfer + sequence-result check
- retry framework
- CRC3 implementation
- register read/write abstraction
- delayed response handling skeleton
- startup diagnostics skeleton
- init state tracking
- GPIO/delay hooks for INH / ENA / SOFF / ERR
- configuration CRC8 helper

## Important integration note

The TLE9183QK datasheet says the exact SPI frame format and register definitions
are documented separately in the TLE9183 User Manual / TLE9183 Registers document.

Therefore:

1. `TLE9183D_Reg.h` contains only addresses explicitly present in the datasheet.
2. SPI frame address/data/command masks are isolated as placeholders.
3. Project-specific configuration register writes are intentionally not invented.
4. Before production use, align the frame packing and register table to the official
   register document and your safety concept.

## Datasheet-derived communication requirements

- 24-bit SPI frame
- MSB first
- CRC3 over SPI frame excluding CRC bits
- CRC polynomial x^3 + x + 1
- retry / reject invalid CRC frame
- max SPI clock 10 MHz
- exact 24 rising + 24 falling clock edges per frame
- configuration CRC8 polynomial x^8 + x^6 + x^3 + x^2 + 1
- power-up diagnostics and configuration sequence should follow Figure 21
