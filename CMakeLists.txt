cmake_minimum_required(VERSION 3.28)
project(boogiewoogie)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_PATH ${CMAKE_SOURCE_DIR}/libs/SDL2)
include_directories(${SDL2_PATH}/include/SDL2)

add_subdirectory(libs/glm)
include_directories(libs/glm)

add_executable(${PROJECT_NAME} main.cpp
        # Dit is beetje yikes.
        # TODO Fix this
        src/renderer/BoogieRenderer.cpp
        src/BoogieWoogieApp.cpp
        src/dummydata/Map.hpp
        src/dummydata/DummyTile.hpp
        src/TileManager.cpp
        src/TileManager.hpp
        src/dummydata/DummyArtist.hpp
        src/dummydata/DummyArtist.cpp
        src/ArtistManager.cpp
        src/ArtistManager.hpp
        src/dummydata/Shape.hpp
)

target_link_libraries(${PROJECT_NAME}
        glm
        mingw32
        ${SDL2_PATH}/lib/libSDL2main.a
        ${SDL2_PATH}/lib/libSDL2.dll.a
)