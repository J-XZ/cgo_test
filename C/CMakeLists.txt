cmake_minimum_required(VERSION 3.0)

project(testCQsort C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)

add_library(my_qsort_cmp SHARED c/sort.c)

add_executable(c_test c_main/main.c)

target_link_libraries(c_test my_qsort_cmp)