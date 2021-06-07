cmake_minimum_required(VERSION 3.19)
project(ex4 C)

set(CMAKE_C_STANDARD 11)

add_executable(ex4 main.c aes.c aes.h)
add_executable(sbox sbox.c)