cmake_minimum_required(VERSION 3.11)

# 项目名和版本号
set(PROJECT_NAME easy_log)
set(PROJECT_VERSION 1.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# -------------------------------------------------------------------------------

# 开启debug模式
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

# 开启Release模式
#SET(CMAKE_BUILD_TYPE "Release")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# -------------------------------------------------------------------------------

# 设置C++11标准
set(CMAKE_CXX_STANDARD 11)

# 本项目
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/core/src DIR_CORE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/utils/src DIR_UTILS)

# 输出详细信息
set(CMAKE_VERBOSE_MAKEFILE ON)

# 添加所需编译文件（全部塞到一起）
list(APPEND DIR_SRCS ${DIR_CORE})
list(APPEND DIR_SRCS ${DIR_UTILS})

# 开始编译
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 添加链接库 (pthread 为线程库，m 为数学库)
target_link_libraries(${PROJECT_NAME} pthread m)

# 加入头文件
target_include_directories(${PROJECT_NAME} PRIVATE core/include)
target_include_directories(${PROJECT_NAME} PRIVATE utils/include)