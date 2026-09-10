/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2022)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Adc_PBcfg.c                                                   **
**                                                                            **
**  VERSION   : 14.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-09-09, 13:49:25            !!!IGNORE-LINE!!!             **
**                                                                            **
**  GENERATOR : Build b191017-0938              !!!IGNORE-LINE!!!             **
**                                                                            **
**  BSW MODULE DECRIPTION : Adc.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION :  Adc configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of ADC Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of module header file */
#include "Adc.h"
/*Function declaration for Notification Function of AdcGroup_AN0*/
extern void Adc_Sync_Callback_Motor(void);
/*Function declaration for Notification Function of AdcGroup_AN1*/
extern void IoHwAb_AdcNotification1(void);
/*Function declaration for Notification Function of AdcGroup_AN2*/
extern void IoHwAb_AdcNotification2(void);
/*Function declaration for Notification Function of AdcGroup_AN3*/
extern void IoHwAb_AdcNotification3(void);
/*Function declaration for Notification Function of AdcGroup_AN8*/
extern void IoHwAb_AdcNotification32(void);
/*Function declaration for Notification Function of AdcGroup_AN16*/
extern void IoHwAb_AdcNotification64(void);
/*Function declaration for Notification Function of AdcGroup_AN17*/
extern void IoHwAb_AdcNotification65(void);
/*Function declaration for Notification Function of AdcGroup_AN18*/
extern void IoHwAb_AdcNotification66(void);
/*Function declaration for Notification Function of AdcGroup_AN24*/
extern void IoHwAb_AdcNotification96(void);
/*Function declaration for Notification Function of AdcGroup_AN25*/
extern void IoHwAb_AdcNotification97(void);
/*Function declaration for Notification Function of AdcGroup_AN33*/
extern void IoHwAb_AdcNotification256(void);
/*Function declaration for Notification Function of AdcGroup_AN32*/
extern void IoHwAb_AdcNotification257(void);
/*Function declaration for Notification Function of AdcGroup_AN37*/
extern void IoHwAb_AdcNotification258(void);
/*Function declaration for Notification Function of AdcGroup_AN38*/
extern void IoHwAb_AdcNotification259(void);
/*Function declaration for Notification Function of AdcGroup_AN36*/
extern void IoHwAb_AdcNotification260(void);
/*Function declaration for Notification Function of AdcGroup_AN39*/
extern void IoHwAb_AdcNotification261(void);
/*Function declaration for Notification Function of AdcGroup_P33_1*/
extern void IoHwAb_AdcNotification320(void);
/*Function declaration for Notification Function of AdcGroup_P33_2*/
extern void IoHwAb_AdcNotification321(void);

/***********Global configuration of EMUX feature***********/

/***********Configuration for External HW trigger and gating signals***********/

