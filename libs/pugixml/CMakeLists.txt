cmake_minimum_required(VERSION 3.22)
add_library(pugixml pugixml.cpp pugixml.hpp pugiconfig.hpp)
target_include_directories(pugixml PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
