//
// Created by 曹高阳 on 2019-02-25.
//

#include "websocket.h"
#include <iostream>
#include <exception>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstring>
#include <cerrno>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

namespace gamer {
    namespace websocket {
        websocket::websocket(string &&host,
                             string &&path,
                             string &&ip,
                             unsigned short int &&port)
                : worker(port) {
            socket = ::socket(AF_INET, SOCK_STREAM, 0);
            if (socket == -1) {
                throw runtime_error("socket failed");
            }
            sockaddr_in server_addr{};
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port);
            server_addr.sin_addr.s_addr = ::inet_addr(ip.c_str());
            if (::bind(socket, reinterpret_cast<sockaddr *> (&server_addr), sizeof(server_addr)) < 0) {
                throw runtime_error("bind port error");
            }
        }

        void websocket::start_worker() {
            sockaddr_in client_addr{};
            socklen_t socklen;
            if (::listen(socket, 20) < 0) {
                throw runtime_error("listen failed");
            };
            if (::accept(socket, reinterpret_cast< sockaddr *>(&client_addr), &socklen) < 0) {
                cout << ::strerror(errno) << endl;
                throw runtime_error("accept client connection failed");
            }
        }
    }
}