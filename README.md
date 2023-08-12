# Fundamentals of networking
This program demonstrates a simple TCP socket communication setup between a server and multiple clients using the "socket.h" functionality in Linux. The server allows clients to connect and exchange messages. The following functionality is implemented:

## Server Functionality
- The server listens for incoming connections from clients.
- Upon connection, clients can send messages to the server.
- If a client sends a 'hello' message, the server responds with 'world'.
- For any other message, the server echoes the message back to the client without modification.

## Client Functionality
- The client can connect to the server using its IP address and port number.
- The client can send messages to the server over the established TCP connection.
- It can receive and display responses from the server.
- The client can explicitly send a 'disconnect' command to end the communication.

## Building and Running the Project
To build the project, you can use the provided CMake file:
1. Create a `build` directory in the project root:
   ```bash
   mkdir build
   cd build
   ```
2. Generate the build files using CMake:
   ```bash
   cmake ..
   ```
3. Build the project using the generated build files:
   ```bash
   cmake --build .
   ```
4. Run the server or client executable:
   ```bash
   ./Server_Application
   ./Client_Application
   ```

## Usage
1. **Server:**
   - Compile and run the server program using the provided source code.
   - The server will listen for incoming connections on a specified port.
   - It will process client messages as described above.

2. **Client:**
   - Compile and run the client program using the provided source code.
   - The client can establish a connection to the server by providing the server's IP address and port number.
   - Send messages to the server, receive responses, and handle disconnection using the 'disconnect' command.

Please refer to the source code and comments for detailed implementation details. Enjoy experimenting with this simple TCP socket communication program for Linux!