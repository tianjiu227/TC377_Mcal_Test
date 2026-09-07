#include "User_Adc.h"

#if 0
static volatile uint8 EVADCInitReturn = 100;
Adc_ValueGroupType ADC_SW_GRP_RES[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static Std_ReturnType AdcBufferSetupStatus = 100;
Adc_StartupCalibStatusType CalStatus;
void ADC_Init(void)
{
	int loopindex = 3;
	IrqAdc_Init();
	SRC_VADCG8SR0.B.SRE = 1;
	SRC_VADCG8SR1.B.SRE = 1;
	SRC_VADCG8SR2.B.SRE = 1;
  SRC_VADCG8SR3.B.SRE = 1;

	for(loopindex = 0 ;loopindex < 3;loopindex++)
	{
		Adc_Init(&Adc_Config);
		EVADCInitReturn = Adc_InitCheck(&Adc_Config);
		if(EVADCInitReturn == E_OK)
		{
			CalStatus = Adc_TriggerStartupCal();
			do
			{
				CalStatus = Adc_GetStartupCalStatus();
			} while (CalStatus != ADC_STARTUP_CALIB_OVER);

			Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_AN32);
			AdcBufferSetupStatus = Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_AN32, ADC_SW_GRP_RES);
			Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_AN32);
			return;
		}
	}
}

void ADC_GetBySoftwareTrigger(void)
{
	//Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_0);
	//AdcBufferSetupStatus = Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_0, ADC_SW_GRP_RES);
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_AN32);
}



