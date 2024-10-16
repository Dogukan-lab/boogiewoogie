//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_video.h>

#include "TileManager.hpp"
#include "renderer/BoogieRenderer.hpp"

void BoogieWoogieApp::SetupSimulation() {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....
    DummyTileType type('Y', {255,255,255}, 10);


    for(int i = 0; i < _tileManager->getTiles().capacity(); i++) {
        _tileManager->AddTile({})
    }
}

BoogieWoogieApp::BoogieWoogieApp(): BoogieWoogieApp("Boogie woogie Sim", true, 640, 480){
}

//TODO Maybe make a window class instead??? <-- I should...
BoogieWoogieApp::BoogieWoogieApp(const char *windowName, const bool isCentered, const int width, const int height): _window(nullptr, SDL_DestroyWindow) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << SDL_GetError() << std::endl;
    }
    if (isCentered) {
        _window.reset(SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN));
    }
    else {
        _window.reset(SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_SHOWN));
    }

    _renderer = std::make_unique<BoogieRenderer>(*_window);
    _tileManager = std::make_unique<TileManager>();
}

void BoogieWoogieApp::RunSimulation() const {
    //Main loop van SDL2 applicatie
    while(isRunning) {
        //Logica afhandelen
        //Rendering
        _renderer->Draw();
    }
}
