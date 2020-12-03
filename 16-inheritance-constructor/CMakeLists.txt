cmake_minimum_required(VERSION 3.15)
project(16_inheritance_constructor)

set(CMAKE_CXX_STANDARD 14)

add_executable(16_inheritance_constructor main.cpp Person.cpp Person.h Student.cpp Student.h Teacher.cpp Teacher.h EliteStudent.cpp EliteStudent.h)