cmake_minimum_required (VERSION 3.10)
project(Fundamentals_Of_Networking)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Server Application
add_executable (Server_Application "Server/Server application.cpp" "Server/Server.h" "Server/Server.cpp")

# Client Application
add_executable (Client_Application "Server/Server application.cpp" "Server/Server.h" "Server/Server.cpp")