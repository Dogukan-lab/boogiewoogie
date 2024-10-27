cmake_minimum_required(VERSION 3.28)
#Pull in sources
#Die inside
add_library(BoogieWoogieInternal)


if (TARGET BoogieWoogieInternal)
    include(${CMAKE_CURRENT_SOURCE_DIR}/gather.cmake)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/builders" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/core" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/data" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/renderer" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/file_readers" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/file_parsers" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/algorithms/collision" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/algorithms/pathfinding" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/input_handler" BoogieWoogieInternal)
endif ()