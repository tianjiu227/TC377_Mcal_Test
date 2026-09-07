/*
 * Bsw_Pwm.h
 *
 *  Created on: 2025Äê4ÔÂ28ÈÕ
 *      Author: ye.lu1
 */

#ifndef BSW_PWM_H_
#define BSW_PWM_H_

#include "Pwm_17_GtmCcu6.h"

extern void PWM_Init(void);
extern float LimitDuty(float duty);
extern void PWM_Update(float* Duty);
extern void PWM_Disable(void);

#endif /* BSW_PWM_H_ */

