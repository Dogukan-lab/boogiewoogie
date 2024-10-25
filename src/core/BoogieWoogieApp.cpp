//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"
#include <iostream>
#include <SDL.h>
#include <iostream>
#include <SDL_video.h>

#include "TileManager.hpp"
#include "BoogieRenderer.hpp"

void BoogieWoogieApp::SetupSimulation() {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....

    _renderer->RegisterTiles(_tileManager->getTiles());
    _renderer->RegisterArtists(_artistManager->GetArtists());
}

BoogieWoogieApp::BoogieWoogieApp(): BoogieWoogieApp("Boogie woogie Sim", true, 640, 480) {
}

//TODO Maybe make a window class instead??? <-- I should...
BoogieWoogieApp::BoogieWoogieApp(const char *windowName, bool isCentered, int width, int height): _window(
    nullptr, SDL_DestroyWindow) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << SDL_GetError() << std::endl;
    }
    if (isCentered) {
        _window.reset(SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       width, height, SDL_WINDOW_SHOWN));
    } else {
        _window.reset(SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                       width, height, SDL_WINDOW_SHOWN));
    }
    isRunning = true;
    _renderer = std::make_unique<BoogieRenderer>(_window.get());
    _tileManager = std::make_unique<TileManager>();
    _artistManager = std::make_unique<ArtistManager>();
}

void BoogieWoogieApp::RunSimulation() {
    //Main loop van SDL2 applicatie
    SDL_Event event;
    while (isRunning) {
        //Poll keyboard events
        //Dude there has to be a better way XD
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            // std::cout << "PRESSING ESCAPE!" << std::endl;
                            isRunning=false;
                        default: break;
                    }
                break;
                case SDL_QUIT:
                    isRunning = false;
                default:
                    break;
            }
        }
        //Update tiles ofcourse
        _artistManager->UpdateArtists();

        //Render tiles
        _renderer->Draw();
    }
}
