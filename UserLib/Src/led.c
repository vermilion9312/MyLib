/*
 * led.c
 *
 *  Created on: May 19, 2025
 *      Author: vermilion9312
 */


#include "led.h"

static void turn_on(LED* this)
{
	HAL_GPIO_WritePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin, GPIO_PIN_RESET);
}

static void turn_off(LED* this)
{
	HAL_GPIO_WritePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin, GPIO_PIN_SET);
}

static void toggle(LED* this)
{
	HAL_GPIO_TogglePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
}

static void test(LED* this, uint32_t timeout)
{
	static bool init_flag;
	static uint32_t last_tick;
	uint32_t current_tick = HAL_GetTick();

	if (!init_flag)
	{
		last_tick = current_tick;
		init_flag = true;

		return;
	}

	if (current_tick - last_tick > timeout)
	{
		HAL_GPIO_TogglePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
		last_tick += timeout;
	}
}

LED* new_LED(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	LED* this = malloc(sizeof(LED));

	this->gpio_config.GPIOx    = GPIOx;
	this->gpio_config.GPIO_Pin = GPIO_Pin;
	this->turn_on              = turn_on;
	this->turn_off             = turn_off;
	this->toggle               = toggle;
	this->test                 = test;

	return this;
}
