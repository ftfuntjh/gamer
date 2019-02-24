project(weboscket_init_test)

include_directories(${GAMER_SOURCE_DIR}/src)

set(gmock_SOURCE_DIR ${CMAKE_BINARY_DIR}/GTest/src/GTest/googlemock/include)
set(gtest_SOURCE_DIR ${CMAKE_BINARY_DIR}/GTest/src/GTest/googletest/include)
set(glist_LIBRARY_DIR ${CMAKE_BINARY_DIR}/GTest/src/GTest-build/googlemock/gtest/)
set(gmock_LIBRARY_DIR ${CMAKE_BINARY_DIR}/GTest/src/GTest-build/googlemock/)
link_directories(${glist_LIBRARY_DIR} ${gmock_LIBRARY_DIR})

add_executable(${PROJECT_NAME} websocket.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${gtest_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${gmock_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} gmock)
add_dependencies(${PROJECT_NAME} GTest)

add_test(websocket_init
        COMMAND ${PROJECT_NAME}

        )