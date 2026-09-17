/*
 * Cdd_TLF35584.c
 *
 *  Created on: 2019-10-25
 *      Author: V22309
 */

#include "Cdd_Tlf35584.h"
#include "Dio.h"
#include "string.h"
/********************************************************************************************
**                     Private  Variable Definitions                                       **
********************************************************************************************/
#define CDD_TLF_35584_START_DATA
#include "Cdd_Memmap.h"

st_Tlf35584_Buff SwBuff;
const uint8 fwdResp[16][4]  = {{0xFF,0x0F,0xF0,0x00},\
		{0xB0,0x40,0xBF,0x4F},\
		{0xE9,0x19,0xE6,0x16},\
		{0xA6,0x56,0xA9,0x59},\
		{0x75,0x85,0x7A,0x8A},\
		{0x3A,0xCA,0x35,0xC5},\
		{0x63,0x93,0x6C,0x9C},\
		{0x2C,0xDC,0x23,0xD3},\
		{0xD2,0x22,0xDD,0x2D},\
		{0x9D,0x6D,0x92,0x62},\
		{0xC4,0x34,0xCB,0x3B},\
		{0x8B,0x7B,0x84,0x74},\
		{0x58,0xA8,0x57,0xA7},\
		{0x17,0xE7,0x18,0xE8},\
		{0x4E,0xBE,0x41,0xB1},\
		{0x01,0xF1,0x0E,0xFE}};



#define CDD_TLF_35584_STOP_DATA
#include "Cdd_Memmap.h"



#define CDD_35584_START_CODE
#include "Cdd_Memmap.h"

/********************************************************************************************
**                     Private Function                                                    **
********************************************************************************************/
static void Tlf35584_Unlock_Register(void);
static void Tlf35584_Lock_Register(void);
static uint16 Cmd_Pack(CmdType type,uint8 RegAddr,uint8 Data);
static boolean Cmd_ParityVerify(uint16 Cmd);
static uint16 Cmd_ParityAdd(uint16 Cmd);
static uint8 Cmd_Unpack(uint16 Cmd);
static void Tlf35584_Setting_WatchDog(void);
static void Tlf35584_Disable_WatchDog(void);
static void Tlf35584_Setting_ErrPinMonitor(void);
static void Tlf35584_Disable_ErrPinMonitor(void);
static void Tlf35584_DevStsRefresh(void);
static void Tlf35584_FaultStsCheck(void);
static void Tlf35584_CtrlStsRefresh(void);
static void Tlf35584_WdgTrigger(void);
static void Tlf35584_ClearFaultFlag(void);
static void Tlf35584_Setting_WakeTimer(void);
static void Tlf35584_StateFlowCtrl(void);
static void Tlf35584_ABIST(void);
static void Tlf35584_WAKE_To_SLEEP(void);
static void Tlf35584_WAKE_To_STANDBY(void);
static void Tlf35584_WAKE_To_NORMAL(void);
static void Tlf35584_NORMAL_To_STANDBY(void);
static void Tlf35584_NORMAL_To_SLEEP(void);
static void Tlf35584_SLEEP_To_WAKE(void);
static void Tlf35584_INT_To_NORMAL(void);
static void Tlf35584_INT_RunFunction(void);
static void Tlf35584_NORMAL_RunFunction(void);
static void Tlf35584_STANDBY_RunFunction(void);
static void Tlf35584_SLEEP_RunFunction(void);
static void Tlf35584_WAKE_RunFunction(void);
static void Tlf35584_SetStandbyQst(void);

void Cdd_WaitforUs(uint32 TimeUs)
{
	int i;
	for(i=0;i<1000;i++)
		for(TimeUs=0;TimeUs<1000;TimeUs++);
}

