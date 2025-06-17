/*
 * sensor.c
 *
 *  Created on: May 19, 2025
 *      Author: vermilion9312
 */


#include "sensor.h"

static bool is_detected(Sensor* this)
{
	if (!this->last_state && this->state)
	{
		return true;
	}

	this->last_state = this->state;

	return false;
}

static void update(Sensor* this, SensorType sensor_type)
{
	if (sensor_type == NO)
	{
		this->state = !HAL_GPIO_ReadPin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
		return;
	}

	if (sensor_type == NC)
	{
		this->state = HAL_GPIO_ReadPin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
	}
}

Sensor* new_Sensor(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	Sensor* this = calloc(1, sizeof(Sensor));

	this->gpio_config.GPIOx    = GPIOx;
	this->gpio_config.GPIO_Pin = GPIO_Pin;
	this->is_detected          = is_detected;
	this->update               = update;

	return this;
}
