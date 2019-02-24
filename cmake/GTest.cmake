if (NOT {ExternalProject_FOUND})
    message(STATUS "not find system build in GTest so clone it now")
    include(ExternalProject)
endif ()

ExternalProject_Add(
        GTest
        PREFIX ${CMAKE_BINARY_DIR}/GTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.8.1
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
        LOG_INSTALL ON
)