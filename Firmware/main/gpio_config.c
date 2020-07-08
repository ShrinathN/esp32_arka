#include "gpio_config.h"

/** @brief Initializes all the pins
 * 
 * 
 * @return
*/
void GPIO_init(void)
{
}

uint16_t GPIO_get_voltage(void)
{
	static uint16_t x = 100;
	x += 100;
	return x;
}