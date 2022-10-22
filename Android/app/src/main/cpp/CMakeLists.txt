# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.11)

# Declares and names the project.

# 项目名和版本号
set(PROJECT_NAME easylog)
set(PROJECT_VERSION 1.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

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

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        easylog

        # Sets the library as a shared library.
        SHARED

        ${DIR_SRCS}

        # Provides a relative path to your source file(s).
        native-lib.cpp)

# 加入头文件
target_include_directories(${PROJECT_NAME} PRIVATE core/include)
target_include_directories(${PROJECT_NAME} PRIVATE utils/include)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        easylog

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})