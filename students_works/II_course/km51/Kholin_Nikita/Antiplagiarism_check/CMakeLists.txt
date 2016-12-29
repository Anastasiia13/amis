cmake_minimum_required(VERSION 3.6)
project(Antiplagiat_check)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c input_works.h plagiarism_check.h output_results.h work.h student.h DEAD.h)
add_executable(Antiplagiat_check ${SOURCE_FILES})