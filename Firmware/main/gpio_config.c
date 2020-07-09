#include "gpio_config.h"

/** @brief Initializes all the pins
 * 
 * 
 * @return
*/
void GPIO_init(void)
{
	//setting up ADC
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(ADC_SOLAR_PANEL_CHANNEL, ADC_ATTEN_DB_11);
	adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
	esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, DEFAULT_VREF, adc_chars);

	//setting up GPIO
	gpio_config_t gp;
	//blinky LED
	gp.intr_type = GPIO_INTR_DISABLE;
	gp.mode = GPIO_MODE_OUTPUT;
	gp.pin_bit_mask = (1 << STATUS_LED_PIN);
	gp.pull_down_en = GPIO_PULLDOWN_DISABLE;
	gp.pull_up_en = GPIO_PULLUP_DISABLE;
	gpio_config(&gp);
	gpio_set_level(STATUS_LED_PIN, 1);
}

uint16_t GPIO_get_voltage(void)
{
	uint32_t adc_reading;
	uint16_t counter;
	for(adc_reading = 0, counter = 0; counter < ADC_NUM_SAMPLES; counter++)
	{
		adc_reading += adc1_get_raw(ADC_SOLAR_PANEL_CHANNEL);
	}
	adc_reading /= ADC_NUM_SAMPLES;
	uint32_t calibrated_reading = esp_adc_cal_raw_to_voltage(adc_reading, adc_chars);
	return calibrated_reading;
}

void GPIO_Blinky_Task(void *arg)
{
	uint8_t x = 0;
	while (1)
	{
		x ^= 1;
		gpio_set_level(STATUS_LED_PIN, x);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}