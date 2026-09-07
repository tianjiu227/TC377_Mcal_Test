#include "User_Pwm.h"

/*************************************PWM Demo**********************************************************/

uint32	Pwm_SetDutyNumber		= 2500;
uint32	Pwm_SetPeriodNumber		= 5000;
uint8   PwmDebugFlag			= 2;
uint8   PwmOutStateflag0			= 0;
uint8   PwmOutStateflag1			= 0;
void PWM_DemoFunction(void)
{
    /* Pwm Initialization */
    Pwm_17_GtmCcu6_Init(&Pwm_17_GtmCcu6_Config);

	while(1)
	{
		if(PwmDebugFlag==1)
		{
			/* 改变周期和占空比 */
			Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_9,Pwm_SetPeriodNumber,Pwm_SetDutyNumber);
			//Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_ATOM2_2,Pwm_SetPeriodNumber,Pwm_SetDutyNumber);
		}
		else if(PwmDebugFlag==2)
		{
			/* 改变占空比 */
			Pwm_17_GtmCcu6_SetDutyCycle(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_9,Pwm_SetDutyNumber);
			//Pwm_17_GtmCcu6_SetDutyCycle(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_ATOM2_2,Pwm_SetDutyNumber);
		}
		else if(PwmDebugFlag==3)
		{
			/* 将指定的 PWM 通道输出设置为空闲状态（Idle State），当前Idle State是低电平 */
			Pwm_17_GtmCcu6_SetOutputToIdle(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_9);
			//Pwm_17_GtmCcu6_SetOutputToIdle(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_ATOM2_2);
		}

		/* 读取指定 PWM 通道当前的实际输出电平状态（高电平或低电平） */
		PwmOutStateflag0 = Pwm_17_GtmCcu6_GetOutputState(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_P2_9);
		//PwmOutStateflag1 = Pwm_17_GtmCcu6_GetOutputState(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_ATOM2_2);
	}
}



