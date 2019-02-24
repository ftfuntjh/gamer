//
// Created by 曹高阳 on 2019-02-25.
//

#include "websocket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <exception>

namespace gamer {
    websocket::websocket(std::string &&host, std::string &&path,
                         std::string &&ip,
                         unsigned short int &&port) {
        socket = ::socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        ::inet_pton(AF_INET, ip.c_str(), static_cast<void *>(&server_addr));
        if (::bind(socket, reinterpret_cast<sockaddr *>(&server_addr), sizeof(server_addr)) < 0) {
            throw std::runtime_error("bind port error");
        }
    }
}