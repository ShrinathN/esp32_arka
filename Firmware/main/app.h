#ifndef APP_H
#define APP_H

#include "main.h"

#include "lwip/sockets.h"
#include "lwip/tcp.h"
#include "lwip/err.h"

#define HTTP_SERVER_PORT 80

//global variables
int listener_socket; //to listen for incoming connections
int acceptor_socket; //to accept connections
struct sockaddr_in info;
struct sockaddr_in remote;

//public functions

/**
 * @brief The main application
 * 
 * Starts the main application, starts listening on port 80. Sets up the UI
 * @param[in] arg Does nothing
**/
void app_task(void *arg);

/**
 * @brief Initializes the socket, and starts listening
 * 
 * Starts the HTTP server, starts listening on port 80
**/
void http_server_init(void);

#endif