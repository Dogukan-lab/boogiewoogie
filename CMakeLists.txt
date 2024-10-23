cmake_minimum_required(VERSION 3.28)
project(BoogieWoogie)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_VAR ON CACHE BOOL "Used to check for building")

add_subdirectory(src)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/pugixml)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE BoogieWoogieInternal pugixml)
