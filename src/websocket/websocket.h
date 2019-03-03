//
// Created by 曹高阳 on 2019-02-25.
//

#ifndef GAMER_WEBSOCKET_H
#define GAMER_WEBSOCKET_H

#include "worker.h"
#include <string>

namespace gamer {
    namespace websocket {
        class websocket : public worker {
        public:
            websocket(std::string &&host,
                      std::string &&path,
                      std::string &&ip = std::string{"127.0.0.1"},
                      unsigned short int &&port = 8082);

            void start_worker();

        private:

            int socket;
        };
    }
}


#endif //GAMER_WEBSOCKET_H
