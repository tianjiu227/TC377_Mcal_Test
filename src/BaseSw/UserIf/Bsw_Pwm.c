/*
  * Bsw_Pwm.c
 *
 *  Created on: 2025��4��28��
 *      Author: ye.lu1
 */

#include "Bsw_Pwm.h"
#include "IfxGtm_reg.h"

#define FreGtm         100000000
#define FrePwm		   20000
#define FreTick        FreGtm/FrePwm
#define DeadTimeTick   100
#define MIN_DUTY       0.03f
#define MAX_DUTY	   0.97f

void PWM_Init(void)
{
	Pwm_17_GtmCcu6_Init(&Pwm_17_GtmCcu6_Config);
}


float LimitDuty(float duty)
{
    if(duty > MAX_DUTY) return MAX_DUTY;
    if(duty < MIN_DUTY) return MIN_DUTY;
    return duty;
}

void PWM_Update(float* Duty)
{
	float DutyU,DutyV,DutyW;
	DutyU = LimitDuty(*Duty);
	DutyV = LimitDuty(*(Duty+1));
	DutyW = LimitDuty(*(Duty+2));
	GTM_ATOM0_CH6_SR1.U = (FreTick-(FreTick*DutyU-DeadTimeTick))/2;
	GTM_ATOM0_CH6_SR0.U = (FreTick+(FreTick*DutyU-DeadTimeTick))/2;

	GTM_ATOM0_CH1_SR1.U = (FreTick-(FreTick*DutyU+DeadTimeTick))/2;
	GTM_ATOM0_CH1_SR0.U = (FreTick+(FreTick*DutyU+DeadTimeTick))/2;

	GTM_ATOM0_CH4_SR1.U = (FreTick-(FreTick*DutyV-DeadTimeTick))/2;
	GTM_ATOM0_CH4_SR0.U = (FreTick+(FreTick*DutyV-DeadTimeTick))/2;

	GTM_ATOM0_CH5_SR1.U = (FreTick-(FreTick*DutyV+DeadTimeTick))/2;
	GTM_ATOM0_CH5_SR0.U = (FreTick+(FreTick*DutyV+DeadTimeTick))/2;

	GTM_ATOM0_CH2_SR1.U = (FreTick-(FreTick*DutyW-DeadTimeTick))/2;
	GTM_ATOM0_CH2_SR0.U = (FreTick+(FreTick*DutyW-DeadTimeTick))/2;

	GTM_ATOM0_CH3_SR1.U = (FreTick-(FreTick*DutyW+DeadTimeTick))/2;
	GTM_ATOM0_CH3_SR0.U = (FreTick+(FreTick*DutyW+DeadTimeTick))/2;
}

void PWM_Disable(void)
{
	GTM_ATOM0_CH6_SR1.U = FreTick;
	GTM_ATOM0_CH6_SR0.U = 0;

	GTM_ATOM0_CH1_SR0.U = FreTick+1;

	GTM_ATOM0_CH4_SR1.U = FreTick;
	GTM_ATOM0_CH4_SR0.U = 0;

	GTM_ATOM0_CH5_SR0.U = FreTick+1;

	GTM_ATOM0_CH2_SR1.U = FreTick;
	GTM_ATOM0_CH2_SR0.U = 0;

	GTM_ATOM0_CH3_SR0.U = FreTick+1;
}


