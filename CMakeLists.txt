cmake_minimum_required(VERSION 3.17)
project(lab2_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories("Header Files")
include_directories("Source Files")

add_executable(lab2_dsa
        "Header Files/Bag.h"
        "Header Files/BagIterator.h"
        "Header Files/ExtendedTest.h"
        "Header Files/ShortTest.h"
        "Source Files/App.cpp"
        "Source Files/Bag.cpp"
        "Source Files/BagIterator.cpp"
        "Source Files/ExtendedTest.cpp"
        "Source Files/ShortTest.cpp")
