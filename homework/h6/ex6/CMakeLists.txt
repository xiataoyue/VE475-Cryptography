cmake_minimum_required(VERSION 3.15)
project(ex6)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex6 ex6.cpp)
add_executable(ex6_gmp ex6_gmp.cpp)
target_link_libraries(ex6_gmp libgmp.so libgmpxx.so)