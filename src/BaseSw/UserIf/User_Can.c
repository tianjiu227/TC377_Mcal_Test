#include "User_Can.h"

uint8 Buffer_TX0[8];
uint8 Buffer_RX0[8] ;
Can_PduType TestPduInfo[ ] =
{
	{0,8, 0x100, Buffer_RX0 },
	{0,8, 0x510, Buffer_TX0 },
};

Std_ReturnType Can_Return = E_OK;
uint8 CAN_Rx_Data[64] = {0};

void Can_DemoFunction(void)
{
    CAN0_Module_Init();

	uint8 i;
	/*-----------------test the can   ---------------------*/
	for(i = 0; i < 8; i++)
	{
		Buffer_TX0[i]= i;
	}

	TestPduInfo[1].id = 0x123;

	uint8 CAN_Tx_Data[64] = {1,2,3,4,5,6,7,8};
	//uint8 CAN_Rx_Data[8] = {0};
	volatile uint8 RetVal;



    while(1)
    {
		//Can_Return = Can_17_McmCan_Write(Can_17_McmCanConf_CanHardwareObject_CanHardwareObject_CAN00_Can1Tx, &TestPduInfo[1]);

    	// RetVal = CAN0_Transmit(Can_17_McmCanConf_CanHardwareObject_CanHardwareObject_can1tx_0X100, 0x456, 0, 64, CAN_Tx_Data, CAN_STANDARD_FD_CAN);
    	// delay_ms(50);

#if 1
	    /* 将数据写入邮箱 */
		RetVal = CAN0_Transmit(Can_17_McmCanConf_CanHardwareObject_CanHardwareObject_can2tx_0X200, 0x1800E000, 0, 64, CAN_Tx_Data, CAN_EXTENDED_FD_CAN);
		delay_ms(50);

		/* 读取接收到的数据 */
		RetVal = CAN0_Receive(CAN_Rx_Data, 64);

		CAN_Tx_Data[0]++;
		CAN_Tx_Data[1]++;
		CAN_Tx_Data[2]++;
		CAN_Tx_Data[3]++;
		CAN_Tx_Data[4]++;
		CAN_Tx_Data[5]++;
		CAN_Tx_Data[6]++;
		CAN_Tx_Data[7]++;
#endif

    }
}


uint8 CAN0_Recv_Data[64];
uint8 CanIf_u8TxConfirmCnt = 0U;
boolean CanIf_bTxFlag = FALSE;
uint8 CanIf_u8RxIndicationCnt = 0U;
boolean CanIf_bRxFlag = FALSE;
boolean CAN0_IsCanFdFrame = FALSE;

#if 1
void CanIf_ControllerBusOff(uint8 ControllerId)
{
	(void)ControllerId;
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
    /* No functionality - just stub for build propose */

    (void)ControllerId;

    (void)ControllerMode;
}

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
	(void)CanTxPduId;

	CanIf_u8TxConfirmCnt++;
    CanIf_bTxFlag = TRUE;
}

uint8 CAN_EXT_Cnt = 0;
uint8 CAN_STD_Cnt = 0;
uint8 CAN_FD_Cnt = 0;
uint8 CAN_Cnt = 0;
uint32 g_actual_id = 0;
void CanIf_RxIndication(const Can_HwType * Mailbox, const PduInfoType * PduInfoPtr)
{
    (void)Mailbox;
    (void)PduInfoPtr;

    uint8 i = 0;
    volatile uint32 actual_id = 0;
	volatile uint8 is_canfd = FALSE;  /* 新增：CAN FD标志 */

    // 1. 通过 CAN ID 的最高位判断是否为扩展帧（bit31 = 1 为扩展帧）
    if (Mailbox->CanId & 0x80000000)  // 扩展帧接收
    {
        actual_id = Mailbox->CanId & 0x1FFFFFFF;  // CAN：0x98F00500 → 0x18F00500, CANFD：0xd8fef200 → 0x18fef200
        CAN_EXT_Cnt++;
    }
    else  // 标准帧接收
    {
        actual_id = Mailbox->CanId & 0x7FF;  // CAN：6bb → 6bb， CANFD：0x400006bb → 6bb
        CAN_STD_Cnt++;
    }

	g_actual_id = actual_id;

	// 2. 判断 CAN / CAN FD（bit30 = 1 为 CAN FD）
    is_canfd = (Mailbox->CanId & 0x40000000U) ? TRUE : FALSE;

    CanIf_u8RxIndicationCnt++;

    for(i = 0; i < PduInfoPtr->SduLength; i++)
    {
        CAN0_Recv_Data[i] = PduInfoPtr->SduDataPtr[i];
    }

	CAN0_IsCanFdFrame = is_canfd;

	/* judge CANFD and CAN */
    if(CAN0_IsCanFdFrame == TRUE)
    {
		CAN_FD_Cnt++;
    }
	else
	{
		CAN_Cnt++;
	}
	
    CanIf_bRxFlag = TRUE;
}
#endif

