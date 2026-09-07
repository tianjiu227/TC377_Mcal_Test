#include "Delay.h"

/* STM 100MHZ ticks 0.00000001s, 1s 100000000 */

/**
 * @brief  Microsecond delay
 * @param  us: number of microseconds to delay (range: 0~42949672, about 42.9 seconds max)
 * @note   1us = 100 ticks (100MHz clock: 1us / 10ns = 100)
 */
void delay_us(uint32 us)
{
    uint32 CurrSTMTick = Mcal_DelayGetTick();
    uint32 BaseSTMTick = CurrSTMTick;
    while ((uint32)((CurrSTMTick - BaseSTMTick) & 0xffffffff) < us * 100)
    {
        CurrSTMTick = Mcal_DelayGetTick();
    }
}

/**
 * @brief  Millisecond delay
 * @param  ms: number of milliseconds to delay (range: 0~42949, about 42.9 seconds max)
 * @note   1ms = 100,000 ticks (100MHz clock: 1ms / 10ns = 100,000)
 */
void delay_ms(uint32 ms)
{
    uint32 CurrSTMTick = Mcal_DelayGetTick();
    uint32 BaseSTMTick = CurrSTMTick;
    while ((uint32)((CurrSTMTick - BaseSTMTick) & 0xffffffff) < ms * 100000)
    {
        CurrSTMTick = Mcal_DelayGetTick();
    }
}

/**
 * @brief  Second delay
 * @param  s: number of seconds to delay (range: 0~42)
 * @note   1s = 100,000,000 ticks (100MHz clock: 1s / 10ns = 100,000,000)
 */
void delay_s(uint32 s)
{
    uint32 CurrSTMTick = Mcal_DelayGetTick();
    uint32 BaseSTMTick = CurrSTMTick;
    while ((uint32)((CurrSTMTick - BaseSTMTick) & 0xffffffff) < s * 100000000UL)
    {
        CurrSTMTick = Mcal_DelayGetTick();
    }
}
