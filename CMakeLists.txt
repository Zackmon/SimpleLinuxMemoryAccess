cmake_minimum_required(VERSION 3.16)
project(cpp)

set(CMAKE_CXX_STANDARD 14)


add_library(cpp SHARED library.cpp library.h)

set_target_properties(cpp PROPERTIES OUTPUT_NAME "MemoryManagement")