/********************************************************************************************
**                     Initiate TLF35584                                                   **
********************************************************************************************/
void Tlf35584_Init(void)
{
	/*Set Buffer*/
	memset(&SwBuff,0,sizeof(SwBuff));

	/*Enter Debug Mode*/
	Tlf35584_SetMPSPinLevelHigh();

	/*Set Step Down Frequency*/
#if STEP_DOWN_FRE_LOW_QUENCY == 0x1
	Tlf35584_SetFREPinLevelHigh();
#else
	Tlf35584_SetFREPinLevelLow();
#endif

	/*Spi Init*/
	Tlf35584_SPI_Init();

	/*Self Test*/
	Tlf35584_ABIST();

	/*Disable Monitor*/
	Tlf35584_Unlock_Register();
	Tlf35584_Disable_WatchDog();
	Tlf35584_Disable_ErrPinMonitor();
	Tlf35584_Lock_Register();

	/*Enable Standby Qst and wakeup Timer*/
	Tlf35584_Unlock_Register();
	Tlf35584_SetStandbyQst();
	Tlf35584_Setting_WakeTimer();
	Tlf35584_Lock_Register();

	/*Clear Fault Flag*/
	Tlf35584_ClearFaultFlag();

	/*Set Initial Flag*/
	SwBuff.ctrlExtSts.initialFinished = TRUE;
	SwBuff.ctrlExtSts.DebugMode = TRUE;
}

/********************************************************************************************
**                     Period Run TLF35584,must Invoke in 5ms Task                         **
********************************************************************************************/
void Tlf35584_Run(void)
{
	if(SwBuff.ctrlExtSts.DebugMode == TRUE)
	{
		/*Exit Debug Mode*/
		Tlf35584_SetMPSPinLevelLow();
		SwBuff.ctrlExtSts.DebugMode = FALSE;
	}
	if(SwBuff.ctrlExtSts.initialFinished == TRUE)
	{
		Tlf35584_DevStsRefresh();
		Tlf35584_CtrlStsRefresh();
		Tlf35584_StateFlowCtrl();
		Tlf35584_WdgTrigger();
		Tlf35584_FaultStsCheck();
	}
}

/********************************************************************************************
**                     TLF35584 Error Hook,Invoked in Call Back of 35584 Interrupt         **
********************************************************************************************/
void Tlf35584_ErrHook(void)
{
	/*Check Fault Reason*/
    uint8 intFlag = SwBuff.devIntSts.intFlag;
    intFlag = intFlag&IF_FAULT_MASK;
	if(intFlag != 0)
	{
       SwBuff.ctrlExtSts.fltMtrx.HwErr |= intFlag;
		/*Clear Fault Flag*/
       Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,IF,intFlag));
	}

	/*Used for Test*/
	SwBuff.ctrlExtSts.errCnt++;
}

/********************************************************************************************
**                     TLF35584 Set StateFlow Mode                                         **
********************************************************************************************/
void Tlf35584_SetMode(en_DevState ModeReq)
{
	SwBuff.ctrlExtSts.modeReq = ModeReq;
}


/********************************************************************************************
**                     TLF35584 Get StateFlow Mode                                         **
********************************************************************************************/
en_DevState Tlf35584_GetMode(void)
{
	return SwBuff.ctrlExtSts.devSts;
}

/********************************************************************************************
**                     TLF35584 State Refresh                                              **
********************************************************************************************/
uint16 Tlf35584_GetError(void)
{
#if 0
	return ((SwBuff.ctrlExtSts.fltMtrx.SwErr<<8)+SwBuff.ctrlExtSts.fltMtrx.HwErr);
#else
	SwBuff.ctrlExtSts.errSts.B.Abist = (SwBuff.devIntSts.sysFail>>6)&0x1;
	SwBuff.ctrlExtSts.errSts.B.DoubleBitError = (SwBuff.devIntSts.sysFail&0x1)|(SwBuff.devIntSts.sysSF&0x1);
	SwBuff.ctrlExtSts.errSts.B.ErrorPinMonitor = (SwBuff.devIntSts.initErr>>5)&0x1;
	SwBuff.ctrlExtSts.errSts.B.MonitorBlock = (SwBuff.devIntSts.intFlag>>3)&0x1;
	SwBuff.ctrlExtSts.errSts.B.OverCurrent = (SwBuff.devIntSts.sysSF>>4)&0x1;
	SwBuff.ctrlExtSts.errSts.B.OverTempShutDown = (SwBuff.devIntSts.intFlag>>5)&0x1;
	SwBuff.ctrlExtSts.errSts.B.OverTempWarn =(SwBuff.devIntSts.intFlag>>4)&0x1;
	SwBuff.ctrlExtSts.errSts.B.SpiBlock = (SwBuff.devIntSts.intFlag>>2)>>1;
	SwBuff.ctrlExtSts.errSts.B.StateTransition = (SwBuff.devIntSts.sysSF>>4)&0x1;
	SwBuff.ctrlExtSts.errSts.B.WatchDogError = ((SwBuff.devIntSts.initErr>>3)&0x1)|((SwBuff.devIntSts.initErr>>4)&0x1);

	return SwBuff.ctrlExtSts.errSts.U;
#endif
}

