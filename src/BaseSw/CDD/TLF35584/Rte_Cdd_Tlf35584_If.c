/*
 * Cdd_35584_Rte.c
 *
 *  Created on: 2023Äê9ÔÂ15ÈÕ
 *      Author: admin
 */

#include "Cdd_Tlf35584.h"
#include <Rte_Cdd_Tlf35584_If.h>

/********************************************************************************************
**                      Private Function                                                  **
********************************************************************************************/
static void ValueFromCddToRte(void);


/********************************************************************************************
**                     Rte_Tlf35584_Init                                                  **
********************************************************************************************/
void Rte_Cdd_Tlf35584_Init(void)
{
	Tlf35584_Init();
}


/********************************************************************************************
**                     Rte_Tlf35584_MainFunction                                           **
********************************************************************************************/
void Rte_Cdd_Tlf35584_MainFunction(void)
{
	Tlf35584_Run();
	ValueFromCddToRte();
}

/********************************************************************************************
**                     Rte_Tlf35584_NMI                                           **
********************************************************************************************/
void Rte_Cdd_Tlf35584_NMI(void)
{
	Tlf35584_ErrHook();
}

/********************************************************************************************
**                     ValueFromCddToRte                                                   **
********************************************************************************************/
static void ValueFromCddToRte(void)
{
	uint16 SbcIntErrU16 = 0;
	uint16 SBCErrU16 = 0;
	uint8 SBCMode_U8 = 0;
	uint8 SBCSupplyState_U8 = 0;
	uint8 SBCWindowWatchdogState_U8 = 0;
	uint8 SBCFunctionalWatchdogState_U8 = 0;
	uint8 SBCWakeUpTimerSetting_U8 = 0;
	uint32 SBCWakeUpTimerCounter_U32 = 0;
	uint8 mBSW_SBCProtectState_U8 = 0;

	SBCErrU16 = Tlf35584_GetError();
	SBCMode_U8 = (uint8)(Tlf35584_GetMode() - 1U);
	SBCSupplyState_U8 = Tlf35584_GetPowerSts();
	SBCWindowWatchdogState_U8 = Tlf35584_GetWindowWdgSts();
	SBCFunctionalWatchdogState_U8 = Tlf35584_GetFunctionWdgSts();
	Tlf35584_GetWakeTimerSts(&SBCWakeUpTimerSetting_U8,&SBCWakeUpTimerCounter_U32);

//	Rte_Write_KL06_BMS_CDD_mBSW_SbcIntErrU16_en_mBSW_SbcIntErrU16_en(0);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCErr_U16_mBSW_SBCErr_U16(SBCErrU16);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCMode_U8_mBSW_SBCMode_U8(SBCMode_U8);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCSupplyState_U8_mBSW_SBCSupplyState_U8(SBCSupplyState_U8);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCWindowWatchdogState_U8_mBSW_SBCWindowWatchdogState_U8(SBCWindowWatchdogState_U8);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCFunctionalWatchdogState_U8_mBSW_SBCFunctionalWatchdogState_U8(SBCFunctionalWatchdogState_U8);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCWakeUpTimerSetting_U8_mBSW_SBCWakeUpTimerSetting_U8(SBCWakeUpTimerSetting_U8);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCWakeUpTimerCounter_U32_mBSW_SBCWakeUpTimerCounter_U32(SBCWakeUpTimerCounter_U32);
//	Rte_Write_KL06_BMS_CDD_CDD_SBC_mBSW_SBCProtectState_U8_mBSW_SBCProtectState_U8(mBSW_SBCProtectState_U8);


}
