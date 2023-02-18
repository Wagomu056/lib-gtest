project(test_lib_gtest)
set(CMAKE_CXX_STANDARD 14)

add_executable(test test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(test GTest::gtest GTest::gtest_main GTest::gmock)

target_link_libraries(test lib_gtest)
