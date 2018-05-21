#include <iostream>

#include "rpc/server.h"

void hello_world ()
{
    std::cout << "hello world" << std::endl;
}

int main (int argc, char** argv)
{    
    rpc::server server(50000);

    server.bind("hello_world", &hello_world);

    std::cout << "starting server" << std::endl;

    server.run();

    std::cout << "server stopped" << std::endl;

    return EXIT_SUCCESS;
}
