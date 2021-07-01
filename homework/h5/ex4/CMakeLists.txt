cmake_minimum_required(VERSION 3.19)
project(h5_ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 ex4.cpp)
target_link_libraries(ex4 libgmp.so libgmpxx.so)