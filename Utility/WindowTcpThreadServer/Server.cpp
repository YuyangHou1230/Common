/**
 ******************************************************************************
 * @file           : Server.cpp
 * @author         : hyy
 * @brief          : None
 * @attention      : None
 * @date           : 2024/3/11
 ******************************************************************************
 */

#include "Server.h"

#include <iostream>
#include <ws2tcpip.h>
#include <thread>
#include <map>

#pragma comment(lib, "ws2_32.lib") // 链接到ws2_32.lib库

const int BUFFER_SIZE = 1024;

namespace Hyy
{
    int Server::startListen(int port, HandleFunc func)
    {
        // 初始化Winsock库
        WSADATA wsa_data;
        int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
        if (result != 0)
        {
            std::cerr << "WSAStartup failed: " << result << std::endl;
            return 1;
        }

        // 创建服务器套接字
        SOCKET server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (server_socket == INVALID_SOCKET)
        {
            std::cerr << "Error creating socket: " << WSAGetLastError() << std::endl;
            WSACleanup();
            return 1;
        }

        // 设置服务器地址和端口
        sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        // 将套接字绑定到端口
        if (bind(server_socket, reinterpret_cast<sockaddr *>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR)
        {
            std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
            closesocket(server_socket);
            WSACleanup();
            return 1;
        }

        // 监听连接请求
        if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR)
        {
            std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
            closesocket(server_socket);
            WSACleanup();
            return 1;
        }

        std::cout << "Server listening on port " << port << std::endl;

        std::thread listenThread(&Server::exec, this, server_socket, func);
        listenThread.detach();

        return 0;
    }

    Server::Server()
    {
        should_listen.store(true);
    }

    Server::~Server()
    {
    }

    void Server::exec(SOCKET server_socket, HandleFunc func)
    {
        // 接受客户端连接
        SOCKET client_socket;
        sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);

        std::map<std::string, int> maps;

        while (should_listen.load())
        {

            client_socket = accept(server_socket, reinterpret_cast<sockaddr *>(&client_addr), &client_addr_len);
            // 获取客户端 IP 和端口
            char client_ip[INET_ADDRSTRLEN];
            strcpy(client_ip, inet_ntoa(client_addr.sin_addr));
            int client_port = ntohs(client_addr.sin_port);

            if (client_socket == INVALID_SOCKET)
            {
                std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;

            }
            else
            {

                std::string addr = std::string(client_ip);
                maps.insert({addr, client_port});

                std::cout << "New connection from " << client_ip << ":" << client_port << std::endl;

                char buffer[BUFFER_SIZE];
                const char *hello = "Hello from server";

                // 接收和发送数据

                while (1)
                {
                    int bytes_received = 0;
                    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
                    if(bytes_received > 0)
                    {
                        buffer[bytes_received] = '\0'; // 添加字符串结束符
                        std::cout << "Client: " << buffer << std::endl;
    
                        func(buffer);
    
                        send(client_socket, hello, strlen(hello), 0);
                        std::cout << "Hello message sent" << std::endl;
                    }
                    else if(bytes_received < 0)
                    {
                        std::string addr = std::string(client_ip);
                        std::map<std::string, int>::iterator ite = maps.find(addr);
                        if (ite != maps.end())
                        {
                            std::cout << "client " << client_ip << ":" << client_port << " disconnection from server" << std::endl;
                            maps.erase(ite);
                        }
                        break;
                    }
                    else
                    {
                        std::cout << "unkown error " << std::endl;
                        break;
                    }
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        // 关闭套接字并清理Winsock库
        closesocket(client_socket);
        closesocket(server_socket);
        WSACleanup();

        std::cout << "close server" << std::endl;
    }

    void Server::closeServer()
    {
        should_listen.store(false);
    }
}