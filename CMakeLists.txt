cmake_minimum_required(VERSION 3.28)
set(PROJECT_NAME boogiewoogie)
project(PROJECT_NAME)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROJECT_NAME main.cpp
        Builders/AritistBuilder.cpp
        Builders/AritistBuilder.hpp
        FileReading/WebReader.cpp
        FileReading/WebReader.hpp
        FileReading/FileReader.cpp
        FileReading/FileReader.hpp
        Builders/builder.cpp
        Builders/builder.hpp
        Builders/MapBuilder.cpp
        Builders/MapBuilder.hpp
        Parsing/Parser.cpp
        Parsing/Parser.hpp
        Parsing/CSVParser.cpp
        Parsing/CSVParser.hpp
        Parsing/TXTParser.cpp
        Parsing/TXTParser.hpp
        Parsing/XMLParser.cpp
        Parsing/XMLParser.hpp
        FileReading/DiskReader.cpp
        FileReading/DiskReader.hpp)

# Explicitly link the urlmon library for MinGW
if (MINGW)
    target_link_libraries(PROJECT_NAME urlmon)
endif ()