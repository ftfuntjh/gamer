//
// Created by 曹高阳 on 2019-02-25.
//

#ifndef PROJECT_WORKER_H
#define PROJECT_WORKER_H

#include <thread>
#include <condition_variable>
#include <mutex>

namespace gamer {
    namespace websocket {
        class worker {
        public:
            enum class worker_status {
                ready,
                started,
                paused,
                stopped
            };

            explicit worker(int socket);

            ~ worker();

            virtual void init();

            virtual worker_status status();

            virtual void ready();

            virtual void pause();

            virtual void stop();

            virtual void notice();

            virtual void run();

        private:
            std::string id;
            int socket;
            worker_status state;
            std::mutex m;
            std::thread t;
            std::condition_variable c_v;
        };
    }
}


#endif //PROJECT_WORKER_H