/*******************Group Definition - Channel Sequence*******************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN0- ID0 of HW Unit 0 */
static const Adc_GroupDefType Adc_kHwUnit0GrpAdcGroup_AN0_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN1- ID1 of HW Unit 0 */
static const Adc_GroupDefType Adc_kHwUnit0GrpAdcGroup_AN1_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  1U,                   1U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN2- ID2 of HW Unit 0 */
static const Adc_GroupDefType Adc_kHwUnit0GrpAdcGroup_AN2_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  2U,                   2U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN3- ID3 of HW Unit 0 */
static const Adc_GroupDefType Adc_kHwUnit0GrpAdcGroup_AN3_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  3U,                   3U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN8- ID32 of HW Unit 1 */
static const Adc_GroupDefType Adc_kHwUnit1GrpAdcGroup_AN8_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN16- ID64 of HW Unit 2 */
static const Adc_GroupDefType Adc_kHwUnit2GrpAdcGroup_AN16_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN17- ID65 of HW Unit 2 */
static const Adc_GroupDefType Adc_kHwUnit2GrpAdcGroup_AN17_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  1U,                   1U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN18- ID66 of HW Unit 2 */
static const Adc_GroupDefType Adc_kHwUnit2GrpAdcGroup_AN18_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  2U,                   2U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN24- ID96 of HW Unit 3 */
static const Adc_GroupDefType Adc_kHwUnit3GrpAdcGroup_AN24_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN25- ID97 of HW Unit 3 */
static const Adc_GroupDefType Adc_kHwUnit3GrpAdcGroup_AN25_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  1U,                   1U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN33- ID256 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpAdcGroup_AN33_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   0U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN32- ID257 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpAdcGroup_AN32_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  1U,                   1U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN37- ID258 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpAdcGroup_AN37_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  2U,                   5U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN38- ID259 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpAdcGroup_AN38_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  3U,                   6U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN36- ID260 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpAdcGroup_AN36_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  4U,                   4U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_AN39- ID261 of HW Unit 8 */
static const Adc_GroupDefType Adc_kHwUnit8GrpAdcGroup_AN39_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  5U,                   7U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_P33_1- ID320 of HW Unit 10 */
static const Adc_GroupDefType Adc_kHwUnit10GrpAdcGroup_P33_1_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  0U,                   6U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/**Group Definition of AdcGroup_P33_2- ID321 of HW Unit 10 */
static const Adc_GroupDefType Adc_kHwUnit10GrpAdcGroup_P33_2_Config[1]=
{
  /*AS Logical Channel*/ /*Analog Channel*/ /*Result Register*/ /*Channel Diagnostic Data*/
        {  1U,                   0U,                0U,                0x00000000U}
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/***********************Group Configuration Definition***********************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 0 ******/
static const Adc_GroupCfgType Adc_kHwUnit0Grp_Config[4]=
{

  {/*Group Configuration structure for AdcGroup_AN0 - ID0*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    Adc_Sync_Callback_Motor,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit0GrpAdcGroup_AN0_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G0QCTRL register*/
    0x00004800U,
    /*Configuration value for the G0QMR register*/
    0x00000005U,
    /*Configuration value for the G0ALIAS register*/
    0x00000100U,
    /* Configuration value for G0REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0001U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0001U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0001U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN1 - ID1*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification1,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit0GrpAdcGroup_AN1_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G0QCTRL register*/
    0x00000000U,
    /*Configuration value for the G0QMR register*/
    0x00000001U,
    /*Configuration value for the G0ALIAS register*/
    0x00000100U,
    /* Configuration value for G0REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0002U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN2 - ID2*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification2,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit0GrpAdcGroup_AN2_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G0QCTRL register*/
    0x00000000U,
    /*Configuration value for the G0QMR register*/
    0x00000001U,
    /*Configuration value for the G0ALIAS register*/
    0x00000100U,
    /* Configuration value for G0REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0004U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN3 - ID3*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification3,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit0GrpAdcGroup_AN3_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G0QCTRL register*/
    0x00000000U,
    /*Configuration value for the G0QMR register*/
    0x00000001U,
    /*Configuration value for the G0ALIAS register*/
    0x00000100U,
    /* Configuration value for G0REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0008U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 1 ******/
static const Adc_GroupCfgType Adc_kHwUnit1Grp_Config[1]=
{

  {/*Group Configuration structure for AdcGroup_AN8 - ID32*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification32,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit1GrpAdcGroup_AN8_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G1QCTRL register*/
    0x00004800U,
    /*Configuration value for the G1QMR register*/
    0x00000005U,
    /*Configuration value for the G1ALIAS register*/
    0x00000100U,
    /* Configuration value for G1REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0001U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 2 ******/
static const Adc_GroupCfgType Adc_kHwUnit2Grp_Config[3]=
{

  {/*Group Configuration structure for AdcGroup_AN16 - ID64*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_HW
      Trigger Edge: ADC_HW_TRIG_RISING_EDGE
      HW Trigger Source: ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification64,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit2GrpAdcGroup_AN16_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G2QCTRL register*/
    0x00004800U,
    /*Configuration value for the G2QMR register*/
    0x00000005U,
    /*Configuration value for the G2ALIAS register*/
    0x00000100U,
    /* Configuration value for G2REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0001U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_HW,
    ADC_CONV_MODE_ONESHOT,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_GTM_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN17 - ID65*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification65,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit2GrpAdcGroup_AN17_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G2QCTRL register*/
    0x00000000U,
    /*Configuration value for the G2QMR register*/
    0x00000001U,
    /*Configuration value for the G2ALIAS register*/
    0x00000100U,
    /* Configuration value for G2REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0002U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN18 - ID66*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification66,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit2GrpAdcGroup_AN18_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G2QCTRL register*/
    0x00000000U,
    /*Configuration value for the G2QMR register*/
    0x00000001U,
    /*Configuration value for the G2ALIAS register*/
    0x00000100U,
    /* Configuration value for G2REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0004U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 3 ******/
static const Adc_GroupCfgType Adc_kHwUnit3Grp_Config[2]=
{

  {/*Group Configuration structure for AdcGroup_AN24 - ID96*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification96,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit3GrpAdcGroup_AN24_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G3QCTRL register*/
    0x00000000U,
    /*Configuration value for the G3QMR register*/
    0x00000001U,
    /*Configuration value for the G3ALIAS register*/
    0x00000100U,
    /* Configuration value for G3REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0001U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN25 - ID97*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification97,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit3GrpAdcGroup_AN25_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G3QCTRL register*/
    0x00000000U,
    /*Configuration value for the G3QMR register*/
    0x00000001U,
    /*Configuration value for the G3ALIAS register*/
    0x00000100U,
    /* Configuration value for G3REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0002U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 8 ******/
static const Adc_GroupCfgType Adc_kHwUnit8Grp_Config[6]=
{

  {/*Group Configuration structure for AdcGroup_AN33 - ID256*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification256,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpAdcGroup_AN33_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00000000U,
    /*Configuration value for the G8QMR register*/
    0x00000001U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0001U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN32 - ID257*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification257,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpAdcGroup_AN32_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00000000U,
    /*Configuration value for the G8QMR register*/
    0x00000001U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0002U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN37 - ID258*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification258,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpAdcGroup_AN37_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00000000U,
    /*Configuration value for the G8QMR register*/
    0x00000001U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0020U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN38 - ID259*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification259,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpAdcGroup_AN38_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00000000U,
    /*Configuration value for the G8QMR register*/
    0x00000001U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0040U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN36 - ID260*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification260,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpAdcGroup_AN36_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00000000U,
    /*Configuration value for the G8QMR register*/
    0x00000001U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0010U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_AN39 - ID261*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification261,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit8GrpAdcGroup_AN39_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G8QCTRL register*/
    0x00000000U,
    /*Configuration value for the G8QMR register*/
    0x00000001U,
    /*Configuration value for the G8ALIAS register*/
    0x00000100U,
    /* Configuration value for G8REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0080U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/ 

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Group Configuration Definition of HW Unit 10 ******/
static const Adc_GroupCfgType Adc_kHwUnit10Grp_Config[2]=
{

  {/*Group Configuration structure for AdcGroup_P33_1 - ID320*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification320,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit10GrpAdcGroup_P33_1_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G10QCTRL register*/
    0x00000000U,
    /*Configuration value for the G10QMR register*/
    0x00000001U,
    /*Configuration value for the G10ALIAS register*/
    0x00000100U,
    /* Configuration value for G10REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0040U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  },

  {/*Group Configuration structure for AdcGroup_P33_2 - ID321*/
    /*
      Group Properties:
      Trigger Source: ADC_TRIGG_SRC_SW
      Trigger Edge: 
      HW Trigger Source: ADC_TRIG_NONE
      HW Gate Source: ADC_GATE_NONE
      Gate Level: ADC_GATE_LVL_HIGH
    */
    /* Notification Function Address */
    IoHwAb_AdcNotification321,
    /*Address for Group Definition Structure*/
    &Adc_kHwUnit10GrpAdcGroup_P33_2_Config[0U],
    /*Address for the GTM trigger configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the GTM gate configuration structure*/
    (const Mcu_17_Gtm_TomAtomChConfigType *)0U,
    /*Address for the ERU trigger configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Address for the ERU gate configuration structure*/
    (const Adc_EruChannelCfgType *)0U,
    /*Configuration value for the G10QCTRL register*/
    0x00000000U,
    /*Configuration value for the G10QMR register*/
    0x00000001U,
    /*Configuration value for the G10ALIAS register*/
    0x00000100U,
    /* Configuration value for G10REQTM register*/
    0x00000000U,
    /*Bit Mask for all the analog channels configured for the group*/
    0x0001U,
    /*Bit Mask for all the result registers configured for the group*/
    0x0001U,
    /*Bit Mask for all the analog channels configured for synchronous conversion*/
    0x0000U,
    /*Bit Mask for all the result registers configured for synchronous conversion*/
    0x0000U,
    ADC_TRIGG_SRC_SW,
    ADC_CONV_MODE_CONTINUOUS,
    ADC_ACCESS_MODE_SINGLE,
    ADC_STREAM_BUFFER_CIRCULAR,
    1U, /*Number of streaming samples for the group*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Trigger*/
    ADC_OTHER_HW_USED, /*HW peripheral used for Gate*/
    0U, /*Priority Level for the group*/
    1U, /*Channel Count for the group*/
    0U, /*Limit Check enabled for the group*/
    0x00U, /* EMUX configuration of the Group */
    0U /* Diagnostic channels configured for the Group */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***********************Channel Configuration Definition***********************/
/*****Channel Configuration Definition of HW Unit 0 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit0Ch_Config[4]=
{

  {
    0x00000402U, /*Configuration value for the G0CHCTR0 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G0CHCTR1 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G0CHCTR2 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G0CHCTR3 register*/
    0x00000000U, /*Configuration value for the G0BOUND register*/
    3U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 1 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit1Ch_Config[1]=
{

  {
    0x00000002U, /*Configuration value for the G1CHCTR0 register*/
    0x00000000U, /*Configuration value for the G1BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 2 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit2Ch_Config[3]=
{

  {
    0x00000002U, /*Configuration value for the G2CHCTR0 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G2CHCTR1 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G2CHCTR2 register*/
    0x00000000U, /*Configuration value for the G2BOUND register*/
    2U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 3 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit3Ch_Config[2]=
{

  {
    0x00000002U, /*Configuration value for the G3CHCTR0 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G3CHCTR1 register*/
    0x00000000U, /*Configuration value for the G3BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 8 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit8Ch_Config[6]=
{

  {
    0x00000002U, /*Configuration value for the G8CHCTR0 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G8CHCTR1 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    1U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G8CHCTR5 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    5U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G8CHCTR6 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G8CHCTR4 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    4U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G8CHCTR7 register*/
    0x00000000U, /*Configuration value for the G8BOUND register*/
    7U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/*****Channel Configuration Definition of HW Unit 10 *****/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_ChannelCfgType Adc_kHwUnit10Ch_Config[2]=
{

  {
    0x00000002U, /*Configuration value for the G10CHCTR6 register*/
    0x00000000U, /*Configuration value for the G10BOUND register*/
    6U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  },

  {
    0x00000002U, /*Configuration value for the G10CHCTR0 register*/
    0x00000000U, /*Configuration value for the G10BOUND register*/
    0U, /*Analog Channel number for the corresponding Logical Channel*/
    0U /*Limit Check channel or not */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

/********************HW Unit Converter Configurations********************/
    
    
  

/**HW Unit 0 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit0Hw_Config=
{
  0x00380004U, /*Configuration value for G0ANCFG register*/
  0x00000003U, /*Configuration value for G0ARBCFG register*/
  0x07000218U, /*Configuration value for G0ARBPR register*/
  0x0000000aU, /*Configuration value for G0ICLASS0 register*/
  0x0000000aU, /*Configuration value for G0ICLASS1 register*/
  0x00000030U /*Configuration value for G0SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

    
    
  

/**HW Unit 1 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit1Hw_Config=
{
  0x00380004U, /*Configuration value for G1ANCFG register*/
  0x00000000U, /*Configuration value for G1ARBCFG register*/
  0x07000218U, /*Configuration value for G1ARBPR register*/
  0x0000000aU, /*Configuration value for G1ICLASS0 register*/
  0x0000000aU, /*Configuration value for G1ICLASS1 register*/
  0x00000031U /*Configuration value for G1SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

    
    
  

/**HW Unit 2 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit2Hw_Config=
{
  0x00380004U, /*Configuration value for G2ANCFG register*/
  0x00000000U, /*Configuration value for G2ARBCFG register*/
  0x07000218U, /*Configuration value for G2ARBPR register*/
  0x0000000aU, /*Configuration value for G2ICLASS0 register*/
  0x0000000aU, /*Configuration value for G2ICLASS1 register*/
  0x00000031U /*Configuration value for G2SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/**HW Unit 3 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit3Hw_Config=
{
  0x00300004U, /*Configuration value for G3ANCFG register*/
  0x00000003U, /*Configuration value for G3ARBCFG register*/
  0x07000210U, /*Configuration value for G3ARBPR register*/
  0x0000000aU, /*Configuration value for G3ICLASS0 register*/
  0x0000000aU, /*Configuration value for G3ICLASS1 register*/
  0x00000000U /*Configuration value for G3SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/**HW Unit 8 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit8Hw_Config=
{
  0x00300004U, /*Configuration value for G8ANCFG register*/
  0x00000003U, /*Configuration value for G8ARBCFG register*/
  0x07000210U, /*Configuration value for G8ARBPR register*/
  0x0000000aU, /*Configuration value for G8ICLASS0 register*/
  0x0000000aU, /*Configuration value for G8ICLASS1 register*/
  0x00000000U /*Configuration value for G8SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/**HW Unit 10 Converter Configurations **/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwCfgType Adc_kHwUnit10Hw_Config=
{
  0x00300004U, /*Configuration value for G10ANCFG register*/
  0x00000003U, /*Configuration value for G10ARBCFG register*/
  0x07000210U, /*Configuration value for G10ARBPR register*/
  0x0000000aU, /*Configuration value for G10ICLASS0 register*/
  0x0000000aU, /*Configuration value for G10ICLASS1 register*/
  0x00000000U /*Configuration value for G10SYNCTR register*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***************************HW Unit Configuration ***************************/

/*************HW Unit 0 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit0_Config=
{
  &Adc_kHwUnit0Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit0Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit0Grp_Config[0U], /*Group Configuration structure*/
  0x0000000eU, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_MASTER, /* Synchronous conversion mode */
  { 0x01U, 0x02U, 0xffU }, /* Slave Kernels */
  4U, /* Group Count for HW Unit 0*/
  7U /* Bit Mask for SRNs used for HW Unit 0*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 1 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit1_Config=
{
  &Adc_kHwUnit1Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit1Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit1Grp_Config[0U], /*Group Configuration structure*/
  0x00000000U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_SLAVE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  1U, /* Group Count for HW Unit 1*/
  7U /* Bit Mask for SRNs used for HW Unit 1*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 2 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit2_Config=
{
  &Adc_kHwUnit2Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit2Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit2Grp_Config[0U], /*Group Configuration structure*/
  0x00000006U, /* Mask for SW triggered groups*/
  0x00000001U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_SLAVE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  3U, /* Group Count for HW Unit 2*/
  7U /* Bit Mask for SRNs used for HW Unit 2*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 3 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit3_Config=
{
  &Adc_kHwUnit3Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit3Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit3Grp_Config[0U], /*Group Configuration structure*/
  0x00000003U, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  2U, /* Group Count for HW Unit 3*/
  7U /* Bit Mask for SRNs used for HW Unit 3*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 8 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit8_Config=
{
  &Adc_kHwUnit8Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit8Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit8Grp_Config[0U], /*Group Configuration structure*/
  0x0000003fU, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  6U, /* Group Count for HW Unit 8*/
  7U /* Bit Mask for SRNs used for HW Unit 8*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/*************HW Unit 10 Configuration **************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
   #define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_HwUnitCfgType Adc_kHwUnit10_Config=
{
  &Adc_kHwUnit10Hw_Config, /*Analog Converter Configuration*/
  &Adc_kHwUnit10Ch_Config[0U], /*Channel Configuration structure*/
  &Adc_kHwUnit10Grp_Config[0U], /*Group Configuration structure*/
  0x00000003U, /* Mask for SW triggered groups*/
  0x00000000U,/* Mask for HW triggered groups*/
  ADC_SYNC_CONV_MODE_NONE, /* Synchronous conversion mode */
  { 0xffU, 0xffU, 0xffU }, /* Slave Kernels */
  2U, /* Group Count for HW Unit 10*/
  7U /* Bit Mask for SRNs used for HW Unit 10*/
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
/******************Global Configuration*******************/

static const Adc_GlobalCfgType Adc_kGlob_Config=
{
  0x00000000U, /*Configuration value for GLOBCFG register */
  0x0000000aU, /*Configuration value for GLOBICLASS0 register */
  0x0000000aU, /*Configuration value for GLOBICLASS1 register */
  0x00000000U /*Configuration value for EMUXSEL register */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


/***************************Core Configuration ***************************/
/*******Core0 Configuration*******/
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
static const Adc_CoreConfigType Adc_kCore0_Config=
{
  {
    &Adc_kHwUnit0_Config, /* HW Unit 1 Configuration */
    &Adc_kHwUnit1_Config, /* HW Unit 2 Configuration */
    &Adc_kHwUnit2_Config, /* HW Unit 3 Configuration */
    &Adc_kHwUnit3_Config, /* HW Unit 4 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 5 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 6 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 7 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 8 Configuration */
    &Adc_kHwUnit8_Config, /* HW Unit 9 Configuration */
    (Adc_HwUnitCfgType*)0U, /* HW Unit 10 Configuration */
    &Adc_kHwUnit10_Config, /* HW Unit 11 Configuration */
    (Adc_HwUnitCfgType*)0U /* HW Unit 12 Configuration */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Memmap macros are defined as per Autosar
   naming convention, hence it goes beyond 32 characters.*/

#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"
  

/*******Configuration Root*******/ 
#define ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar 
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"

const Adc_ConfigType Adc_Config=
{
  &Adc_kGlob_Config, /* Global Configuration */
  {
    &Adc_kCore0_Config, /* Core0 Configuration */
    (const Adc_CoreConfigType*)0U, /* Core1 Configuration */
    (const Adc_CoreConfigType*)0U /* Core2 Configuration */
  }
};


#define ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */ 
#include "Adc_MemMap.h"