/********************************************************************************************
**                     Tlf35584_GetPowerSts                                                **
********************************************************************************************/
uint8 Tlf35584_GetPowerSts(void)
{
	return SwBuff.ctrlExtSts.powerSts.U;
}

/********************************************************************************************
**                     Tlf35584_GetWindowWdgSts                                            **
********************************************************************************************/
uint8 Tlf35584_GetWindowWdgSts(void)
{
	return (uint8)((WINDOW_WATCHDOG_ENABLE)+((1-WATCH_DOG_SLOW_MODE)<<1)+((SwBuff.devIntSts.initErr>>3)&0x1)+(((WWDCFG0_DEFAULT+WWDCFG1_DEFAULT+2)*50)<<4));
}

/********************************************************************************************
**                     Tlf35584_GetFunctionWdgSts                                          **
********************************************************************************************/
uint8 Tlf35584_GetFunctionWdgSts(void)
{
	return (uint8)((FUNCTTION_WATCHDOG_ENABLE)+((1-WATCH_DOG_SLOW_MODE)<<1)+((SwBuff.devIntSts.initErr>>4)&0x1)+(((FWDCFG_DEFAULT+1)*50)<<4));
}

/********************************************************************************************
**                     Tlf35584_GetWakeTimerSts                                            **
********************************************************************************************/
void Tlf35584_GetWakeTimerSts(uint8 *CtrlSts,uint32 *CntSts)
{
	*CtrlSts = WAKE_TIMER_ENABLE + (1<<(WAKE_TIMER_MS+1));
	*CntSts = WAKE_TIMER_COUNT;
}

/********************************************************************************************
**                     TLF35584 State Refresh                                              **
********************************************************************************************/
static void Tlf35584_CtrlStsRefresh(void)
{
	/*Update WatchDog Status*/
	SwBuff.ctrlExtSts.wdSts.wwdCw = ((SwBuff.devIntSts.rwwdCfg0&0x1f)+1)*WD_DEFAULT_CYCLE_MS/MODULE_CTRL_PERIOD_MS;
	SwBuff.ctrlExtSts.wdSts.wwdOw = ((SwBuff.devIntSts.rwwdCfg1&0x1f)+1)*WD_DEFAULT_CYCLE_MS/MODULE_CTRL_PERIOD_MS;
	SwBuff.ctrlExtSts.wdSts.fwdOvThrld = (((SwBuff.devIntSts.rfwdCfg&0x1f)+1))*WD_DEFAULT_CYCLE_MS/MODULE_CTRL_PERIOD_MS-4;

	/*Update Current Mode*/
	SwBuff.ctrlExtSts.devSts = SwBuff.devIntSts.devStat&0x7U;

	/*Update Power Source Status*/
	SwBuff.ctrlExtSts.powerSts.B.Qt2    = (SwBuff.devIntSts.devStat>>7)&0x1;
	SwBuff.ctrlExtSts.powerSts.B.Qt1    = (SwBuff.devIntSts.devStat>>6)&0x1;
	SwBuff.ctrlExtSts.powerSts.B.Qco    = (SwBuff.devIntSts.devStat>>5)&0x1;
	SwBuff.ctrlExtSts.powerSts.B.StdLDO = (SwBuff.devIntSts.devStat>>4)&0x1;
	SwBuff.ctrlExtSts.powerSts.B.Qvr    = (SwBuff.devIntSts.devStat>>3)&0x1;
	SwBuff.ctrlExtSts.powerSts.B.Quc    = 1;   /*Always Enable*/

}

/********************************************************************************************
**                     TLF35584 Self Check                                                 **
********************************************************************************************/
static void Tlf35584_FaultStsCheck(void)
{
	/*Auto Clear Hw Fault*/
	if(SwBuff.ctrlExtSts.fltMtrx.HwErr!=0)
	{
		SwBuff.ctrlExtSts.fltMtrx.ErrAutoClrCnt++;
		if(SwBuff.ctrlExtSts.fltMtrx.ErrAutoClrCnt > FAULT_AUTO_CLEAR_CYCLE)
		{
			SwBuff.ctrlExtSts.fltMtrx.ErrAutoClrCnt = 0;
			SwBuff.ctrlExtSts.fltMtrx.HwErr = 0;
		}
	}
}

