/*
 * Tlf35584.h
 *
 *  Created on: 2019-10-25
 *      Author: V22309
 */

#ifndef TLF35584_H_
#define TLF35584_H_

/*****************************************Include Files***************************************/
#include "Cdd_Tlf35584_Cfg.h"
#include "Cdd_Tlf35584_llD.h"
/***************************************Global Variable Define********************************/
typedef enum CmdType
{
	ReadCmd = 0,
	WriteCmd = 1
}CmdType;

/**************************************Global Macor Define************************************/
/*Register Address*/
#define DEVCFG0               (0x00U)       /*设备配置寄存器0*/
#define DEVCFG1               (0x01U)       /*设备配置寄存器1*/
#define DEVCFG2               (0x02U)       /*设备配置寄存器2*/
#define PROTCFG               (0x03U)       /*保护寄存器*/
#define SYSPCFG0              (0x04U)       /*保护系统配置寄存器0*/
#define SYSPCFG1              (0x05U)       /*保护系统配置寄存器1*/
#define WDCFG0                (0x06U)       /*看门狗配置寄存器0*/
#define WDCFG1                (0x07U)       /*看门狗配置寄存器1*/
#define FWDCFG                (0x08U)       /*功能看门狗配置寄存器*/
#define WWDCFG0               (0x09U)       /*保护窗看门狗配置寄存器0*/
#define WWDCFG1               (0x0AU)       /*保护窗看门狗配置寄存器1*/
#define RSYSPCFG0             (0x0BU)       /*系统配置状态寄存器0*/
#define RSYSPCFG1             (0x0CU)       /*系统配置状态寄存器1*/
#define RWDCFG0               (0x0DU)       /*只读看门狗配置寄存器0*/
#define RWDCFG1               (0x0EU)       /*只读看门狗配置寄存器1*/
#define RFWDCFG               (0x0FU)       /*功能看门狗配置寄存器*/
#define RWWDCFG0              (0x10U)       /*窗看门狗配置寄存器0*/
#define RWWDCFG1              (0x11U)       /*窗看门狗配置寄存器1*/
#define WKTIMCFG0             (0x12U)       /*唤醒定时器配置寄存器0*/
#define WKTIMCFG1             (0x13U)       /*唤醒定时器配置寄存器1*/
#define WKTIMCFG2             (0x14U)       /*唤醒定时器配置寄存器2*/
#define DEVCTRL               (0x15U)       /*设备控制寄存器*/
#define DEVCTRLN              (0x16U)       /*设备控制寄存器取反*/
#define WWDSCMD               (0x17U)       /*窗看门狗喂狗寄存器*/
#define FWDRSP                (0x18U)       /*功能看门狗响应寄存器*/
#define FWDRSPSYNC            (0x19U)       /*功能看门狗响应同步寄存器*/
#define SYSFAIL               (0x1AU)       /*故障状态标志寄存器*/
#define INITERR               (0x1BU)       /*初始故障标志寄存器*/
#define IF                    (0x1CU)       /*中断标志*/
#define SYSSF                 (0x1DU)       /*系统状态寄存器*/
#define WKSF                  (0x1EU)       /*唤醒状态寄存器*/
#define SPISF                 (0x1FU)       /*SPI状态寄存器*/
#define MONSF0                (0x20U)       /*监控寄存器0*/
#define MONSF1                (0x21U)       /*监控寄存器1*/
#define MONSF2                (0x22U)       /*监控寄存器2*/
#define MONSF3                (0x23U)       /*监控寄存器3*/
#define OTFAIL                (0x24U)       /*过温故障状态寄存器*/
#define OTWRNSF               (0x25U)       /*过温警告状态寄存器*/
#define VMONSTAT              (0X26U)       /*电压监控状态*/
#define DEVSTAT               (0x27U)       /*设备状态寄存器*/
#define PROTSTAT              (0x28U)       /*保护状态寄存器*/
#define WWDSTAT               (0x29U)       /*窗看门狗寄存器*/
#define FWDSTAT0              (0x2AU)       /*功能看门狗寄存器0*/
#define FWDSTAT1              (0x2BU)       /*功能看门狗寄存器1*/
#define ABIST_CTRL0           (0x2CU)       /*自检控制器0*/
#define ABIST_CTRL1           (0x2DU)       /*自检控制器1*/
#define ABIST_SELECT0         (0x2EU)       /*自检选择寄存器0*/
#define ABIST_SELECT1         (0x2FU)       /*自检选择寄存器1*/
#define ABIST_SELECT2         (0x30U)       /*自检选择寄存器2*/
#define GTM                   (0x3FU)       /*全局测试模式*/
#define BCK_FREQ_CHANGE       (0x31U)       /*Buck开管频率修改寄存器*/
#define BCK_FRE_SPREAD        (0x32U)       /*Buck开管频率传播*/
#define BCK_MAIN_CTRL         (0x33U)       /*Buck控制寄存器*/


