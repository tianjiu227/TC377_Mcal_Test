/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Cpu0_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2016-08-17                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Cpu0 Main startup file for TC375 Bootloader                **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"

/* MCAL Includes */
#include "Mcu.h"
#include "Spi.h"
//#include "Gpt.h"
#include "Irq.h"
#include "IfxSrc_reg.h"
#include "Port.h"
#include "Dio.h"
#include "Can_17_McmCan.h"
/* User Includes */
#include "User_Adc.h"
#include "Delay.h"
#include "User_Pwm.h"
#include "User_Can.h"
#include "w25qxx.h"
#include "Bsw_Pwm.h"
#include "Bsw_Adc.h"
//#include "User_Fls.h"
//#include "User_FlsLoader.h"



/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef enum
{
	APP_NO_REQ = 0,
	APP_TO_BOOT_NO_RESP = 2,
	APP_TO_BOOT_DO_RESP = 3,
	APP_TO_BOOT_MAX = 0xFF
}APP2FBL_ReprogReq;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
volatile Mcu_ClockType ClockID = 0;
Mcu_PllStatusType Mcu_GetPllStatusRetVal = MCU_PLL_STATUS_UNDEFINED;
Std_ReturnType InitClockRetVal = E_NOT_OK;
Std_ReturnType DistributePllClockRetVal = E_NOT_OK;

/* GPT timer variables for bootloader */
volatile uint32 Gpt_1msTick = 0;
volatile uint8 Gpt_10msFlag = FALSE;
uint32 GetTimeElapsed = 0;
uint32 GetTimeRemaining = 0;


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/

#if 0
/*
 * Bootloader system initialization
 * Initializes MCAL modules required for bootloader operation
 */
uint32 Test_FlsLoaderPF_Address = 0x801E0000;
uint8  Test_FlsLoader_WriteBuffer0[2048];
uint8 ProductId;
extern void FLASH_HAL_RegisterFlashAPI_Init(void);
void Bootloader_SystemInit(void)
{
    /* Initialize MCU and clocks */
    Mcu_Init(&Mcu_Config);
    InitClockRetVal = Mcu_InitClock(ClockID);
    Mcu_GetPllStatusRetVal = Mcu_GetPllStatus();

    while (MCU_PLL_UNLOCKED == Mcu_GetPllStatus())
    {
         /* wait for PLL locked */
    }

    DistributePllClockRetVal = Mcu_DistributePllClock();

    /* Initialize IRQ modules */
    IrqGtm_Init();
    IrqGpt_Init();

    /* Enable module Interrupts using SRE Bit */
    SRC_GTMTOM00.B.SRE = 1;

    /* GPT module Initialization for 1ms tick */
    Gpt_Init(&Gpt_Config);
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_GTM);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_GTM, 6250);

#if 0
    /* GPT12 Irq for additional timing */
    SRC_GPT120T3.B.SRE = 1;

    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_GPT12);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_GPT12, 50000);
    Mcu_17_Gpt12_TimerStart(MCU_GPT12_TIMER3);
#endif

    /* Initialize Port module */
    Port_Init(&Port_Config);

    /* Initialize CAN module for UDS communication */
    CAN0_Module_Init();

    /* Initialize ADC for ECU position detection */
    /* Adc_HWGroupDemo(); - optional */

    /* Initialize Flash Loader - required before any Flash operations */
    FlsLoader_Init(NULL_PTR);

	FLASH_HAL_RegisterFlashAPI_Init();

	/* Initialize SBC SPI Module */
	Spi_Init(&Spi_Config);

#if 0
	uint32 Index = 0;

	for(Index = 0; Index < 2048; Index++)
	{
		Test_FlsLoader_WriteBuffer0[Index] = 0xCC;
	}

	FlsLoader_Erase((uint32)Test_FlsLoaderPF_Address, 1);

	FlsLoader_Write((uint32)Test_FlsLoaderPF_Address, 2048, &Test_FlsLoader_WriteBuffer0[0]);
#endif

	//IoHwAb_Init();

	//CDD_SBC_init();

#if 1
	/* 1. 鐠囪褰囬獮鍫曠崣鐠囷拷 SBC 閼侯垳澧栭惃鍕獓閸濓拷 ID */
	CDD_SBC_ReadProductId(&ProductId);

	/* 2. 绾喕绻歋BC鏉╂稑鍙哊ormal濡�崇础 */
	CDD_SBC_ModeChange(Normal_Mode);

	/* 3. 閸忔娊妫碫CC2 */
	CDD_SBC_VCC2_Ctrl(VCC2_OFF);

    /* 4. 閻妫悪妤�鍨垫慨瀣鎼村繐鍨� */
	CDD_SBC_WD_Init(WD_TYPE_TIMEOUT, WD_PERIOD_200MS);
#endif

	//FlsLoader_Erase((uint32)Test_FlsLoaderPF_Address, 1);

	//FlsLoader_Write((uint32)Test_FlsLoaderPF_Address, 2048, &Test_FlsLoader_WriteBuffer0[0]);

}
#endif

void core0_main (void)
{
    ENABLE();

    /* Initialize MCU and clocks */
	Mcu_Init(&Mcu_Config);
	InitClockRetVal = Mcu_InitClock(ClockID);
	Mcu_GetPllStatusRetVal = Mcu_GetPllStatus();

	while (MCU_PLL_UNLOCKED == Mcu_GetPllStatus())
	{
		 /* wait for PLL locked */
	}

	DistributePllClockRetVal = Mcu_DistributePllClock();




	 /* Initialize IRQ modules */
	IrqGtm_Init();
	IrqGpt_Init();

	/* Enable module Interrupts using SRE Bit */
	SRC_GTMTOM00.B.SRE = 1;
#if 0
	/* GPT module Initialization for 1ms tick */
	Gpt_Init(&Gpt_Config);
	Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_GTM);
	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_GTM, 6250);

#if 1
	/* GPT12 Irq for additional timing */
	SRC_GPT120T3.B.SRE = 1;

	Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_GPT12);
	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_GPT12, 50000);
	Mcu_17_Gpt12_TimerStart(MCU_GPT12_TIMER3);
#endif
#endif


	/* Initialize Port module */
	Port_Init(&Port_Config);

	/* open led */
	//Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_HIGH);
	

	//DemoApp_Adc_Init();
	/* close led */
	//Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_LOW);

	//Can_DemoFunction();

	// PWM_DemoFunction();
	PWM_Init();
	ADC_All_Init();
	
    /* Should never reach here */
    while (1)
    {

		// Can_DemoFunction();
		//  Spi_DemoFunction_HW_CS();
		//  ADC_Init();
		//Dio_WriteChannel(DioConf_DioChannel_DioChannel_GD_ENA1_P00_0, STD_HIGH);
		// PWM_DemoFunction();
		// Adc_HWGroupDemo();
	
#if 0
	    /* close led */
	    Dio_WriteChannel(DioConf_DioChannel_DioChannel_P33_10, STD_HIGH);
	    delay_ms(500);
	    /* open led */
	    Dio_WriteChannel(DioConf_DioChannel_DioChannel_P33_10, STD_LOW);
	    delay_ms(500);
#endif
    }
}

/*
 * GPT 1ms timer interrupt callback
 * Called every 1ms from GPT timer interrupt
 */
void Gpt_1ms(void)
{
    Gpt_1msTick++;
}

/*
 * GPT12 timer interrupt callback (2ms)
 */
uint32 Gpt_2msTick = 0;
void Gpt_2ms(void)
{
    Gpt_2msTick++;
}

