cmake_minimum_required(VERSION 3.23)
project(CPU)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPU
        main.cpp
        PCB.cpp
        PCB.h
        processor.cpp
        processor.h
        scheduler.cpp
        scheduler.h)
