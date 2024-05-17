cmake_minimum_required(VERSION 3.28)
project(reference_counter)

set(CMAKE_CXX_STANDARD 17)

add_executable(reference_counter main.cpp
        counter_ptr.h
        array_cell.h
        stack.cpp
        stack.h)
