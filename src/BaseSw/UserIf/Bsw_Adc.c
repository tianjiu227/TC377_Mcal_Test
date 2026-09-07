/*
 * Bsw_Adc.c
 *
 *  Created on: 2025��4��28��
 *      Author: ye.lu1
 */

#include "Bsw_Adc.h"
#include "Irq.h"
#include "IfxSrc_reg.h"
#include "IfxEvadc_reg.h"
#include "Bsw_Pwm.h"

unsigned char ENABLE_PWM = 0;
ADC_RESULT_TYPE ADC_RESULT_BUFFER;
float DutyCycle[3] = {0.2,0.5,0.9};
//float DutyCycle[3] = {0.5,0.5,0.5};

void Adc_Sync_Callback_Motor(void)
{
	if(ENABLE_PWM)
		PWM_Update(DutyCycle);
	else
		PWM_Disable();
	ADC_GetResult();
}

void ADC_All_Init(void)
{
	Adc_Init(&Adc_Config);
	IrqAdc_Init();
	SRC_VADC_G0_SR0.B.SRE = 1U;
	Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_AN0, &(ADC_RESULT_BUFFER.SyncChannel.ADC_I_U));
	Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_AN0);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_AN0);
}

void ADC_GetResult(void)
{
	// Adc_StartGroupConversion(AdcConf_AdcGroup_AdcG0SW);
	// Adc_StartGroupConversion(AdcConf_AdcGroup_AdcG3SW);
	// Adc_StartGroupConversion(AdcConf_AdcGroup_AdcG8SW);
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_REF1 = EVADC_G0_RES2.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_I_HV1 = EVADC_G0_RES3.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_REF2 = EVADC_G3_RES0.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_BATT = EVADC_G3_RES1.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_SUPPLY = EVADC_G8_RES0.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_I_HV2 = EVADC_G8_RES1.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_12V = EVADC_G8_RES2.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_C = EVADC_G8_RES3.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_W_MOS_TEMP = EVADC_G8_RES4.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_35584_TEMP1 = EVADC_G8_RES5.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_MODE_REG = EVADC_G8_RES6.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_35584_TEMP2 = EVADC_G8_RES7.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_V_MOS_TEMP = EVADC_G8_RES8.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_U_MOS_TEMP = EVADC_G8_RES9.B.RESULT;
	// ADC_RESULT_BUFFER.ScanChannel.ADC_PRE_CHARGE = EVADC_G8_RES10.B.RESULT;
}

void IoHwAb_AdcNotification0(void)
{

}
void IoHwAb_AdcNotification1(void)
{

}
void IoHwAb_AdcNotification2(void)
{

}
void IoHwAb_AdcNotification3(void)
{

}
void IoHwAb_AdcNotification32(void)
{

}
void IoHwAb_AdcNotification64(void)
{

}
void IoHwAb_AdcNotification66(void)
{

}
void IoHwAb_AdcNotification96(void)
{

}
void IoHwAb_AdcNotification97(void)
{

}
void IoHwAb_AdcNotification256(void)
{

}
void IoHwAb_AdcNotification257(void)
{

}
void IoHwAb_AdcNotification258(void)
{

}
void IoHwAb_AdcNotification259(void)
{

}
void IoHwAb_AdcNotification260(void)
{

}
void IoHwAb_AdcNotification320(void)
{

}
void IoHwAb_AdcNotification321(void)
{

}

void IoHwAb_AdcNotification65(void)
{
	
}