#define FUNCTION_WATCHDOG_ENABLE_MASK      (0x04U)
#define WINDOW_WATCHDOG_ENABLE_MASK        (0x08U)
/***************************************Global Variable Define********************************/
typedef struct
{
	uint8 sysFail;
	uint8 initErr;
	uint8 intFlag;
	uint8 sysSF;
	uint8 wkSF;
	uint8 spiSF;
	uint8 protStat;
	uint8 rwdCfg0;
	uint8 rwdCfg1;
	uint8 rfwdCfg;
	uint8 rwwdCfg0;
	uint8 rwwdCfg1;
	uint8 devCfg0;
	uint8 devCfg1;
	uint8 devCfg2;
	uint8 rsyspCfg0;
	uint8 rsyspCfg1;
	uint8 monSf0;
	uint8 monSf1;
	uint8 monSf2;
	uint8 monSf3;
	uint8 otFail;
	uint8 otWrnSf;
	uint8 vMonStat;
	uint8 devStat;
	uint8 wwdStat;
	uint8 fwdStat0;
	uint8 fwdStat1;
	uint8 gtm;
}st_DevStatus;

typedef enum
{
	None      = 0,
	Init      = 1,
	Normal    = 2,
	Sleep     = 3,
	Standby   = 4,
	Wake      = 5,
	Reserved1 = 6,
	Reserved2 = 7
}en_DevState;

typedef struct
{
    uint8 SwErr;
	uint8 HwErr;
	uint16 ErrAutoClrCnt;
}st_FltMtrx;

typedef struct
{
	uint16 wwdCw;
	uint16 wwdOw;
	uint16 wwdTrigCnt;
	uint16 fwdOvThrld;
	uint16 fwdTrigCnt;
	uint16 fwdResStart;
}st_WdgSts;

typedef struct
{
	uint8 Quc    :1;
	uint8 Qco    :1;
	uint8 Qt1    :1;
	uint8 Qt2    :1;
	uint8 Qvr    :1;
	uint8 StdLDO :1;
	uint8 res    :2;
}st_PowerSts_B;

typedef struct
{
	union
	{
		st_PowerSts_B B;
		uint8 U;
	};
}st_PowerSts;

typedef struct
{
	uint8 StateTransition :1;
	uint8 WatchDogError:1;
	uint8 ErrorPinMonitor :1;
	uint8 MonitorBlock :1;
	uint8 OverTempWarn :1;
	uint8 OverTempShutDown :1;
	uint8 OverCurrent:1;
	uint8 SpiBlock :1;
	uint8 Abist :1;
	uint8 DoubleBitError :1;
}st_ErrSts_B;

typedef struct
{
	union
	{
		st_ErrSts_B B;
		uint16 U;
	};
}st_ErrSts;


typedef struct
{
	uint32 errCnt;
	boolean initialFinished;
	boolean DebugMode;
	boolean RegSts;
	st_FltMtrx fltMtrx;
	en_DevState devSts;
	en_DevState modeReq;
    st_WdgSts wdSts;
    st_PowerSts powerSts;
    st_ErrSts errSts;
}st_CtrlStatus;

typedef struct
{
	st_DevStatus  devIntSts;
	st_CtrlStatus ctrlExtSts;
}st_Tlf35584_Buff;



/***************************************Global function Define********************************/
extern void Tlf35584_Init(void);
extern void Tlf35584_Run(void);
extern void Tlf35584_ErrHook(void);
extern en_DevState Tlf35584_GetMode(void);
extern void Tlf35584_SetMode(en_DevState ModeReq);
extern uint16 Tlf35584_GetError(void);
extern uint8 Tlf35584_GetPowerSts(void);
extern uint8 Tlf35584_GetWindowWdgSts(void);
extern uint8 Tlf35584_GetFunctionWdgSts(void);
extern void Tlf35584_GetWakeTimerSts(uint8 *CtrlSts,uint32 *CntSts);

#endif /* TLF35584_H_ */
