#include "Server.h"

Server::Server(const int port) : port(port), server_socket(socket(AF_INET, SOCK_STREAM, 0))
{
    if (server_socket == -1)
    {
        throw std::runtime_error("Error creating socket.");
    }
}

void Server::handle(const int client_socket)
{
    char buffer[1024] = { 0 };
    while (true)
    {
        const int bytes = recv(client_socket, buffer, sizeof(buffer), 0);   // Receive message from client and store it in buffer.
        if (bytes <= 0)
        {
            close(client_socket);
            throw std::runtime_error("Client disconnected.");
        }

        const std::string message(buffer, bytes);                           // Convert buffer to std::string.

        if (message == "disconnect")                                        // Check if client requested disconnect.
        {
            close(client_socket);
            std::cout << "Client requested disconnect." << std::endl;
            break;
        }

        std::cout << "Received: " << message << std::endl;

        if (message == "hello")   								            // Check if client sent "hello" message.
        {
            send(client_socket, "world", 5, 0);
        }
        else
        {
            send(client_socket, buffer, bytes, 0);
        }
    }
}

void Server::start()
{
    sockaddr_in server_addr = {};
    server_addr.sin_family = AF_INET;                                       // Set the address family for the socket to IPv4. 
    server_addr.sin_port = htons(port);									    // Set port number.
    server_addr.sin_addr.s_addr = INADDR_ANY;								// Set IP address to any.

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        throw std::runtime_error("Error binding socket.");
    }

    if (listen(server_socket, 5) == -1)
    {
        throw std::runtime_error("Error listening on socket.");
    }

    std::cout << "Server listening on port " << port << "..." << std::endl;
}

void Server::run()
{
    while (true)
    {
        const sockaddr_in client_addr{};
        socklen_t client_addr_size = sizeof(client_addr);
        const int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);   // Accept client connection.
        if (client_socket == -1)
        {
            throw std::runtime_error("Error accepting client connection.");
        }

        std::cout << "Client connected." << std::endl;

        const pid_t pid = fork(); 									        // Create child process.
        if (pid == -1)
        {
            throw std::runtime_error("Error forking process.");
        }
        else if (pid == 0)                                                  // Child process handle communication with the connected client.
        {
            close(server_socket);
            handle(client_socket);
            return;
        }
        else  														        // Parent process handle new client connections.
        {
            close(client_socket);
        }
    }
}