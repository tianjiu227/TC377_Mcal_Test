

/****************************************************************************************/
/* Include Files */
/****************************************************************************************/
#include "TLE9183D_HW.h"
//#include "IoHwAb_Cfg.h"
//#include "TLE9180D.h"


uint32 TLE9183D_SpiTxBuffer_u32;
uint32 TLE9183D_SpiRxBuffer_u32;


/****************************************************************************************/
/* ----------------------------------Public Function -----------------------------------*/
/****************************************************************************************/
/****************************************************************************************
* Function Name :
* Description   :
* Argument      :
* Return Value  :
****************************************************************************************/
Std_ReturnType TLE9183D_HW_Init (void)
{
	Std_ReturnType result_u8 = E_OK;
    result_u8 |= TLE9183D_HW_SPISETUPEB(
	SpiConf_SpiChannel_SpiChannel_QSPI4_TLE9183QK,
		 (TLE9183D_HW_SPIDATATYPE *) &TLE9183D_SpiTxBuffer_u32,
		 (TLE9183D_HW_SPIDATATYPE *) &TLE9183D_SpiRxBuffer_u32,
		 TLE9183D_HW_SPI_TRANSFER_LENGTH);
	
}
