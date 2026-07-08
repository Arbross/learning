cmake_minimum_required(VERSION 3.26)
project(zapasWody)

set(CMAKE_CXX_STANDARD 17)

add_executable(zapasWody main.cpp
        zapas_wody.h
        zapas_wody.cpp)