/********************************************************************************************
**                     Tlf35584 Clear Fault Flag                                           **
********************************************************************************************/
static void Tlf35584_ClearFaultFlag(void)
{
	/*Clear Hardware Fault*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,SYSFAIL ,0xC7));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,INITERR ,0xFC));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,IF      ,0x7F));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,SYSSF   ,0x3F));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WKSF    ,0x1F));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,SPISF   ,0x1F));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,MONSF0  ,0xFF));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,MONSF1  ,0xFF));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,MONSF2  ,0xFF));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,MONSF3  ,0xF1));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,OTFAIL  ,0x93));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,OTWRNSF ,0x37));

	/*Clear Software Fault*/
	SwBuff.ctrlExtSts.errCnt = 0;
}

/********************************************************************************************
**                     Tlf35584 Set Wake up Timer                                          **
********************************************************************************************/
static void Tlf35584_Setting_WakeTimer(void)
{
	/*set during SLEEP or STANDBY mode to transfer to INIT mode*/
	/*DEVFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCFG0,(WAKE_TIMER_ENABLE<<7)+(WAKE_TIMER_MS<<6)+8));
	/*WKTIMCFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WKTIMCFG0,(WAKE_TIMER_COUNT&0xff)));
	/*WKTIMCFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WKTIMCFG1,((WAKE_TIMER_COUNT>>8)&0xff)));
	/*WKTIMCFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WKTIMCFG2,(((WAKE_TIMER_COUNT>>16)&0xff))));
}

/********************************************************************************************
**                     Setting Window Watch Dog                                            **
********************************************************************************************/
static void Tlf35584_Setting_WatchDog(void)
{
	/*WDCFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WDCFG0,WDCFG0_DEFAULT));
	/*WWDCFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WWDCFG0,WWDCFG0_DEFAULT));
	/*WWDCFG1*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WWDCFG1,WWDCFG1_DEFAULT));
	/*FWDCFG*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,FWDCFG,FWDCFG_DEFAULT));
}

/********************************************************************************************
**                     Disable Window Watch Dog                                            **
********************************************************************************************/
static void Tlf35584_Disable_WatchDog(void)
{
	uint8 Data = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RWDCFG0,0)));
	/*WWDCFG0*/
	Data = Data&0xF7;	/*Clear WWDEN*/
	Data = Data&0xFB;	/*Clear FWDEN*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,WDCFG0,Data));
}


/********************************************************************************************
**                     Setting Error Pin Monitor                                           **
********************************************************************************************/
static void Tlf35584_Setting_ErrPinMonitor(void)
{
//	uint16 Cmd  = Cmd_Pack(ReadCmd,RSYSPCFG1,0);
//	uint8  Data = Cmd_Unpack(Tlf35584_SPI_Read(Cmd));
//	if((Data&0x08)==0)
//	{
//		/*Set ERREN*/
//		Data = Data|0x08;
//		Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,SYSPCFG1,Data));
//	}
}

/********************************************************************************************
**                     Disable Error Pin Monitor                                           **
********************************************************************************************/
static void Tlf35584_Disable_ErrPinMonitor(void)
{
	uint16 Cmd  = Cmd_Pack(ReadCmd,RSYSPCFG1,0);
	uint8  Data = Cmd_Unpack(Tlf35584_SPI_Read(Cmd));
	if(Data&0x08)
	{
		/*Clear ERREN*/
		Data = Data&0xF7;
		Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,SYSPCFG1,Data));
	}
}

/********************************************************************************************
**                     State Flow Control                                                  **
********************************************************************************************/
static void Tlf35584_StateFlowCtrl(void)
{
	switch(SwBuff.ctrlExtSts.devSts)
	{
	case 	Init:
		Tlf35584_INT_RunFunction();
		if(SwBuff.ctrlExtSts.modeReq == Normal)
		{
			Tlf35584_INT_To_NORMAL();
		}
		break;
	case	Normal:
		Tlf35584_NORMAL_RunFunction();
		if(SwBuff.ctrlExtSts.modeReq == Sleep)
		{
			Tlf35584_NORMAL_To_SLEEP();
		}
		else if(SwBuff.ctrlExtSts.modeReq == Standby)
		{
			Tlf35584_NORMAL_To_STANDBY();
		}
		break;
	case	Sleep:
		Tlf35584_SLEEP_RunFunction();
		if(SwBuff.ctrlExtSts.modeReq == Wake)
		{
			Tlf35584_SLEEP_To_WAKE();
		}
		break;
	case	Standby:
		Tlf35584_STANDBY_RunFunction();
		break;
	case	Wake:
		Tlf35584_WAKE_RunFunction();
		if(SwBuff.ctrlExtSts.modeReq == Standby)
		{
			Tlf35584_WAKE_To_STANDBY();
		}
		else if(SwBuff.ctrlExtSts.modeReq == Sleep)
		{
			Tlf35584_WAKE_To_SLEEP();
		}
		else if(SwBuff.ctrlExtSts.modeReq == Normal)
		{
			Tlf35584_WAKE_To_NORMAL();
		}
		break;
	default:
		break;
	}
}

