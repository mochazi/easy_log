#ifndef HELLOWORLD_LOG_HPP
#define HELLOWORLD_LOG_HPP

#include "headers.hpp"

// 单条日志最大长度
#define MAX_LOG_BUF_SIZE 77777

enum log_level {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
    VERB
};

// 获取当前线程ID
// 参考链接：https://en.cppreference.com/w/cpp/thread/thread/id/hash
unsigned long getTheadId();

// 获取当前日期和时间的字符串
std::string dateAndTime();

// 如果是Android环境，使用Android的打印方式
#ifdef __ANDROID__

#define LOG_TAG    "native-log"
#define LOG_INFO(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_ERROR(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOG_DEBUG(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOG_WARN(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOG_VERBOSE(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)

//     /data/data/com.mochazi.easylog


#else // 其他平台默认 printf 打印

//  ./xxxx

#define LOG_INFO(...)  printf(__VA_ARGS__)
#define LOG_ERROR(...) printf(__VA_ARGS__)
#define LOG_DEBUG(...) printf(__VA_ARGS__)
#define LOG_WARN(...)  printf(__VA_ARGS__)
#define LOG_VERBOSE(...)  printf(__VA_ARGS__)

#endif

void do_log(enum log_level level, const char *sfile, int sline, const char *sfunc,
            const char *fmt, ...);

#define SYS_LOG(level, fmt, ...) \
    do_log(level, basename(__FILE__), __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);

#endif //HELLOWORLD_LOG_HPP
