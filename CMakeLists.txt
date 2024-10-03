cmake_minimum_required(VERSION 3.28)
project(boogiewoogie)

set(CMAKE_CXX_STANDARD 17)

add_executable(boogiewoogie main.cpp
        AritistBuilder.cpp
        AritistBuilder.hpp
        FileProxy.cpp
        FileProxy.hpp
        WebReader.cpp
        WebReader.hpp
        FileReader.cpp
        FileReader.hpp)
