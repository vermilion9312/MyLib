/*
 * rc_servo.h
 *
 *  Created on: Jun 26, 2025
 *      Author: vermi
 */

#ifndef INC_RC_SERVO_H_
#define INC_RC_SERVO_H_

#include "stm32f4xx_hal.h"

typedef struct _RC_Servo RC_Servo;

typedef struct {
	uint16_t ccr_min;
	uint16_t ccr_max;
} PWM_Range;

struct _RC_Servo {
	TIM_HandleTypeDef* htim;
	uint32_t           channel;
	PWM_Range          pwm_range;

	void (* set_angle)(RC_Servo*, uint8_t);

};

#endif /* INC_RC_SERVO_H_ */
