cmake_minimum_required(VERSION 3.15)
project(3_extern_c)

set(CMAKE_CXX_STANDARD 20)

add_executable(3_extern_c main.cpp math.h math.c other.c)