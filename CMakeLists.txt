cmake_minimum_required(VERSION 3.10)
project(mini_STL)

set(CMAKE_CXX_STANDARD 11)

add_executable(mini_STL main.cpp myVector.cpp myVector.h myIterator.cpp myIterator.h)