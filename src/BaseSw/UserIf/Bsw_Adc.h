/*
 * Bsw_Adc.h
 *
 *  Created on: 2025��4��28��
 *      Author: ye.lu1
 */

#ifndef BSW_ADC_H_
#define BSW_ADC_H_

#include "Adc.h"

extern void ADC_All_Init(void);
extern void ADC_GetResult(void);
extern void Adc_Raw_To_Phy_Conversion(void);
extern void Adc_Sync_Callback_Motor(void);


#define MOTOR_POSITION_SENSOR_DEVIATION  (0.0f) /* 传感器机械角度偏差 */

/* Raw-to-physical conversion type: pre-computed physical values from ADC raw data */
typedef struct
{
    float F_ADC_I_U;           /* U-phase current (A)  | AN0  */
    float F_ADC_I_U_2ND;       /* U-phase current (A)  | AN5  */
    float F_ADC_I_V;           /* V-phase current (A)  | AN8  */
    float F_ADC_I_V_2ND;       /* V-phase current (A)  | AN13 */
    float F_ADC_I_W;           /* W-phase current (A)  | AN16 */
    float F_ADC_I_W_2ND;       /* W-phase current (A)  | AN21 */
    float F_ADC_V_C;           /* HV bus voltage (V)   | AN37 */
	float F_ADC_PRE_CHARGE;    /**< KL40_1 Pre-Charging Voltage Sampling  (V)   | AN38 */
	float F_ADC_I_HV;          /* 母线电流 */
} ADC_RAW_TO_PHY_TYPE;

extern ADC_RAW_TO_PHY_TYPE ADC_RAW_TO_PHY_BUFFER;
extern unsigned char ENABLE_PWM;
extern float DutyCycle[3];

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
		Adc_ValueGroupType ADC_V_REF1;//AN3
		Adc_ValueGroupType ADC_I_HV1;//AN4
		Adc_ValueGroupType ADC_V_REF2;//AN25
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
		Adc_ValueGroupType ADC_PRE_CHARGE;//AN38
	}ScanChannel;

}ADC_RESULT_TYPE;

extern ADC_RESULT_TYPE ADC_RESULT_BUFFER;




#endif /* BSW_ADC_H_ */
