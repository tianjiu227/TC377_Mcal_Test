/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2024)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Pwm_17_GtmCcu6_PBcfg.c                                        **
**                                                                            **
**  VERSION   : 23.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2023-09-11, 15:05:43              !!!IGNORE-LINE!!!       **
**                                                                            **
**  GENERATOR : Build b191017-0938                !!!IGNORE-LINE!!!         **
**                                                                            **
**  BSW MODULE DECRIPTION : Pwm.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Pwm configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR Specification of Pwm Driver                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include module header File */
#include "Pwm_17_GtmCcu6.h"
#include "Mcu_17_TimerIp.h"



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*
Configuration:
PWM Channel Configuration:
Elements / Attributes
1. Notification function pointer (if required)
2. Shift Value, only for PWM_FIXED_PERIOD_SHIFTED Class
   Input a value between 0 and 0x8000.
3. Default Duty Cycle ( duty cycle value between
   0 and 0x8000)
4. Pwm_Period:
   Enter in ticks
   PWM070: All time units should be in ticks.
5. Pwm_ConfigChannel:
   Go in the following parameter order
   a) Reference to Channel Number, for a Shifted, Center Aligned and
   Zero Shifted channel, a reference must be given. For a variable
   and Fixed Period channel class, reference should not be given.
   Reference should be given in the form of channel number index.
   b) Channel Class
      Possible Options: PWM_FIXED_PERIOD, PWM_FIXED_PERIOD_SHIFTED,
      PWM_FIXED_PERIOD_CENTER_ALIGNED, PWM_VARIABLE_PERIOD
   c) Channel Idle State:
      Possible Options: PWM_LOW, PWM_HIGH
      Output line goes into Idle state either after Pwm_SetOutputtoIdle
      or Pwm_DeInit.
   d) Channel Polarity:
      Possible Options: PWM_LOW, PWM_HIGH
      Initial Polarity state of the channel.
   e) GTM timer Configuration:
      Select timer reference :TOM/ATOM.
      Clockselect.
 */
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*
Function Like Macro:Pwm_lConfigChannel
Macro that packs the PWM Channel Information.
Input Parameters:
DsadcNotif: The notification flag to enable GTM interrupts to trigger DSADC
ShiftReset: Shifted channel is reset by itself or by other channel
ChannelClass : Channel Class
ChannelCoherency : Channel Coherency
IdleState : Idle State
Polarity : Channel Polarity
AssignedHwUnit : Hardware Unit Used
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro is used to reduce the
memory usage */
#define Pwm_lConfigChannel(DsadcNotif,                   \
                           ShiftReset,                   \
                           ChannelClass,                 \
                           ChannelCoherency,             \
                           IdleState,                    \
                           Polarity)                     \
              ((uint16)( ((DsadcNotif) << 6U)          |   \
                         ((ShiftReset) << 5U)          |   \
                         ((ChannelClass) << 3U)        |   \
                         ((ChannelCoherency) << 2U)    |   \
                         ((IdleState) << 1U)           |   \
                         ((Polarity))                       \
                       ))
/******************************************************************************/
/******************************************************************************/
  
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion. It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
  
