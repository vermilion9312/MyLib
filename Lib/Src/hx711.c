/*
 * hx711.c
 *
 *  Created on: May 20, 2025
 *      Author: LeeJooHo
 */


#include "hx711.h"

static void HX711_Delay_us(uint32_t us) {
    uint32_t start = DWT->CYCCNT;
    uint32_t ticks = us * (HAL_RCC_GetHCLKFreq() / 1000000);
    while ((DWT->CYCCNT - start) < ticks);
}

static void DWT_Init(void) {
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}

void HX711_Init(void) {
    HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_RESET);
    DWT_Init();  // 딜레이용 DWT 초기화
}

int32_t HX711_ReadRaw(void) {
    uint32_t data = 0;

    // 데이터 준비 대기 (DT가 LOW가 될 때까지)
    while (HAL_GPIO_ReadPin(HX711_DT_GPIO_Port, HX711_DT_Pin) == GPIO_PIN_SET);

    // 24비트 데이터 수신
    for (int i = 0; i < 24; i++) {
        HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_SET);
        HX711_Delay_us(1);
        data = (data << 1) | HAL_GPIO_ReadPin(HX711_DT_GPIO_Port, HX711_DT_Pin);
        HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_RESET);
        HX711_Delay_us(1);
    }

    // 25번째 클럭: 채널 A, gain 128
    HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_SET);
    HX711_Delay_us(1);
    HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_RESET);
    HX711_Delay_us(1);

    // 부호 확장
    if (data & 0x800000) {
        data |= 0xFF000000;
    }

    return (int32_t)data;
}
