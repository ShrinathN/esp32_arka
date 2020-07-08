#include "app.h"

/**
 * @brief The main application
 * 
 * Starts the main application, starts listening on port 80. Sets up the UI
 * @param[in] arg Does nothing
**/
void app_task(void *arg)
{
	char buffer[] = "HTTP/1.1 200 OK\r\n<html><h1>test</h1></html>\r\n\r\n";
	const char *TAG = "app_task";
	ESP_LOGI(TAG, "Running!");
	http_server_init();
	socklen_t siz = sizeof(struct sockaddr_in);
	while (1)
	{
		acceptor_socket = accept(listener_socket, (struct sockaddr*)&remote, &siz);
		write(acceptor_socket, buffer, strlen(buffer));
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