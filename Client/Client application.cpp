// Apriorit Poland Summer 2023 Internship Program
// Fundamentals of networking - Client
// Szymon Siąkała

#include "Client.h"

int main()
{
    try
    {
        Client client("127.0.0.1", 12345);
        client.connect_to_server();
        client.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return 0;
}
