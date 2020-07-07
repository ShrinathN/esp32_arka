#include "wifi_config.h"
#include "app.h"

/**
 * @brief Initializes the WiFi Connection to the AP
 * 
 * Connects to the AP with SSID and Password as AP_SSID and AP_PASS
**/
void connect_wifi_function()
{
	const char * TAG = "connect_wifi_function";
	ESP_LOGI(TAG, "Running!");
	//creating netif, and event loop
	ESP_ERROR_CHECK(esp_netif_init());
	ESP_ERROR_CHECK(esp_event_loop_create_default());
	esp_netif_create_default_wifi_sta();

	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK(esp_wifi_init(&cfg);

	ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL));
	ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL));

	wifi_config_t wcfg = {
		.sta = {
			.ssid = AP_SSID,
			.password = AP_PASS
		},
	};

	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
	ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wcfg));
	ESP_ERROR_CHECK(esp_wifi_start());
}

/**
 * @brief Event handler for WiFi connection
 * 
 * @param[in] event_base the base id of the event to register the handler for
 * @param[in] event_id the id of the event to register the handler for
 * @param[in] event_handler the handler function which gets called when the event is dispatched
 * @param[in] event_handler_arg data, aside from event data, that is passed to the handler when it is called
**/
void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
	const char * TAG = "wifi_event_handler";
	ESP_LOGI(TAG, "Running! %s %d", event_base, event_id);
	if (event_base == WIFI_EVENT)
	{
		if (event_id == WIFI_EVENT_STA_START)
		{
			esp_wifi_connect();
		}
		else if (event_id == WIFI_EVENT_STA_DISCONNECTED)
		{
			esp_wifi_connect();
		}
	}
	else if (event_base == IP_EVENT)
	{
		if (event_id == IP_EVENT_STA_GOT_IP)
		{
			xTaskCreate(app_task, "app_task", 4096, NULL, 10, NULL);
		}
	}
}