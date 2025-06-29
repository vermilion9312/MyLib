/*
 * rc_servo.c
 *
 *  Created on: Jun 26, 2025
 *      Author: vermi
 */


#include "rc_servo.h"


RC_Servo* new_RC_Servo(TIM_TypeDef* htim, uint32_t channel)
{
	RC_Servo* this = malloc(sizeof(RC_Servo));
//
//	this->htim = htim;
//	this->htim->Instance->CCMR2
//	TIM1.


//	HAL_TIM_PWM_Start(htim, Channel);
}
