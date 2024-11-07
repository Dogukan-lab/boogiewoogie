cmake_minimum_required(VERSION 3.28)
project(BoogieWoogie)

set(CMAKE_CXX_STANDARD 17)

# GTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(libs/googletest-main)
include_directories(libs/googletest/include)

# SDL2 VARS
set(SDL2_ROOT "${CMAKE_SOURCE_DIR}/libs/SDL2")
set(SDL2_INCLUDE_PATH "${SDL2_ROOT}/include/SDL2")
set(SDL2_LIBRARIES_PATH "${SDL2_ROOT}/lib/libSDL2.dll.a")
set(SDL2_RUNTIME_PATH "${SDL2_ROOT}/bin/SDL2.dll")

# Check status of the SDL2 vars
message(STATUS "SDL2 Root Directory: ${SDL2_ROOT}/include")
message(STATUS "SDL2 Include Directory: ${SDL2_INCLUDE_PATH}")
message(STATUS "SDL2 Library Directory: ${SDL2_LIBRARIES_PATH}")
message(STATUS "SDL2 Library Directory: ${SDL2_RUNTIME_PATH}")

# CURL VARS
set(CURL_ROOT "${CMAKE_SOURCE_DIR}/libs/curl")
set(CURL_RUNTIME_PATH "${CURL_ROOT}/bin/libcurl-x64.dll")
set(CURL_LIB_PATH "${CURL_ROOT}/lib/libcurl.dll.a")

#Check status of the CURL vars
message(STATUS "CURL Include Directory: ${CURL_ROOT}/include")
message(STATUS "CURL Library Directory: ${CURL_LIB_PATH}")

# PUGI VARS
set(PUGI_ROOT "${CMAKE_SOURCE_DIR}/libs/pugixml")

# GLM
add_subdirectory(libs/glm)
include_directories(libs/glm)

# PUGIXML
add_subdirectory(${PUGI_ROOT})
include_directories(${PUGI_ROOT})

#SDL2
include_directories(${SDL2_INCLUDE_PATH})

# SRC plus pugiXML
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp
        #        testing/builders/FixtureMapBuilder.cpp
        #        testing/builders/FixtureMapBuilder.hpp
        testing/filereading/FileReadTest.cpp
        testing/TestSuite.cpp
#        testing/parser/ParserSuite.hpp
#        testing/parser/TXTFixture.cpp
#        testing/parser/XMLFixture.cpp
#        testing/parser/CSVParser.cpp
)

#Testing
target_link_libraries(${PROJECT_NAME} PUBLIC GTest::gtest_main GTest::gmock)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# Link CURL + SDL2
target_link_directories(${PROJECT_NAME} PUBLIC ${CURL_ROOT}/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_PATH})

# Link Pugi, Glm, Curl, SDL2
target_link_libraries(${PROJECT_NAME} PRIVATE BoogieWoogieInternal
        pugixml
        glm
        ${CURL_LIB_PATH}
        ${SDL2_LIBRARIES_PATH}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURL_RUNTIME_PATH};${CURL_LIB_PATH};${SDL2_RUNTIME_PATH};${SDL2_LIBRARIES_PATH}"
)