//
// Created by 曹高阳 on 2019-02-25.
//

#ifndef GAMER_WEBSOCKET_H
#define GAMER_WEBSOCKET_H

#include <string>

namespace gamer {
    class websocket {
    public:
        websocket(std::string &&host,
                  std::string &&path,
                  std::string &&ip = std::string{"0.0.0.0"},
                  unsigned short int &&port = 8081);


    private:
        int socket;
    };
}


#endif //GAMER_WEBSOCKET_H
