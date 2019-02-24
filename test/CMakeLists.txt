find_package(GTest)
if (NOT ${GTEST_FOUND})
    message(STATUS "package Gtest not found")
    include(${PROJECT_SOURCE_DIR}/cmake/GTest.cmake)
endif ()

add_subdirectory(websocket)