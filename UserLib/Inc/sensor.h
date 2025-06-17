/*
 * sensor.h
 *
 *  Created on: May 19, 2025
 *      Author: vermilion9312
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#include "gpio_config.h"

typedef enum {
	NO,
	NC,
	SENSOR_TYPE_COUNT
} SensorType;

typedef struct _Sensor Sensor;

struct _Sensor {
	GPIO_Config gpio_config;
	bool (* is_detected)(Sensor*);
	void (* update)(Sensor*, SensorType);
	bool last_state;
	bool state;
};

Sensor* new_Sensor(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* INC_SENSOR_H_ */

