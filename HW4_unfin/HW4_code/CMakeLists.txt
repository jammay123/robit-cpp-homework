cmake_minimum_required(VERSION 3.5)

project(HW4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HW4 main.cpp myvector.h myvector.cpp)
