//
// Created by caogaoyang on 19-3-3.
//

#ifndef PROJECT_LOG_H
#define PROJECT_LOG_H
#define LOG_DEFAULT_OUTPUT_FORMAT "yyyy-MM-dd HH:mm:ss.SSS [file][line][column][state][message]"
namespace gamer {
    namespace utils {
        class log {
        public:
            log(std::string file_path) : log(file_path, false, std::string(LOG_DEFAULT_OUTPUT_FORMAT)) {

            }

            log(std::string file_path, std::string format) : log(file_path,
                                                                 false,
                                                                 format) {
            }

            log(std::string file_path, bool ttf) : log(file_path, ttf, std::string(LOG_DEFAULT_OUTPUT_FORMAT)) {

            }

            log(std::string file_path, bool ttf, std::string format);

            void format(std::string placeholder);

            template<class ...Args>
            void error(Args &&args);

            template<class ...Args>
            void info(Args &&args);

            template<class ...Args>
            void warn(Args &&args);

        private:
            std::string format;
        };
    }
}


#endif //PROJECT_LOG_H
