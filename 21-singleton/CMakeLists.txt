cmake_minimum_required(VERSION 3.15)
project(21_singleton)

set(CMAKE_CXX_STANDARD 14)

add_executable(21_singleton main.cpp EarlySingleton.h EarlySingleton.cpp LazilySingleton.cpp LazilySingleton.h)