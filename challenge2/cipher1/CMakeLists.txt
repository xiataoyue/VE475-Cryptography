cmake_minimum_required(VERSION 3.19)
project(cipher1)

set(CMAKE_CXX_STANDARD 14)

add_executable(g2 main.cpp transform.cpp transform.h aes.c aes.h)