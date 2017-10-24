cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(dimmath)

add_executable(test_fold test/test_fold.cpp)
target_include_directories(test_fold PUBLIC ./inc ./thirdparty)

enable_testing()
add_test(NAME test_fold COMMAND test_fold)