/********************************************************************************************
**                     Tlf35584_WAKE_To_SLEEP                                              **
********************************************************************************************/
static void Tlf35584_WAKE_To_SLEEP(void)
{
	/*Disable Watch Dog and Err Pin*/
	Tlf35584_Unlock_Register();
	Tlf35584_Disable_WatchDog();
	Tlf35584_Disable_ErrPinMonitor();
	Tlf35584_Lock_Register();

	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = (SLEEP_QT2_ENABLE<<7)+(SLEEP_QT1_ENABLE<<6)+
			(SLEEP_COM_LDO_ENABLE<<5)+(SLEEP_REF_LDO_ENABLE<<3)+Sleep;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_WAKE_To_STANDBY                                            **
********************************************************************************************/
static void Tlf35584_WAKE_To_STANDBY(void)
{
	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = Standby;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_WAKE_To_NORMAL                                             **
********************************************************************************************/
static void Tlf35584_WAKE_To_NORMAL(void)
{
    /*Enable Monitor*/
	Tlf35584_Unlock_Register();
	Tlf35584_Setting_WatchDog();
	Tlf35584_Setting_ErrPinMonitor();
	Tlf35584_Lock_Register();

	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = (NORMAL_QT2_ENABLE<<7)+(NORMAL_QT1_ENABLE<<6)+
			(NORMAL_COM_LDO_ENABLE<<5)+(NORMAL_REF_LDO_ENABLE<<3)+Normal;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_NORMAL_To_STANDBY                                          **
********************************************************************************************/
static void Tlf35584_NORMAL_To_STANDBY(void)
{
	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = Standby;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_NORMAL_To_SLEEP                                            **
********************************************************************************************/
static void Tlf35584_NORMAL_To_SLEEP(void)
{
	/*Disable Watch Dog and Err Pin*/
	Tlf35584_Unlock_Register();
	Tlf35584_Disable_WatchDog();
	Tlf35584_Disable_ErrPinMonitor();
	Tlf35584_Lock_Register();

	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = (SLEEP_QT2_ENABLE<<7)+(SLEEP_QT1_ENABLE<<6)+
			(SLEEP_COM_LDO_ENABLE<<5)+(SLEEP_REF_LDO_ENABLE<<3)+Sleep;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_SLEEP_To_WAKE                                              **
********************************************************************************************/
static void Tlf35584_SLEEP_To_WAKE(void)
{
	/*Disable Watch Dog and Err Pin*/
	Tlf35584_Unlock_Register();
	Tlf35584_Disable_WatchDog();
	Tlf35584_Disable_ErrPinMonitor();
	Tlf35584_Lock_Register();

	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = (WAKE_QT2_ENABLE<<7)+(WAKE_QT1_ENABLE<<6)+
			(WAKE_COM_LDO_ENABLE<<5)+(WAKE_REF_LDO_ENABLE<<3)+Wake;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_INT_To_NORMAL                                              **
********************************************************************************************/
static void Tlf35584_INT_To_NORMAL(void)
{
    /*Enable Monitor*/
	Tlf35584_Unlock_Register();
	Tlf35584_Setting_WatchDog();
	Tlf35584_Setting_ErrPinMonitor();
	Tlf35584_Lock_Register();

	/*Set TRK2EN,TRK1EN,COMEN,VREFEN,Enter Normal Mode*/
	uint8 Cmd = (NORMAL_QT2_ENABLE<<7)+(NORMAL_QT1_ENABLE<<6)+
			(NORMAL_COM_LDO_ENABLE<<5)+(NORMAL_REF_LDO_ENABLE<<3)+Normal;
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRL,Cmd));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,DEVCTRLN,~Cmd));
}

/********************************************************************************************
**                     Tlf35584_INT_RunFunction                                            **
********************************************************************************************/
static void Tlf35584_INT_RunFunction(void)
{
	/*Set Normal Mode*/
	Tlf35584_SetMode(Normal);
}

/********************************************************************************************
**                     Tlf35584_NORMAL_RunFunction                                         **
********************************************************************************************/
static void Tlf35584_NORMAL_RunFunction(void)
{

}

/********************************************************************************************
**                     Tlf35584_STANDBY_RunFunction                                        **
********************************************************************************************/
static void Tlf35584_STANDBY_RunFunction(void)
{

}

/********************************************************************************************
**                     Tlf35584_SLEEP_RunFunction                                          **
********************************************************************************************/
static void Tlf35584_SLEEP_RunFunction(void)
{

}

/********************************************************************************************
**                     Tlf35584_WAKE_RunFunction                                           **
********************************************************************************************/
static void Tlf35584_WAKE_RunFunction(void)
{
	/*Set Normal Mode*/
	Tlf35584_SetMode(Normal);
}

/********************************************************************************************
**                     Refresh Tlf35584                                                    **
********************************************************************************************/
static void Tlf35584_DevStsRefresh(void)
{
#if REGISTER_DEBUG_MODE_ENABLE == 0x1
	SwBuff.devIntSts.wkSF          = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,WKSF           ,0x0)));
	SwBuff.devIntSts.protStat      = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,PROTSTAT       ,0x0)));
	SwBuff.devIntSts.rwdCfg1       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RWDCFG1        ,0x0)));
	SwBuff.devIntSts.devCfg0       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,DEVCFG0        ,0x0)));
	SwBuff.devIntSts.devCfg1       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,DEVCFG1        ,0x0)));
	SwBuff.devIntSts.devCfg2       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,DEVCFG2        ,0x0)));
	SwBuff.devIntSts.rsyspCfg0     = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RSYSPCFG0      ,0x0)));
	SwBuff.devIntSts.rsyspCfg1     = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RSYSPCFG1      ,0x0)));
	SwBuff.devIntSts.monSf0        = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,MONSF0         ,0x0)));
	SwBuff.devIntSts.monSf1        = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,MONSF1         ,0x0)));
	SwBuff.devIntSts.monSf2        = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,MONSF2         ,0x0)));
	SwBuff.devIntSts.monSf3        = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,MONSF3         ,0x0)));
	SwBuff.devIntSts.otFail        = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,OTFAIL         ,0x0)));
	SwBuff.devIntSts.otWrnSf       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,OTWRNSF        ,0x0)));
	SwBuff.devIntSts.vMonStat      = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,VMONSTAT       ,0x0)));
	SwBuff.devIntSts.gtm           = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,GTM            ,0x0)));
	SwBuff.devIntSts.fwdStat1      = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,FWDSTAT1       ,0x0)));
