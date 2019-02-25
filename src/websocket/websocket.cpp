//
// Created by 曹高阳 on 2019-02-25.
//

#include "websocket.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <exception>

using namespace std;

namespace gamer {
    namespace websocket {
        websocket::websocket(string &&host,
                             string &&path,
                             string &&ip,
                             unsigned short int &&port) {
            socket = ::socket(AF_INET, SOCK_STREAM, 0);
            sockaddr_in server_addr{};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port);
            ::inet_pton(AF_INET, ip.c_str(), static_cast<void *>(&server_addr));
            if (::bind(socket, reinterpret_cast<sockaddr *>(&server_addr), sizeof(server_addr)) < 0) {
                throw runtime_error("bind port error");
            }
        }

        void websocket::start_worker() {

        }
    }

}