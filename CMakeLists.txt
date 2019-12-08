cmake_minimum_required(VERSION 3.15)
project(lds)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(lds
        includes/Stack.h
        includes/Text.h
        includes/WordsList.h
        source/main.cpp
        source/Stack.cpp
        source/Text.cpp
        source/WordsList.cpp)
