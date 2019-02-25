//
// Created by 曹高阳 on 2019-02-25.
//
#include <websocket/websocket.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace gamer::websocket;
TEST(GAMER_WEBSOCKET, websocket_init_test) {
    websocket w(std::string("test"), std::string("/test"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    int returnValue = RUN_ALL_TESTS();

    return returnValue;
}