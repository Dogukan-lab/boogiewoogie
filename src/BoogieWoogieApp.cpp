//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"
#include <SDL.h>
#include <SDL_video.h>

void BoogieWoogieApp::SetupSimulation() {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....
}

BoogieWoogieApp::BoogieWoogieApp(): BoogieWoogieApp("Boogie woogie Sim", true, 640, 480){
}

//TODO Maybe make a window class instead??? <-- I should...
BoogieWoogieApp::BoogieWoogieApp(const char *windowName, const bool isCentered, const int width, const int height): _window(nullptr, SDL_DestroyWindow) {
    if (SDL_Init(SDL_VIDEO_OPENGL) != 0)
        return;
    if (isCentered) {
        _window.reset(SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN));
    }
    else {
        _window.reset(SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_SHOWN));
    }
}

void BoogieWoogieApp::RunSimulation() {
    //Main loop van SDL2

    while(isRunning) {

        
    }
}