void CAN0_Module_Init(void)
{
	IrqCan_Init();
	
	SRC_CAN_CAN0_INT0.B.SRE = 1;
	SRC_CAN_CAN0_INT1.B.SRE = 1;
	SRC_CAN_CAN0_INT2.B.SRE = 1;
	SRC_CAN_CAN0_INT3.B.SRE = 1;

	SRC_CAN_CAN1_INT4.B.SRE = 1;
	SRC_CAN_CAN1_INT5.B.SRE = 1;
	SRC_CAN_CAN1_INT6.B.SRE = 1;
	SRC_CAN_CAN1_INT7.B.SRE = 1;

	Can_17_McmCan_Init(&Can_17_McmCan_Config);

	/* CAN1 */
	// Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CanController_can1 , CAN_CS_STARTED);
	// Can_17_McmCan_EnableControllerInterrupts(Can_17_McmCanConf_CanController_CanController_can1 );
	/* CAN2 */
	Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CanController_can2, CAN_CS_STARTED);
	Can_17_McmCan_EnableControllerInterrupts(Can_17_McmCanConf_CanController_CanController_can2);
}


/**
 * @brief CAN发送信息配置
 * @param id：报文ID
 * @param swPduHandle：路由ID，一般为0即可
 * @param length：有效数据长度
 * @param sdu：有效数据
 * @param Id_Type：帧类型
 * @return CAN发送信息配置结构体
 */
Can_PduType CAN_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu, uint8 Id_Type)
{
	Can_PduType PduInfo;

	switch (Id_Type)
    {
        case CAN_EXTENDED_CAN:
        {
            PduInfo.id = id | 0x80000000U;
            break;
        }
        case CAN_EXTENDED_FD_CAN:
        {
            PduInfo.id = id | 0xC0000000U;
            break;
        }
        case CAN_STANDARD_FD_CAN:
        {
            PduInfo.id = id | 0x40000000U;
            break;
        }
        default:
        {
			PduInfo.id = id;
            break;
        }
    }

	PduInfo.swPduHandle = swPduHandle;
	PduInfo.length = length;
	PduInfo.sdu = sdu;

	return PduInfo;
}

uint8 CAN0_Receive(uint8* Recv_Data, uint8 Data_Length)
{
	uint8 i = 0;

	if(CanIf_u8RxIndicationCnt > 0)
	{
		for(i = 0; i < Data_Length; i++)
		{
			Recv_Data[i] = CAN0_Recv_Data[i];
		}
		CanIf_u8RxIndicationCnt = 0;
		return 1;//成功
	}

	return 0;//失败
}

uint8 CAN0_Transmit(Can_HwHandleType Hth, Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu, uint8 Id_Type)
{
	Std_ReturnType RetVal;
	Can_PduType CanPduInfo;

	CanPduInfo = CAN_CreatePduInfo(id, swPduHandle, length, sdu, Id_Type);

	/* Hth：CAN 邮箱，在 EB 配置 CAN 邮箱中 Can Object ID 选项。 */
	/* PduInfo：CAN 发送信息结构体，其中包含 CAN 发送的 ID、有效数据数据长度等。 */
	RetVal = Can_17_McmCan_Write(Hth, &CanPduInfo);

	if(RetVal == E_OK)
	{
		return 1;//成功
	}
	else
	{
		return 0;//失败
	}
}

void Can_DummyDelay(uint32 loops)
{
    volatile uint32 data = 0xAA55AA55;
	volatile uint32 contor1 = 0;
    volatile uint32 contor2 = loops;

    do
    {
        for (contor1 = 0; contor1 < 0x2FF; contor1++)
        {
            data ^= (1 << contor1) | (0xAAAAAA | contor2);
        }
        contor2--;
    } while( contor2 > 0);
}

