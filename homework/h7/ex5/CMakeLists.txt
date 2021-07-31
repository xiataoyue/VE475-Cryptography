cmake_minimum_required(VERSION 3.19)
project(h7_ex5)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex5 main.cpp)
target_link_libraries(ex5 libgmp.so libgmpxx.so)