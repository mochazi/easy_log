#include <jni.h>
#include <string>

#include "headers.hpp"

extern "C" JNIEXPORT void JNICALL
Java_com_mochazi_easylog_MainActivity_MainFromJNI(
        JNIEnv* env,
        jobject /* this */)
{

    // 主线程
    print_hello_world();

    // 测试新建线程 id
    std::thread test_thread{print_test};
    test_thread.join();
    pause();

}