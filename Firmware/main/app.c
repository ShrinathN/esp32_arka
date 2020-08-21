#include "app.h"
#include "web_page.h"
#include "gpio_config.h"

/**
 * @brief The main application
 * 
 * Starts the main application, starts listening on port 80. Sets up the UI
 * @param[in] arg Does nothing
**/
void app_task(void *arg)
{
	const char *TAG = "app_task";
	ESP_LOGI(TAG, "Running!");

	char buffer[1024];
	http_server_init();
	socklen_t siz = sizeof(struct sockaddr_in);
	while (1)
	{
		ESP_LOGI(TAG, "Listening! Free Heap: %d", esp_get_free_heap_size());
		acceptor_socket = accept(listener_socket, (struct sockaddr *)&remote, &siz);
		ESP_LOGI(TAG, "Accepted connection!");

		bzero(buffer, sizeof(buffer));
		recv(acceptor_socket, buffer, sizeof(buffer), 0);
		// ESP_LOGI(TAG, "==============\n%s\n===========", buffer);
		if (strstr(buffer, "favicon") != NULL) //error
		{
			ESP_LOGI(TAG, "Favicon, 404!");
			send(acceptor_socket, error_response, strlen(error_response), SOCK_DGRAM);
		}
		else if (strstr(buffer, "event") != NULL) //event
		{
			ESP_LOGI(TAG, "Event!");
			int rc;
			char smallbuff[10];
			while (1)
			{
				bzero(buffer, sizeof(buffer));
				strcat(buffer, event_response);
				sprintf(smallbuff, "%d", GPIO_get_voltage());
				strcat(buffer, smallbuff);
				rc = send(acceptor_socket, buffer, strlen(buffer), 0);
				bzero(buffer, sizeof(buffer));
				ESP_LOGI(TAG, "ADC->%s", smallbuff);
				bzero(smallbuff, sizeof(smallbuff));
				if (rc < 0)
				{
					ESP_LOGI(TAG, "Disconnected! %d", rc);
					break;
				}
				vTaskDelay(pdMS_TO_TICKS(200));
			}
		}
		else
		{
			ESP_LOGI(TAG, "Web page request!");
			send(acceptor_socket, page_data, strlen(page_data), 0);
		}

		shutdown(acceptor_socket, SHUT_RDWR);
	}
}

/**
 * @brief Initializes the socket, and starts listening
 * 
 * Starts the HTTP server, starts listening on port 80
**/
void http_server_init(void)
{
	char one = 1;
	listener_socket = socket(AF_INET, SOCK_STREAM, 0);
	info.sin_addr.s_addr = htonl(INADDR_ANY);
	info.sin_family = AF_INET;
	info.sin_port = htons(HTTP_SERVER_PORT);
	setsockopt(listener_socket, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
	bind(listener_socket, (struct sockaddr *)&info, sizeof(info));
	listen(listener_socket, 10);
}