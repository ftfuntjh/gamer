//
// Created by caogaoyang on 19-3-3.
//

#ifndef PROJECT_BUFFER_H
#define PROJECT_BUFFER_H

/*
 * This class used to hold the client's request header and body.
 * request_context class will need this info for a websocket handshake && websocket disconnection
 * all the buffer will been stored in a linked list,each node has different capacity for most all request;
 * */

namespace gamer {
    namespace websocket {
        class buffer {

        };
    }
}



#endif //PROJECT_BUFFER_H
