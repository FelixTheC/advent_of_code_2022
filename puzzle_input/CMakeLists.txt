cmake_minimum_required(VERSION 3.24)
project(puzzle_input)

set(CMAKE_CXX_STANDARD 20)

add_library(puzzle_input STATIC PuzzleInputLibrary.cpp PuzzleInputLibrary.hpp)
