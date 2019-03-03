//
// Created by caogaoyang on 19-3-3.
//

#ifndef PROJECT_LOG_IMPLEMENT_H
#define PROJECT_LOG_IMPLEMENT_H

/*
 * This file for implement the log template function
 * */

#include "log.h"

namespace gamer {
    namespace utils {
        template<class ...Args>
        void log::info(Args &&... args) {

        }

        template<class ...Args>
        void log::error(Args &&... args) {

        }

        template<class ...Args>
        void log::warn(Args &&... args) {

        }
    }
}

#endif //PROJECT_LOG_IMPLEMENT_H