cmake_minimum_required(VERSION 3.28)
project(boogiewoogie)

set(CMAKE_CXX_STANDARD 17)


add_executable(${PROJECT_NAME}
        main.cpp
        MapActionHandler.hpp
        src/input_handler/InputHandler.cpp
        src/input_handler/MoveArtists.cpp   # Make sure this is included
        MapActionHandler.cpp
        src/input_handler/RenderArtists.cpp
        src/input_handler/AdjustBoxAtMousePointer.cpp
        src/input_handler/MouseAndKeyboard.cpp
        src/input_handler/RenderArtists.hpp
)


# Link CURL + SDL2
target_link_directories(${PROJECT_NAME} PUBLIC ${INPUT_ROOT})


set_target_properties(${PROJECT_NAME} PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
)

