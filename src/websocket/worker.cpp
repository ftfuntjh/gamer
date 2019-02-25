//
// Created by 曹高阳 on 2019-02-25.
//

#include "worker.h"

using namespace std;

namespace gamer {
    namespace websocket {
        worker::worker() : t{},
                           m{},
                           c_v{} {
        }

        worker::~worker() {

        }

        void worker::pause() {

        }

        void worker::ready() {

        }

        void worker::stop() {

        }

        void worker::notice() {

        }

        void worker::init() {

        }

        worker::worker_status worker::status() {
            return worker_status::paused;
        }
    }

}