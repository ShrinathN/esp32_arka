#include "gpio_config.h"

/** @brief Initializes all the pins
 * 
 * 
 * @return
*/
void GPIO_init(void)
{
	gpio_config_t gp;
	gp.intr_type = GPIO_INTR_DISABLE;
	gp.mode = GPIO_MODE_OUTPUT;
	gp.pin_bit_mask = ( 1 << STATUS_LED_PIN);
	gp.pull_down_en = GPIO_PULLDOWN_DISABLE;
	gp.pull_up_en = GPIO_PULLUP_DISABLE;
	gpio_config(&gp);

	gpio_set_level(STATUS_LED_PIN, 1);
}

uint16_t GPIO_get_voltage(void)
{
	static uint16_t x = 100;
	x += 100;
	return x;
}

void GPIO_Blinky_Task(void * arg)
{
	uint8_t x = 0;
	while(1)
	{
		x ^= 1;
		gpio_set_level(STATUS_LED_PIN, x);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}