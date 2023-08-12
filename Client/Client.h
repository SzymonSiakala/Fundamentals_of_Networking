#pragma once
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Client
{
private:
    std::string IP;
    int port;
    int client_socket = -1;

public:
    Client(const std::string& IP, const int port);
    void connect_to_server();
    void run();
};