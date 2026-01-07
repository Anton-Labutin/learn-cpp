cmake_minimum_required(VERSION 3.27)
project(ip_filter)

add_library(split split.cpp)
add_library(sort sort.cpp)
add_library(print print.cpp)
add_library(filter filter.cpp)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE split sort print filter)