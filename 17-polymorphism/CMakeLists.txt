cmake_minimum_required(VERSION 3.15)
project(17_polymorphism)

set(CMAKE_CXX_STANDARD 14)

add_executable(17_polymorphism main.cpp Animal.cpp Animal.h Dog.cpp Dog.h Cat.cpp Cat.h Consts.h)