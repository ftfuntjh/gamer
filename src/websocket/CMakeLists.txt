project(gamer_websocket)

file(GLOB SOURCE_FILES *.c *.cpp)

add_library(${PROJECT_NAME}
        SHARED
        ${SOURCE_FILES}
        )