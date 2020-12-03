cmake_minimum_required(VERSION 3.15)
project(15_inheritance)

set(CMAKE_CXX_STANDARD 17)

add_executable(15_inheritance main.cpp Person.cpp Person.h Student.cpp Student.h Teacher.cpp Teacher.h)