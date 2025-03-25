#include <iostream>

#include "Server.h"

void printMsg(char *msg)
{
    std::cout  <<  "rev msg: " << msg << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Hyy::Server server;
    server.startListen( 8081, printMsg);

    std::getchar();

    server.closeServer();

    std::cout << "Press any key to exit..." << std::endl;
    std::getchar();
    std::cin.get(); // 等待用户按下任意键

    return 0;
}
