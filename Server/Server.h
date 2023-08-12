#pragma once
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Server
{
private:
	int port;
	int server_socket = -1;

	void handle(const int client_socket);

public:
	Server(const int port);
	void start();
	void run();
};