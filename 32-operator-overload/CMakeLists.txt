cmake_minimum_required(VERSION 3.15)
project(32_operator_overload)

set(CMAKE_CXX_STANDARD 14)

add_executable(32_operator_overload main.cpp Point.cpp Point.h Person.cpp Person.h Student.cpp Student.h Sum.cpp Sum.h)