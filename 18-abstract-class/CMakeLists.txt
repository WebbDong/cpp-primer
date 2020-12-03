cmake_minimum_required(VERSION 3.15)
project(18_abstract_class)

set(CMAKE_CXX_STANDARD 14)

add_executable(18_abstract_class main.cpp Animal.cpp Animal.h Consts.h Cat.cpp Cat.h Dog.cpp Dog.h)