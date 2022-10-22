#include "headers.hpp"

int main() {

    // 主线程
    print_hello_world();

    // 测试新建线程 id
    std::thread test_thread{print_test};
    test_thread.join();

    pause();

    return 0;
}
