cmake_minimum_required(VERSION 3.29)
project(matrices)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrices main.cpp
        Matrix.cpp
        Matrix.h
        functions.cpp
        functions.h)