uint32 PCBLayout = 0xff;
volatile uint32 EVADCInterrupt = 0;
void IoHwAb_AdcNotification65(void)
{
	/* if (ADC_SW_GRP_RES[2] > 0x0300)
	{
		PCBLayout = 0;
	}
	else if (ADC_SW_GRP_RES[3] > 0300)
	{
		PCBLayout = 1;
	}
	EVADCInterrupt++; */
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


/* 娴嬭瘯浠ｇ爜濡備笅锛岀涓�閮ㄥ垎瀹屾垚浜咥DC鐨勫垵濮嬪寲锛岀浜岄儴鍒嗗垯鍦ㄨ缃簡AD杞崲缁撴灉buffer涔嬪悗锛屼娇鑳戒簡纭欢瑙﹀彂锛�
骞跺湪娴佸紡杞悗濉弧buffer涔嬪悗锛屽け鑳戒簡纭欢瑙﹀彂锛堝睆钄界殑鎵撳嵃閮ㄥ垎鎵撳嵃浜嗗悇涓�氶亾鐨勫叾涓竴涓粨鏋滐級銆�

 */

#if 1
void DemoApp_Adc_Init(void)
{
  // SRC_VADCG0SR0.U |= SRE_ENABLE;
  SRC_VADCG0SR0.B.SRE = 1;
	SRC_VADCG0SR1.B.SRE = 1;
	SRC_VADCG0SR2.B.SRE = 1;
  SRC_VADCG0SR3.B.SRE = 1;
  SRC_VADCG1SR0.B.SRE = 1;
	SRC_VADCG1SR1.B.SRE = 1;
	SRC_VADCG1SR2.B.SRE = 1;
  SRC_VADCG1SR3.B.SRE = 1;
  SRC_VADCG2SR0.B.SRE = 1;
	SRC_VADCG2SR1.B.SRE = 1;
	SRC_VADCG2SR2.B.SRE = 1;
  SRC_VADCG2SR3.B.SRE = 1;


  const Adc_ConfigType * ConfigPtr = NULL_PTR;
  ConfigPtr = &Adc_Config;
  Adc_Init(ConfigPtr);
  /* Wait till the StartUp calibration is over */
  while( (Adc_GetStartupCalStatus()) != E_OK)
  {}
}
 
Adc_ValueGroupType ADC_HW_GRP_RES[16];
void Adc_HWGroupDemo(void)
{
  Adc_StreamNumSampleType AdcHWGroupNoSamples;
  Std_ReturnType AdcBufferSetupStatus;
 
  /* Initialize ADC interrupt */
  IrqAdc_Init();
 
  /* Initialize ADC */
  DemoApp_Adc_Init();
 
  /* Buffer Marker value */
  ADC_HW_GRP_RES[0] = 0x00C8;
 
  /* Initialize the Result buffer for AdcHWGroup */
	AdcBufferSetupStatus = Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_AN0, &ADC_HW_GRP_RES[0]);
	AdcBufferSetupStatus = Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_AN8, &ADC_HW_GRP_RES[1]);
	AdcBufferSetupStatus = Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_AN16,&ADC_HW_GRP_RES[2]);
 
  if(AdcBufferSetupStatus == E_OK)
  {
    Adc_ValueGroupType Demo_ResultPtr0 = 0;
    Adc_ValueGroupType Demo_ResultPtr8 = 0;
    Adc_ValueGroupType Demo_ResultPtr16 = 0;
    Adc_StreamNumSampleType Demo_AdcNoSamp = 0;
 
    /* Initialize the no. of group samples (Streaming length)
       for AdcHWGroup as configured
    */
    AdcHWGroupNoSamples = (Adc_StreamNumSampleType)2;
 
    /* Start the AdcHWGroup group */
    Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_AN0);

    while(Demo_AdcNoSamp != AdcHWGroupNoSamples)
    {
      /* Get the pointer to last conversion result of Adc Group */
      Demo_AdcNoSamp = Adc_GetStreamLastPointer(AdcConf_AdcGroup_AdcGroup_AN0, &Demo_ResultPtr0);
	    Demo_AdcNoSamp = Adc_GetStreamLastPointer(AdcConf_AdcGroup_AdcGroup_AN8, &Demo_ResultPtr8);
	    Demo_AdcNoSamp = Adc_GetStreamLastPointer(AdcConf_AdcGroup_AdcGroup_AN16, &Demo_ResultPtr16);
    }
 
    /* Print the latest converted result of the channels as pointed by
       Demo_ResultPtr
    */
    // print_f("\n ADC Conversion Results (Raw Value): \n");
    // print_f("AN0) : %4x\n", *(Demo_ResultPtr));
    // print_f("AN1) : %4x\n", *(Demo_ResultPtr + AdcHWGroupNoSamples));
    // print_f("AN2) : %4x\n", *(Demo_ResultPtr + 2*AdcHWGroupNoSamples));
    // print_f("AN3) : %4x\n", *(Demo_ResultPtr + 3*AdcHWGroupNoSamples));
    // print_f("AN4) : %4x\n", *(Demo_ResultPtr + 4*AdcHWGroupNoSamples));
    // print_f("AN5) : %4x\n", *(Demo_ResultPtr + 5*AdcHWGroupNoSamples));
    // print_f("AN6) : %4x\n", *(Demo_ResultPtr + 6*AdcHWGroupNoSamples));
    // print_f("AN7) : %4x\n", *(Demo_ResultPtr + 7*AdcHWGroupNoSamples));
 
 
    /* Check if the Group has implictly stopped and status is IDLE
     before Stop request
    */
    if( (Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_AN0)) != ADC_IDLE)
    {
      /* Stop the conversion which will reset the status and result buffer
         and notification is disabled
      */
      Adc_DisableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_AN0);
    }
    if( (Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_AN8)) != ADC_IDLE)
    {
      /* Stop the conversion which will reset the status and result buffer
         and notification is disabled
      */
      Adc_DisableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_AN8);
    }
    if( (Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_AN16)) != ADC_IDLE)
    {
      /* Stop the conversion which will reset the status and result buffer
         and notification is disabled
      */
      Adc_DisableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_AN16);
    }
  }
  else
  {
    //print_f("\nError in ADC_HW_GRP_RES buffer setup for AdcHWGroup");
  }
  return;
 
} /* Adc_HWGroupDemo */
#endif


#if 0
void DemoApp_Adc_Init(void)
{
  SRC_VADCG0SR0.U |= SRE_ENABLE;
  const Adc_ConfigType * ConfigPtr = NULL_PTR;
  ConfigPtr = &Adc_Config;
  Adc_Init(ConfigPtr);
  /* Wait till the StartUp calibration is over */
  while( (Adc_GetStartupCalStatus()) != E_OK)
  {}
}
 

