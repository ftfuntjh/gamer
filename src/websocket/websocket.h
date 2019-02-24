//
// Created by 曹高阳 on 2019-02-25.
//

#ifndef GAMER_WEBSOCKET_H
#define GAMER_WEBSOCKET_H

#include <string>

namespace gamer {
    class websocket {
    public:
        explicit websocket(std::string &&, std::string &&);

    private:
        int socket;
    };
}


#endif //GAMER_WEBSOCKET_H
