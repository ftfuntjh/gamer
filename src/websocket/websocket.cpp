//
// Created by 曹高阳 on 2019-02-25.
//

#include "websocket.h"
#include <sys/socket.h>

namespace gamer {
    websocket::websocket(std::string host, std::string path) {
        socket = ::socket(AF_INET, SOCK_STREAM, 0);
    }
}