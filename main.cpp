//
// Created by hmkam on 26/10/2024.
//
#include "src/input_handler/InputHandler.hpp"
#include "src/input_handler/MouseAndKeyboard.hpp"
#include "MapActionHandler.hpp"
#include "src/input_handler/AdjustBoxAtMousePointer.hpp"
#include "src/input_handler/MoveArtists.hpp"


void testInputHandler() {
    auto inputHandler = InputHandler();

    inputHandler.addKey('A', new MoveArtists);
    inputHandler.addKey('B', new AdjustBoxAtMousePointer(new MouseAndKeyboard, new MapActionHandler)); {
        inputHandler.executeKey('B');
        inputHandler.executeKey('C');
    }
}


int main() {
    testInputHandler();
    return 0;
}
