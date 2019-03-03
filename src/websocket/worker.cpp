//
// Created by 曹高阳 on 2019-02-25.
//

#include "worker.h"
#include <unistd.h>
#include <error.h>
#include <cstring>
#include <iostream>

#define MAX_BUFFER_SIZE 4096

using namespace std;

namespace gamer {
    namespace websocket {
        worker::worker(int socket) : state(worker_status::started),
                                     socket(socket),
                                     t{},
                                     m{},
                                     c_v{} {
            init();
        }

        worker::~worker() {

        }

        void worker::pause() {
            state = worker_status::paused;
        }

        void worker::ready() {
            state = worker_status::ready;
        }

        void worker::stop() {
            state = worker_status::stopped;
        }

        void worker::notice() {
            if (state != worker_status::started) {
                throw runtime_error("can't notice worker thread with not started state");
            }

            c_v.notify_one();
        }

        void worker::init() {
            std::unique_lock<std::mutex> u_l{m};
            c_v.wait(u_l, [&] { return ready(); });
            u_l.unlock();
            run();
        }

        worker::worker_status worker::status() {
            return state;
        }

        void worker::run() {
            char *buffer = new char[MAX_BUFFER_SIZE];
            memset(buffer, 0, sizeof(&buffer));
            size_t read_size = 0;
            size_t idle_size = sizeof(&buffer);
            while (state == worker_status::stopped) {
                if (::read(socket, buffer, idle_size) < 0) {
                    switch (errno) {
                        case EINTR : {
                            cout << "interpret by other signal" << endl;
                            continue;
                        }

                        default:
                            cout << "worker thread id: " << id << "exit by error " << strerror(errno) << endl;
                    }
                }
            }
        }
    }

}