#endif
	SwBuff.devIntSts.initErr       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,INITERR        ,0x0)));
	SwBuff.devIntSts.intFlag       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,IF             ,0x0)));
	SwBuff.devIntSts.spiSF         = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,SPISF          ,0x0)));
	SwBuff.devIntSts.sysFail       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,SYSFAIL        ,0x0)));
	SwBuff.devIntSts.sysSF         = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,SYSSF          ,0x0)));
	SwBuff.devIntSts.rwdCfg0       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RWDCFG0        ,0x0)));
	SwBuff.devIntSts.rfwdCfg       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RFWDCFG        ,0x0)));
	SwBuff.devIntSts.rwwdCfg0      = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RWWDCFG0       ,0x0)));
	SwBuff.devIntSts.rwwdCfg1      = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,RWWDCFG1       ,0x0)));
	SwBuff.devIntSts.devStat       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,DEVSTAT        ,0x0)));
	SwBuff.devIntSts.wwdStat       = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,WWDSTAT        ,0x0)));
	SwBuff.devIntSts.fwdStat0      = Cmd_Unpack(Tlf35584_SPI_Read(Cmd_Pack(ReadCmd,FWDSTAT0       ,0x0)));
}

/********************************************************************************************
**                     Self Test Operation                                                 **
********************************************************************************************/
static void Tlf35584_ABIST(void)
{

}

/********************************************************************************************
**                     Tlf35584_SetStandbyQst                                              **
********************************************************************************************/
static void Tlf35584_SetStandbyQst(void)
{
	/*SYSPCFG0*/
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,SYSPCFG0,STANDBY_QST_ENABLE));
}