Adc_ValueGroupType ADC_HW_GRP_RES[16];
void Adc_HWGroupDemo(void)
{
  Adc_StreamNumSampleType AdcHWGroupNoSamples;
  Std_ReturnType AdcBufferSetupStatus;
 
  /* Initialize ADC interrupt */
  IrqAdc_Init();
 
  /* Initialize ADC */
  DemoApp_Adc_Init();
 
  /* Buffer Marker value */
  ADC_HW_GRP_RES[0] = 0x00C8;
 
  /* Initialize the Result buffer for AdcHWGroup */
  AdcBufferSetupStatus = Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_2, ADC_HW_GRP_RES);
  
  if(AdcBufferSetupStatus == E_OK)
  {
    Demo_AdcNoSamp = 0;
 
    /* Initialize the no. of group samples (Streaming length)
       for AdcHWGroup as configured
    */
    AdcHWGroupNoSamples = (Adc_StreamNumSampleType)2;
 
    /* Start the AdcHWGroup group */
    Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_2);
 
 
    while(Demo_AdcNoSamp != AdcHWGroupNoSamples)
    {
      /* Get the pointer to last conversion result of Adc Group */
      Demo_AdcNoSamp = Adc_GetStreamLastPointer(AdcConf_AdcGroup_AdcGroup_2, &Demo_ResultPtr);
    }
 
    /* Print the latest converted result of the channels as pointed by
       Demo_ResultPtr
    */
    // print_f("\n ADC Conversion Results (Raw Value): \n");
    // print_f("AN0) : %4x\n", *(Demo_ResultPtr));
    // print_f("AN1) : %4x\n", *(Demo_ResultPtr + AdcHWGroupNoSamples));
    // print_f("AN2) : %4x\n", *(Demo_ResultPtr + 2*AdcHWGroupNoSamples));
    // print_f("AN3) : %4x\n", *(Demo_ResultPtr + 3*AdcHWGroupNoSamples));
    // print_f("AN4) : %4x\n", *(Demo_ResultPtr + 4*AdcHWGroupNoSamples));
    // print_f("AN5) : %4x\n", *(Demo_ResultPtr + 5*AdcHWGroupNoSamples));
    // print_f("AN6) : %4x\n", *(Demo_ResultPtr + 6*AdcHWGroupNoSamples));
    // print_f("AN7) : %4x\n", *(Demo_ResultPtr + 7*AdcHWGroupNoSamples));
 
 
    /* Check if the Group has implictly stopped and status is IDLE
     before Stop request
    */
    if( (Adc_GetGroupStatus(AdcHWGroup)) != ADC_IDLE)
    {
      /* Stop the conversion which will reset the status and result buffer
         and notification is disabled
      */
      Adc_DisableHardwareTrigger(AdcHWGroup);
    }
  }
  else
  {
    //print_f("\nError in ADC_HW_GRP_RES buffer setup for AdcHWGroup");
  }
  Adc_DeInit();
  return;
 
} /* Adc_HWGroupDemo */
#endif

#if 0
unsigned char ENABLE_PWM = 0;
ADC_RESULT_TYPE ADC_RESULT_BUFFER;
float DutyCycle[3] = {0.2,0.5,0.9};

void Adc_Sync_Callback_Motor(void)
{
	if(ENABLE_PWM)
		PWM_Update(DutyCycle);
	else
		PWM_Disable();
	ADC_GetResult();
}

void ADC_Init(void)
{
	Adc_Init(&Adc_Config);
	//Adc_TriggerStartupCal();
	IrqAdc_Init();
	SRC_VADC_G0_SR0.B.SRE = 1U;
	Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_AN0, &(ADC_RESULT_BUFFER.SyncChannel.ADC_I_U));
	Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_AN0);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_AN0);

}

void ADC_GetResult(void)
{
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_AN0);
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_AN8);
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_AN16);
/* 	ADC_RESULT_BUFFER.ScanChannel.ADC_I_HV1 = EVADC_G0_RES2.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_V_REF = EVADC_G3_RES0.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_V_BATT = EVADC_G3_RES1.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_V_SUPPLY = EVADC_G8_RES0.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_I_HV2 = EVADC_G8_RES1.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_V_12V = EVADC_G8_RES2.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_V_C = EVADC_G8_RES3.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_W_MOS_TEMP = EVADC_G8_RES4.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_35584_TEMP1 = EVADC_G8_RES5.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_MODE_REG = EVADC_G8_RES6.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_35584_TEMP2 = EVADC_G8_RES7.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_V_MOS_TEMP = EVADC_G8_RES8.B.RESULT;
	ADC_RESULT_BUFFER.ScanChannel.ADC_U_MOS_TEMP = EVADC_G8_RES9.B.RESULT; */
}

#endif

#endif
