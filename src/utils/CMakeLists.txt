project(gamer_utils)

file(GLOB source_files *.cpp *.c)

add_library(${PROJECT_NAME}
        SHARED
        ${source_files})