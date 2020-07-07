#include "main.h"
#include "wifi_config.h"
#include "gpio_config.h"

//nvs
#include "nvs_flash.h"
//power management
#include "esp_pm.h"
#include "esp32/pm.h"

void app_main(void)
{
	const char *TAG = "app_main";
	ESP_LOGI(TAG, "Running!");

	int rc;
	//power management config
	esp_pm_config_esp32_t pm_confg;
	pm_confg.light_sleep_enable = 1;
	pm_confg.max_freq_mhz = 240;
	pm_confg.min_freq_mhz = 80;
	
	//initializing NVS
	rc = nvs_flash_init();
	if(rc != ESP_OK)
	{
		ESP_LOGE(TAG, "Could not init flash! %d", rc);
		nvs_flash_erase();
		nvs_flash_init();
	}

	//configuring pm
	esp_pm_configure(&pm_confg);

	//connecting to WiFi
	connect_wifi_function();

	//infinite loop
	while(1)
	{
		vTaskDelay(pdMS_TO_TICKS(1000));
	}

}
