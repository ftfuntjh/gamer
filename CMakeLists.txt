cmake_minimum_required(VERSION 3.13)

add_compile_options(-std=c++11)

option(ENABLE_TEST "Enable GTest..." NOT)

set(PROJECT_INCLUDE_DIR include)
set(GAMER_SOURCE_DIR ${PROJECT_SOURCE_DIR})
add_subdirectory(src)

if (${ENABLE_TEST})
    add_subdirectory(test)
endif ()