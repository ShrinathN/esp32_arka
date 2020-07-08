#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "main.h"
#include "driver/gpio.h"

#define STATUS_LED_PIN GPIO_NUM_2


//public functions
void GPIO_init(void);
uint16_t GPIO_get_voltage(void);
void GPIO_Blinky_Task(void * arg);
#endif