/********************************************************************************************
**                     Watch Dog Trigger                                                   **
********************************************************************************************/
static void Tlf35584_WdgTrigger(void)
{
	/*Feed the window watch dog*/
	uint16 wwdcw = SwBuff.ctrlExtSts.wdSts.wwdCw;
	uint16 wwdow = SwBuff.ctrlExtSts.wdSts.wwdOw;
	if(SwBuff.devIntSts.rwdCfg0&WINDOW_WATCHDOG_ENABLE_MASK)
	{
		if(SwBuff.ctrlExtSts.wdSts.wwdTrigCnt <= 0)
		{
			Tlf35584_SetWDIPinLevelLow();
			SwBuff.ctrlExtSts.wdSts.wwdTrigCnt = wwdcw+(wwdow>>1);
		}
		else
		{
			SwBuff.ctrlExtSts.wdSts.wwdTrigCnt--;
			if(SwBuff.ctrlExtSts.wdSts.wwdTrigCnt == (wwdcw>>1)+(wwdow>>1))
			{
				Tlf35584_SetWDIPinLevelHigh();
			}
		}
	}
	/*Feed the functional watch dog*/
	if(SwBuff.devIntSts.rwdCfg0&FUNCTION_WATCHDOG_ENABLE_MASK)
	{
		uint16 TrigStep = SwBuff.ctrlExtSts.wdSts.fwdOvThrld>>2;
		uint16 TrigCnt  = SwBuff.ctrlExtSts.wdSts.fwdTrigCnt++;
		uint8 fwdrspc   = (SwBuff.devIntSts.fwdStat0>>4)&0x3;
		uint8 fwdquest  = SwBuff.devIntSts.fwdStat0&0xf;
		uint8 fwdres = 0;
		if(TrigCnt == TrigStep||TrigCnt == TrigStep*2||TrigCnt == TrigStep*3||TrigCnt == TrigStep*4)
		{
			fwdres = fwdResp[fwdquest][3-fwdrspc];
			if(fwdrspc == 0)
			{
				SwBuff.ctrlExtSts.wdSts.fwdTrigCnt = 0;
				Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,FWDRSPSYNC,fwdres));
			}
			else
			{
				Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,FWDRSP,fwdres));
			}
		}
	}
}

/********************************************************************************************
**                     Unlock TLF35584 to set Protected Register                           **
********************************************************************************************/
static void Tlf35584_Unlock_Register(void)
{
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0xAB));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0xAB));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0xEF));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0x56));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0x12));
}

/********************************************************************************************
**                     Lock TLF35584 to Protect Register                                   **
********************************************************************************************/
static void Tlf35584_Lock_Register(void)
{
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0xDF));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0x34));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0xBE));
	Tlf35584_SPI_Write(Cmd_Pack(WriteCmd,PROTCFG,0xCA));
	Cdd_WaitforUs(100);
}

/********************************************************************************************
**                     Pack the Command                                                    **
********************************************************************************************/
static uint16 Cmd_Pack(CmdType type,uint8 RegAddr,uint8 Data)
{
	uint16 Cmd = (((uint8)type)*0x8000)+((RegAddr&0x3f)<<9)+(Data<<1);
	Cmd = Cmd_ParityAdd(Cmd);
	return Cmd;
}

/********************************************************************************************
**                     Unpack the Command                                                    **
********************************************************************************************/
static uint8 Cmd_Unpack(uint16 Cmd)
{
	uint8 Data = 0;
	if(Cmd_ParityVerify(Cmd) == TRUE)
	{
		Data = ((Cmd>>1)&0xff);
	}
	return Data;
}

/********************************************************************************************
**                     Verify the Command with Parity                                      **
********************************************************************************************/
static boolean Cmd_ParityVerify(uint16 Cmd)
{
	uint8 i = 0;
	uint8 Sum = 0;
	for(i=0;i<=15;i++)
	{
		Sum = Sum + ((Cmd>>i)&0x1);
	}
	return (!(Sum&0x1));
}

/********************************************************************************************
**                     Pack the Command with Parity                                        **
********************************************************************************************/
static uint16 Cmd_ParityAdd(uint16 Cmd)
{
	if(Cmd_ParityVerify(Cmd) == FALSE)
	{
		Cmd = Cmd|0x1;
	}
	return Cmd;
}



#define CDD_35584_STOP_CODE
#include "Cdd_Memmap.h"
