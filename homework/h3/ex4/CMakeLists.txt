cmake_minimum_required(VERSION 3.16)
project(ex4 C)

set(CMAKE_C_STANDARD 11)

add_executable(aes main.c aes.c aes.h)
add_executable(sbox sbox.c)