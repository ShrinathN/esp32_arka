#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include "main.h"

//other includes
#include "esp_wifi.h"
#include "lwip/tcp.h"
#include "lwip/sockets.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "esp_netif.h"

#define AP_SSID "Shinu BSNL"
#define AP_PASS "987654321"

/**
 * @brief Initializes the WiFi Connection to the AP
 * 
 * Connects to the AP with SSID and Password as AP_SSID and AP_PASS
**/
void connect_wifi_function();


/**
 * @brief Event handler for WiFi connection
 * 
 * @param[in] event_base the base id of the event to register the handler for
 * @param[in] event_id the id of the event to register the handler for
 * @param[in] event_handler the handler function which gets called when the event is dispatched
 * @param[in] event_handler_arg data, aside from event data, that is passed to the handler when it is called
**/
void wifi_event_handler(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data);

#endif