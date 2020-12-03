cmake_minimum_required(VERSION 3.15)
project(19_multiple_inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(19_multiple_inheritance main.cpp Person.cpp Person.h Consts.h Student.cpp Student.h Worker.cpp Worker.h Undergraduate.cpp Undergraduate.h)