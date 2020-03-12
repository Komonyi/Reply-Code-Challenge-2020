cmake_minimum_required(VERSION 3.14)
project(Reply_Code_Challenge_2020)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Reply_Code_Challenge_2020
        main.cpp
        reader.cpp
        structures.h)
