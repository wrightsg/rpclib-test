#include "rpc/client.h"

#include <chrono>
#include <iostream>
#include <thread>

int main (int argc, char** argv)
{
    rpc::client client("127.0.0.1", 50000);

    std::cout << "started client";

    for (auto n=0; n < 10; n++) {
        client.call("hello_world");
        std::cout << "called hello_world" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return EXIT_SUCCESS;
}
