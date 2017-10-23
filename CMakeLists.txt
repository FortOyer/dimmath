cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(dimmath)

add_executable(test_vector test/test_vector.cpp)
target_include_directories(test_vector PUBLIC ./inc ./thirdparty)

enable_testing()
add_test(NAME test_vector COMMAND test_vector)
