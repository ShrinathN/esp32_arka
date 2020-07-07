#include "main.h"
#include "wifi_config.h"
#include "gpio_config.h"

void app_main(void)
{
	const char *TAG = "app_main";
	ESP_LOGI(TAG, "Running!");

	connect_wifi_function();

}
