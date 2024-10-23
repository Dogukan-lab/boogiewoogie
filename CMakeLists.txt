cmake_minimum_required(VERSION 3.28)
project(boogiewoogie)

set(CMAKE_CXX_STANDARD 17)

set(CURL_ROOT "${CMAKE_SOURCE_DIR}/libs/curl")
set(CURL_RUNTIME_PATH "${CURL_ROOT}/bin/libcurl-x64.dll")
set(CURL_LIB_PATH "${CURL_ROOT}/lib/libcurl.dll.a")

#Check status of the CURL vars
message(STATUS "CURL Include Directory: ${CURL_ROOT}/include")
message(STATUS "CURL Library Directory: ${CURL_LIB_PATH}")

add_subdirectory(src)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/pugixml)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE ${CURL_ROOT}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE BoogieWoogieInternal pugixml
        ${CURL_LIB_PATH}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURL_RUNTIME_PATH};${CURL_LIB_PATH}"
)
set(SDL2_PATH ${CMAKE_SOURCE_DIR}/libs/SDL2)
include_directories(${SDL2_PATH}/include/SDL2)

add_subdirectory(libs/glm)
include_directories(libs/glm)
