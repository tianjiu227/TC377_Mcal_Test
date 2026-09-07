#ifndef USER_ADC_H_
#define USER_ADC_H_
#if 0

#include "IfxSrc_reg.h"
#include "Adc.h"
#include "Irq.h"


extern Adc_ValueGroupType ADC_SW_GRP_RES[];

void ADC_Init(void);
void ADC_GetBySoftwareTrigger(void);

 
void DemoApp_Adc_Init(void);
void Adc_HWGroupDemo(void);


extern void ADC_Init(void);
extern void ADC_GetResult(void);

typedef struct
{
	struct
	{
		Adc_ValueGroupType ADC_I_U;//AN0
		Adc_ValueGroupType ADC_I_U_2ND;//AN5
		Adc_ValueGroupType ADC_I_V;//AN8
		Adc_ValueGroupType ADC_I_V_2ND;//AN13
		Adc_ValueGroupType ADC_I_W;//AN16
		Adc_ValueGroupType ADC_I_W_2ND;//AN21
	}SyncChannel;
	struct
	{
		Adc_ValueGroupType ADC_I_HV1;//AN4
		Adc_ValueGroupType ADC_V_REF;//AN25
		Adc_ValueGroupType ADC_V_BATT;//AN27
		Adc_ValueGroupType ADC_V_SUPPLY;//AN33
		Adc_ValueGroupType ADC_I_HV2;//AN35
		Adc_ValueGroupType ADC_V_12V;//AN36
		Adc_ValueGroupType ADC_V_C;//AN37
		Adc_ValueGroupType ADC_W_MOS_TEMP;//AN42
		Adc_ValueGroupType ADC_35584_TEMP1;//AN43
		Adc_ValueGroupType ADC_MODE_REG;//AN44
		Adc_ValueGroupType ADC_35584_TEMP2;//AN45
		Adc_ValueGroupType ADC_V_MOS_TEMP;//AN46
		Adc_ValueGroupType ADC_U_MOS_TEMP;//AN47
	}ScanChannel;

}ADC_RESULT_TYPE;


#endif

#endif
