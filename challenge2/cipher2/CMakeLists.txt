cmake_minimum_required(VERSION 3.19)
project(cipher2)

set(CMAKE_CXX_STANDARD 14)

add_executable(g2 main.cpp idea.cpp idea.h transform.cpp transform.h)