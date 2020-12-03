cmake_minimum_required(VERSION 3.15)
project(30_inner_class)

set(CMAKE_CXX_STANDARD 14)

add_executable(30_inner_class main.cpp Person.cpp Person.h SuperClass1.cpp SuperClass1.h SuperClass2.cpp SuperClass2.h InnerClass2.cpp InnerClass2.h)