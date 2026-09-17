
#ifndef TLE9183D_HW_H
#define TLE9183D_HW_H

/****************************************************************************************/
/* Include Files */
/****************************************************************************************/
#include "Std_Types.h"
#include "string.h"
#include "Spi.h"
#include "Spi_Cfg.h"



extern uint32 TLE9183D_SpiTxBuffer_u32;
extern uint32 TLE9183D_SpiRxBuffer_u32;

#define TLE9183D_HW_SPISETUPEB                 Spi_SetupEB
#define TLE9183D_HW_SPISYNCTRANSMIT            Spi_SyncTransmit
#define TLE9183D_HW_SPIGETSEQUENCERESULT       Spi_GetSequenceResult
#define TLE9183D_HW_SPI_TRANSFER_LENGTH        1
#define TLE9183D_HW_SPIDATATYPE                Spi_DataBufferType

Std_ReturnType TLE9183D_HW_Init (void);
void TLE9183D_Read_Err_Task(void);


#endif /* CAN_TLT9255_HW */

