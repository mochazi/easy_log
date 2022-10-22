#ifndef HELLOWORLD_HEADERS_HPP
#define HELLOWORLD_HEADERS_HPP

// c++
#include <iostream>
#include <cstdio>
#include <thread>
#include <cstring>
#include <cstdarg>
#include <sstream>

// c
#include <unistd.h>

// Cygwin条件编译
#ifdef __CYGWIN__
#include <libgen.h>
#endif

// Android条件编译
#ifdef __ANDROID__
#include <android/log.h>
#include <libgen.h>
#endif

// 日志
#include "log.hpp"

// 业务
#include "hello_world.hpp"
#include "test.hpp"

#endif //HELLOWORLD_HEADERS_HPP
