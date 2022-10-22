#include "headers.hpp"

void print_hello_world()
{
    std::string hello = "Hello World!!";
    SYS_LOG(INFO,"------------------------------");
    SYS_LOG(INFO,"%s",hello.c_str());
    SYS_LOG(INFO,"------------------------------");
}