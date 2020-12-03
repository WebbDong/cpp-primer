cmake_minimum_required(VERSION 3.15)
project(14_namespace)

set(CMAKE_CXX_STANDARD 17)

add_executable(14_namespace src/main.cpp src/Car.cpp src/Car.h src/Person.cpp src/Person.h)

target_link_libraries(14_namespace PRIVATE)