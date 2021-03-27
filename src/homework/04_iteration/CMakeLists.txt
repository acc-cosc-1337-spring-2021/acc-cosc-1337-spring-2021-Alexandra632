cmake_minimum_required (VERSION 3.8)
project(hw_04_library)

add_library(hw_04_library "dna.cpp" "dna.h")
add_executable(hw_04_exe "main.cpp" "dna.cpp")

