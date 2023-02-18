cmake_minimum_required(VERSION 3.24)
project(lib_gtest)

set(CMAKE_CXX_STANDARD 17)

add_library(lib_gtest SHARED src/library.cpp src/http_client/HttpClient.cpp)
target_include_directories(lib_gtest PUBLIC src)

add_subdirectory(test)