cmake_minimum_required(VERSION 3.27)
project(Sand_Pile_Model)

set(CMAKE_CXX_STANDARD 14)

include_directories(bin)
include_directories(lib)

add_executable(Sand_Pile_Model
        bin/main.cpp
        bin/main.h
        lib/bit_grid.h
        lib/bit_grid.cpp
        lib/BMP_struct.cpp
        lib/BMP_struct.h
        lib/write_bmp.cpp
        lib/write_bmp.h)
