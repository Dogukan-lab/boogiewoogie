//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_video.h>

#include "TileManager.hpp"
#include "renderer/BoogieRenderer.hpp"

void BoogieWoogieApp::SetupSimulation() const {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....

    int yellow[] = {255,255,0};
    int red[] = {255,0,0};
    int green[] = {0,255,0};
    int blue[] = {0,0,255};

    DummyTileType yellowType('Y', yellow, 10);
    DummyTileType greenType('G', green, 10);
    DummyTileType redType('R', red, 10);
    DummyTileType blueType('B', blue, 10);
    std::vector types = {yellowType, greenType, redType, blueType};

    for(int i = 0; i < _tileManager->getTiles().capacity(); i++) {
        _tileManager->AddTile(DummyTile(types[i%4], Rectangle(32,32)));
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

    _renderer = std::make_unique<BoogieRenderer>(_window.get());
    _tileManager = std::make_unique<TileManager>();
}

void BoogieWoogieApp::RunSimulation() const {
    //Main loop van SDL2 applicatie
    // while(isRunning) {
    //     //Logica afhandelen
    //     //Rendering
    // }

    for(const auto& tile: _tileManager->getTiles()) {
        std::cout << tile->type.tag << "," << tile->type.rgb[0] << "," << tile->type.weight <<
            "\n";
        //TODO Shape is not working!
        auto shape = tile->getShape<Rectangle>().rectangle;
        std::cout << "SHAPE WIDTH: " << shape.w << " SHAPE HEIGHT: " << shape.h << std::endl;
    }
}
