cmake_minimum_required(VERSION 3.28)
project(boogiewoogie)

set(CMAKE_CXX_STANDARD 17)

add_executable(boogiewoogie main.cpp
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
