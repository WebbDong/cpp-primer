cmake_minimum_required(VERSION 3.15)
project(41_smart_pointer)

set(CMAKE_CXX_STANDARD 17)

add_executable(41_smart_pointer main.cpp MyAutoPtr.hpp Person.cpp Person.h Student.cpp Student.h)