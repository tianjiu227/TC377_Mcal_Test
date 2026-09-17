/*
 * Cdd_Tlf35584_Cfg.h
 *
 *  Created on: 2021Äê8ÔÂ31ÈÕ
 *      Author: admin
 */

#ifndef CDD_35584_CDD_TLF35584_CFG_H_
#define CDD_35584_CDD_TLF35584_CFG_H_

/**************************************Enable Switch Define************************************/
#define   FUNCTTION_WATCHDOG_ENABLE       (0x1U)   /*0x1:Enable  0x0:Disable*/
#define   WINDOW_WATCHDOG_ENABLE          (0x1U)   /*0x1:Enable  0x0:Disable*/
#define   WATCH_DOG_SLOW_MODE             (0x1U)   /*0x1:Enable  0x0:Disable*/
#define   STEP_DOWN_FRE_LOW_QUENCY        (0x1U)   /*0x1:Enable  0x0:Disable*/
#define   WAKE_TIMER_ENABLE               (0x1U)   /*0x1:Enable  0x0:Disable*/
#define   REGISTER_DEBUG_MODE_ENABLE      (0x1U)   /*0x1:Enable  0x0:Disable*/
/**************************************Power Source Switch Define*****************************/
#define   STANDBY_QST_ENABLE               (0x1)

/*WAKE MODE*/
#define   WAKE_COM_LDO_ENABLE              (0x1)
#define   WAKE_QT1_ENABLE                  (0x1)
#define   WAKE_QT2_ENABLE                  (0x1)
#define   WAKE_REF_LDO_ENABLE              (0x1)

/*NORMAL MODE*/
#define   NORMAL_COM_LDO_ENABLE            (0x1)
#define   NORMAL_QT1_ENABLE                (0x1)
#define   NORMAL_QT2_ENABLE                (0x1)
#define   NORMAL_REF_LDO_ENABLE            (0x1)

/*SLEEP MODE*/
#define   SLEEP_COM_LDO_ENABLE             (0x1)
#define   SLEEP_QT1_ENABLE                 (0x1)
#define   SLEEP_QT2_ENABLE                 (0x1)
#define   SLEEP_REF_LDO_ENABLE             (0x1)

/**************************************FAULT MASK Define**************************************/
#define   IF_FAULT_MASK                   (0x39U)
#define   FAULT_AUTO_CLEAR_CYCLE          (100U)    /*500mS*/

/**************************************Wake up Time Parameter Define**************************/
#define   WAKE_TIMER_MS                   (0x1)     /*1:Unit=10ms  0:Unit:10us*/
#define   WAKE_TIMER_COUNT                (1000)     /*10ms*1000 = 10S*/

/**************************************WatchDog Time Parameter Define**************************/
#define   WDCFG0_DEFAULT                  (0x90U+(FUNCTTION_WATCHDOG_ENABLE<<2)+(WINDOW_WATCHDOG_ENABLE<<3)+(WATCH_DOG_SLOW_MODE))
/*0X9D  Set WWDTSEL = 0,Using WDI to Feed Watch Dog,
Set WWDEN = 1,Enable Window Watch Dog,Set FWDEN = 1,Enable Function Watch Dog*/

#define   MODULE_CTRL_PERIOD_MS           (0x5U)    /*5ms*/

#if WATCH_DOG_SLOW_MODE == 0x1
#define   WD_DEFAULT_CYCLE_MS             (50U)     /*Slow Mode 50ms*/
#else
#define   WD_DEFAULT_CYCLE_MS             (5U)      /*Fast Mode 5ms*/
#endif

#if WATCH_DOG_SLOW_MODE == 0x1
#define   WWDCFG0_DEFAULT                 (0x7U)    /*Slow Mode:400ms*/
#define   WWDCFG1_DEFAULT                 (0xBU)    /*Slow Mode 600ms*/
#define   FWDCFG_DEFAULT                  (0x9U)    /*Slow Mode 500ms*/
#else
#define   WWDCFG0_DEFAULT                 (0x7U)    /*Fast Mode 40ms*/
#define   WWDCFG1_DEFAULT                 (0xBU)    /*Fast Mode 60ms*/
#define   FWDCFG_DEFAULT                  (0x13U)    /*Fast Mode 100ms*/
#endif
/**************************************Check Parameter Error************************************/
#if WD_SLOW_MODE == 0x0
#if FWDCFG_DEFAULT < 7
#error 'FWDCFG_DEFAULT Parameter too small,the miumun is 7 in Fast Mode'
#endif
#endif




#endif /* 1_LIB_0_BSW_4_CDD_35584_CDD_TLF35584_CFG_H_ */
