cmake_minimum_required(VERSION 3.28)
#Pull in sources
#Die inside
add_library(BoogieWoogieInternal)

target_link_libraries(BoogieWoogieInternal PUBLIC pugixml)

if (TARGET BoogieWoogieInternal)
    include(${CMAKE_CURRENT_SOURCE_DIR}/gather.cmake)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/builders" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/file-reading" BoogieWoogieInternal)
    gather_sources_headers("${CMAKE_CURRENT_SOURCE_DIR}/parsing" BoogieWoogieInternal)
endif ()