/*
 * Cdd_Tlf35584_Spi.h
 *
 *  Created on: 2021Äê8ÔÂ25ÈÕ
 *      Author: admin
 */

#ifndef CDD_35584_CDD_TLF35584_SPI_H_
#define CDD_35584_CDD_TLF35584_SPI_H_

/*****************************************Include Files***************************************/
#include "Std_Types.h"
#include "Spi.h"
/**************************************Global Macor Define************************************/

/***************************************Global Variable Define********************************/


/***************************************Global function Define********************************/
extern void Tlf35584_SPI_Init(void);
extern uint16 Tlf35584_SPI_Read(uint16 Data);
extern uint16 Tlf35584_SPI_Write(uint16 Data);
extern void Tlf35584_SetMPSPinLevelLow(void);
extern void Tlf35584_SetMPSPinLevelHigh(void);
extern void Tlf35584_SetWDIPinLevelLow(void);
extern void Tlf35584_SetWDIPinLevelHigh(void);
extern void Tlf35584_SetWAKPinLevelLow(void);
extern void Tlf35584_SetWAKPinLevelHigh(void);
extern void Tlf35584_SetFREPinLevelLow(void);
extern void Tlf35584_SetFREPinLevelHigh(void);
extern uint8 Tlf35584_GetMPSPinLevel(void);

#endif /* 1_LIB_0_BSW_4_CDD_35584_CDD_TLF35584_SPI_H_ */
