//
// Created by caogaoyang on 19-3-3.
//

#ifndef PROJECT_LOG_H
#define PROJECT_LOG_H

#include <iostream>
#include <memory>

#define LOG_DEFAULT_OUTPUT_FORMAT "yyyy-MM-dd HH:mm:ss.SSS [file][line][column][state][message]"
namespace gamer {
    namespace utils {
        class log {
        public:
            static std::shared_ptr<log> getInstance(std::string file_path) {
                static std::shared_ptr<log> instance_ptr = nullptr;
                if (!instance_ptr) {
                    instance_ptr = std::make_shared<log>(file_path);;
                }
                return instance_ptr;
            }

            log(std::string file_path) : log(std::move(file_path), false, std::string(LOG_DEFAULT_OUTPUT_FORMAT)) {

            }

            log(std::string file_path, std::string format) : log(std::move(file_path),
                                                                 false,
                                                                 std::move(format)) {
            }

            log(std::string file_path, bool ttf) : log(std::move(file_path), ttf,
                                                       std::string(LOG_DEFAULT_OUTPUT_FORMAT)) {

            }

            log(std::string file_path, bool ttf, std::string format);

            void setFormat(std::string placeholder);

            template<class ...Args>
            void error(Args &&... args);

            template<class ...Args>
            void info(Args &&... args);

            template<class ...Args>
            void warn(Args &&... args);

            void message(std::string &&message);

        private:
            std::string format;
        };
    }
}


#endif //PROJECT_LOG_H
