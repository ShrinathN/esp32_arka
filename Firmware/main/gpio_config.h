#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "main.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

//constants
#define ADC_SOLAR_PANEL_CHANNEL ADC_CHANNEL_0
#define STATUS_LED_PIN GPIO_NUM_2
#define DEFAULT_VREF 1100
#define ADC_NUM_SAMPLES 100

//vars
static esp_adc_cal_characteristics_t *adc_chars;

//public functions
void GPIO_init(void);
uint16_t GPIO_get_voltage(void);
void GPIO_Blinky_Task(void * arg);


#endif