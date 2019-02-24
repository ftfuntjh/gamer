//
// Created by 曹高阳 on 2019-02-25.
//
#include <websocket/websocket.h>
#include "gmock/gmock.h"

TEST(GAMER_WEBSOCKET, websocket_init_test) {
    gamer::websocket w{std::string{"test.com"}, std::string{"/test"}};
}