# CMakeList.txt : CMake project for Lab4, include source and define
# project specific logic here.
#
project ("Week8")
cmake_minimum_required (VERSION 3.1)

# Add source to this project's executable.
add_library(Lab8 SHARED Week8.cpp Week8.h)

# TODO: Add tests and install targets if needed.
target_include_directories(Lab8 PRIVATE
"C:\\Program Files\\Java\\jdk-11.0.10\\include"
"C:\\Program Files\\Java\\jdk-11.0.10\\include\\win32")