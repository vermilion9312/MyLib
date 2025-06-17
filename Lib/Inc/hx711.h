/*
 * hx711.h
 *
 *  Created on: May 20, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_HX711_H_
#define INC_HX711_H_

#include "main.h"
#include "stm32f4xx_hal.h"

// HX711 핀 설정 (사용자 설정에 맞게 수정)
#define HX711_DT_GPIO_Port  INPUT_CH6_GPIO_Port
#define HX711_DT_Pin        INPUT_CH6_Pin
#define HX711_SCK_GPIO_Port OUTPUT_CH12_GPIO_Port
#define HX711_SCK_Pin       OUTPUT_CH12_Pin

void HX711_Init(void);
int32_t HX711_ReadRaw(void);

#endif /* INC_HX711_H_ */
