#ifndef USER_CAN_H_
#define USER_CAN_H_

#include "IfxSrc_reg.h"
#include "Can_17_McmCan.h"
#include "CanIf_Cbk.h"
#include "Irq.h"
#include "Delay.h"


typedef enum
{
    CAN_EXTENDED_CAN = 0U,        /* CAN frame with extended identifier (29 bits) */
    CAN_EXTENDED_FD_CAN,          /* CAN FD frame with extended identifier (29 bits) */
    CAN_STANDARD_CAN,             /* CAN frame with standard identifier (11 bits) */
    CAN_STANDARD_FD_CAN           /* CAN FD frame with standard identifier (11 bits) */
} Can_FrameIdType;


void Can_DemoFunction(void);


/* CAN interface function */
void CanIf_ControllerBusOff(uint8 ControllerId);
void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);
void CanIf_TxConfirmation(PduIdType CanTxPduId);
void CanIf_RxIndication(const Can_HwType * Mailbox, const PduInfoType * PduInfoPtr);


/**
 * @brief CAN发送信息配置
 * @param id：报文ID
 * @param swPduHandle：路由ID，一般为0即可
 * @param length：有效数据长度
 * @param sdu：有效数据
 * @param Id_Type：帧类型
 * @return CAN发送信息配置结构体
 */
Can_PduType CAN_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu, uint8 Id_Type);
void Can_DummyDelay(uint32 loops);


/* CAN0 Module User Interface */
void CAN0_Module_Init(void);
uint8 CAN0_Receive(uint8* Recv_Data, uint8 Data_Length);
uint8 CAN0_Transmit(Can_HwHandleType Hth, Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu, uint8 Id_Type);


#endif
