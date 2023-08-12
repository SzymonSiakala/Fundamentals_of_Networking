#include "Client.h"

Client::Client(const std::string& IP, const int port) : IP(IP), port(port), client_socket(socket(AF_INET, SOCK_STREAM, 0))
{
    if (client_socket == -1)
    {
        throw std::runtime_error("Error creating socket.");
    }
}

void Client::connect_to_server()
{
    sockaddr_in server_addr = {};
    server_addr.sin_family = AF_INET;                                       // Set the address family for the socket to IPv4.
    server_addr.sin_port = htons(port);									    // Set the port number.
    server_addr.sin_addr.s_addr = inet_addr(IP.c_str());					// Set the IP address.

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        throw std::runtime_error("Error connecting to server.");
    }
}

void Client::run()
{
    char buffer[1024] = { 0 };
    while (true)
    {
        std::cout << "Enter message (or 'disconnect' to exit): ";
        std::string message = "";
        std::getline(std::cin, message);

        if (send(client_socket, message.c_str(), message.size(), 0) == -1)
        {
            close(client_socket);
            throw std::runtime_error("Error sending message.");
        }

        if (message == "disconnect")
        {
            close(client_socket);
            std::cout << "Disconnecting." << std::endl;
            break;
        }

        const int bytes = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes <= 0)
        {
            close(client_socket);
            throw std::runtime_error("Error receiving response.");
        }

        std::cout << "Received: " << std::string(buffer, bytes) << std::endl;
    }
}