static const uint8 Pwm_ChannelIndexMap [12] =
{
  0x0U,
  0x1U,
  0x2U,
  0x3U,
  0x4U,
  0x5U,
  0x6U,
  0x7U,
  0x8U,
  0x9U,
  0xaU,
  0xbU,
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/* Loop for all the cores */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
        
static const Mcu_17_Gtm_TomAtomChConfigType Pwm_kChannelConfigGtm_Core0[12] = 
{
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x0U,
    0x81000002U, /* Channel Control Register*/
    0x1388U, /* CN0 in ticks */
    0x1388U, /* CM0 in ticks */
    0x9c4U, /* CM1 in ticks */
    0x1388U, /* SR0 in ticks */
    0x9c4U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x1U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0xffffffU, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0xffffffU, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x2U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0xffffffU, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0xffffffU, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x3U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0xffffffU, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0xffffffU, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x4U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0xffffffU, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0xffffffU, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x5U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0xffffffU, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0xffffffU, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x6U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0xffffffU, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0xffffffU, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x7U,
    0x80100802U, /* Channel Control Register*/
    0x0U, /* CN0 in ticks */
    0x0U, /* CM0 in ticks */
    0x64U, /* CM1 in ticks */
    0x0U, /* SR0 in ticks */
    0x64U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x100U,
    0x80001802U, /* Channel Control Register*/
    0x1388U, /* CN0 in ticks */
    0x1388U, /* CM0 in ticks */
    0x9c4U, /* CM1 in ticks */
    0x1388U, /* SR0 in ticks */
    0x9c4U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x101U,
    0x80000002U, /* Channel Control Register*/
    0x1388U, /* CN0 in ticks */
    0x1388U, /* CM0 in ticks */
    0x9c4U, /* CM1 in ticks */
    0x1388U, /* SR0 in ticks */
    0x9c4U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x102U,
    0x80000002U, /* Channel Control Register*/
    0x1388U, /* CN0 in ticks */
    0x1388U, /* CM0 in ticks */
    0x9c4U, /* CM1 in ticks */
    0x1388U, /* SR0 in ticks */
    0x9c4U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
  {
    MCU_GTM_TIMER_ATOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x105U,
    0x80000002U, /* Channel Control Register*/
    0x1388U, /* CN0 in ticks */
    0x1388U, /* CM0 in ticks */
    0x9c4U, /* CM1 in ticks */
    0x1388U, /* SR0 in ticks */
    0x9c4U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
};
      
static const Pwm_17_GtmCcu6_ChannelConfigType Pwm_kChannelConfigurationCore0[] =
{
/*******************************************************************************
*  Channel Number        : 0
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_0
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    0, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_LOW  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x9c4, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[0],
    4294967295, /* Clock Divider value */
    255 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 1
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    1, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[1],
    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 2
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_2
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    2, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[2],
    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 3
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_3
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    3, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[3],
    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 4
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_4
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    4, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[4],

    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 5
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_5
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    5, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[5],

    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 6
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_6
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    6, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[6],

    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 7
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_7
*  Channel Class         : PWM_FIXED_PERIOD_SHIFTED
*******************************************************************************/
  {
    7, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      1U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD_SHIFTED,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x64, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[7],

    4294967295, /* Clock Divider value */
    0 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 8
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_7
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    8, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x9c4, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[8],
    4294967295, /* Clock Divider value */
    255 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 9
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_9
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    9, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_LOW  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x9c4, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[9],
    4294967295, /* Clock Divider value */
    255 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 10
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_10
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    10, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_LOW  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x9c4, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[10],
    4294967295, /* Clock Divider value */
    255 /* Fixed channel timer channel used */
  },
/*******************************************************************************
*  Channel Number        : 11
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_8
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    11, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_LOW  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x1388, /* Default Period */
    (uint32)0x9c4, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
    (const void*)&Pwm_kChannelConfigGtm_Core0[11],
    4294967295, /* Clock Divider value */
    255 /* Fixed channel timer channel used */
  },
};
      
static const Pwm_17_GtmCcu6_CoreConfigType Pwm_CoreConfigCore0 =
{ 
  (Pwm_17_GtmCcu6_ChannelType)12U,
  (const Pwm_17_GtmCcu6_ChannelConfigType*)&Pwm_kChannelConfigurationCore0[0]
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"

const Pwm_17_GtmCcu6_ConfigType Pwm_17_GtmCcu6_Config =
{
  {

    /* MISRA2012_RULE_11_8_JUSTIFICATION: This typecast is in-line with the data type of the structure member PwmCoreAdd, MISRA is reported becasue of structure Pwm_CoreConfigCore,
    which is defined as constant to be allocated in Read only memory, Hence no side effects foreseen by violating this MISRA rule */

    (Pwm_17_GtmCcu6_CoreConfigType*)&Pwm_CoreConfigCore0,
    /* MISRA2012_RULE_11_8_JUSTIFICATION: This typecast is in-line with the data type of the structure member PwmCoreAdd, MISRA is reported becasue of structure Pwm_CoreConfigCore,
    which is defined as constant to be allocated in Read only memory, Hence no side effects foreseen by violating this MISRA rule */

    NULL_PTR,
    NULL_PTR
  },
  /* MISRA2012_RULE_11_8_JUSTIFICATION: This typecast is in-line with the data type of structure member PwmChannelIdxmapPtr, MISRA is reported becasue of data type Pwm_ChannelIndexMap,
  which is defined as constant to be allocated in Read only memory, Hence no side effects foreseen by violating this MISRA rule */
  (uint8*)&Pwm_ChannelIndexMap,
  { 
    0xffffffffU,
    0xffffffffU
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
