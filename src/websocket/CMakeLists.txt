project(gamer_websocket)

file(GLOB SOURCE_FILES *.c *.cpp)

add_library(${PROJECT_NAME}
        SHARED
        ${SOURCE_FILES}
        ../utils/log.cpp ../utils/log.h request_context.cpp request_context.h buffer.cpp buffer.h)

target_link_libraries(${PROJECT_NAME} pthread gamer_utlis)
add_dependencies(gamer_websocket gamer_utils)