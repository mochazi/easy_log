#include "headers.hpp"

void print_test(){

    std::string test = "This is test!!";
    SYS_LOG(INFO,"------------------------------");
    SYS_LOG(INFO,"%s",test.c_str());
    SYS_LOG(INFO,"------------------------------");
}