/*
 * led.h
 *
 *  Created on: May 19, 2025
 *      Author: vermilion9312
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "gpio_config.h"

typedef struct _LED LED;

struct _LED {
	GPIO_Config gpio_config;
	void (* turn_on)(LED*);
	void (* turn_off)(LED*);
	void (* toggle)(LED*);
	void (* test)(LED*, uint32_t);
};

LED* new_LED(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* INC_LED_H_ */
