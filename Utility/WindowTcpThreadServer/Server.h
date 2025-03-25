/**
  ******************************************************************************
  * @file           : Server.h
  * @author         : hyy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/11
  ******************************************************************************
  */

#ifndef CPP_STUDY_SERVER_H
#define CPP_STUDY_SERVER_H

#include <atomic>
#include <winsock2.h> // 包含Winsock2库

typedef void (*HandleFunc)(char *);

namespace Hyy
{

    class Server {
    public:
        Server();
        ~Server();
        int startListen(int port, HandleFunc func);

        void closeServer();

    private:
        void exec(SOCKET socket, HandleFunc func);

    private:
        std::atomic<bool> should_listen;
    };
}




#endif //CPP_STUDY_SERVER_H
