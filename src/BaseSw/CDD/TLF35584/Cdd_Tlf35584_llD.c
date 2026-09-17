/*
 * Cdd_Tlf35584_Spi.c
 *
 *  Created on: 2021��8��25��
 *      Author: admin
 */

#include <Cdd_Tlf35584_llD.h>
#include "Dio.h"
#include "Spi.h"
/********************************************************************************************
**                     Private  Variable Definitions                          **
********************************************************************************************/
#define CDD_TLF_35584_START_DATA
#include "Cdd_Memmap.h"

__align(16) uint16 SPISendBuffer;
__align(16) uint16 SPIRecBuffer;
Std_ReturnType Result = E_NOT_OK;

/********************************************************************************************
**                     Initiate TLF35584                                      **
********************************************************************************************/
void Tlf35584_SPI_Init(void)
{
	Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_QSPI2_TLF35584,(uint8*)&SPISendBuffer,(uint8*)&SPIRecBuffer,1);
}

/********************************************************************************************
**                      SPI Read TLF35584                                      **
********************************************************************************************/
uint16 Tlf35584_SPI_Read(uint16 Data)
{
	SPISendBuffer = Data;
	Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_QSPI2_35584);
	return SPIRecBuffer;
}


/********************************************************************************************
 **                     SPI Write TLF35584                                      **
 ********************************************************************************************/
uint16 Tlf35584_SPI_Write(uint16 Data)
{
	SPISendBuffer = Data;
	Result = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_QSPI2_35584);
	return SPIRecBuffer;
}

/********************************************************************************************
**                     TTlf35584_SetMPSPinLevelLow                                         **
********************************************************************************************/
void Tlf35584_SetMPSPinLevelLow(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_DO_35584_MPS,STD_HIGH);
}

/********************************************************************************************
**                     Tlf35584_SetMPSPinLevelHigh                                         **
********************************************************************************************/
void Tlf35584_SetMPSPinLevelHigh(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_DO_35584_MPS,STD_LOW);
}

/********************************************************************************************
**                     Tlf35584_SetWDIPinLevelLow                                          **
********************************************************************************************/
void Tlf35584_SetWDIPinLevelLow(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_P15_7,STD_LOW);
}

/********************************************************************************************
**                     Tlf35584_SetWDIPinLevelHigh                                         **
********************************************************************************************/
void Tlf35584_SetWDIPinLevelHigh(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_P15_7,STD_HIGH);
}

/********************************************************************************************
**                     Tlf35584_SetWAKPinLevelLow                                         **
********************************************************************************************/
void Tlf35584_SetWAKPinLevelLow(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_MCU_HOLD,STD_LOW);
}

/********************************************************************************************
**                     Tlf35584_SetWAKPinLevelHigh                                         **
********************************************************************************************/
void Tlf35584_SetWAKPinLevelHigh(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_MCU_HOLD,STD_HIGH);
}

/********************************************************************************************
**                     Tlf35584_GetMPDPinLevel                                             **
********************************************************************************************/
//uint8 Tlf35584_GetMPSPinLevel(void)
//{
//	return !Dio_ReadChannel(DioConf_DioChannel_DO_35584_MPS);
//}

/********************************************************************************************
**                     Tlf35584_SetFREPinLevelLow                                          **
********************************************************************************************/
void Tlf35584_SetFREPinLevelLow(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_DO_FRE_35584,STD_HIGH);
}

/********************************************************************************************
**                     Tlf35584_SetFREPinLevelHigh                                         **
********************************************************************************************/
void Tlf35584_SetFREPinLevelHigh(void)
{
	//Dio_WriteChannel(DioConf_DioChannel_DO_FRE_35584,STD_LOW);
}


#define CDD_35584_STOP_CODE
#include "Cdd_Memmap.h"
