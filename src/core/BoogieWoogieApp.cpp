//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"
#include <iostream>
#include <SDL.h>
#include <iostream>
#include <SDL_video.h>

#include "TileManager.hpp"
#include "dummydata/DummyTile.hpp"
#include "renderer/BoogieRenderer.hpp"

void BoogieWoogieApp::SetupSimulation() {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....

    SDL_Colour yellow{255, 255, 0};
    SDL_Colour red{255, 0, 0};
    SDL_Colour green{0, 255, 0};
    SDL_Colour blue{0, 0, 255};

    DummyTileType yellowType('Y', yellow, 10);
    DummyTileType greenType('G', green, 10);
    DummyTileType redType('R', red, 10);
    DummyTileType blueType('B', blue, 10);
    std::vector types = {yellowType, greenType, redType, blueType};

    int j = 0;
    for (int i = 0; i < _tileManager->getTiles().capacity(); i++) {
        DummyTile tile(types[i % 4], Shape(32, 32, i, j, ShapeType::Rectangle));
        _tileManager->AddTile(tile);
        j++;
    }

    for(int i = 0; i < 1; i++) {
        _artistManager->AddArtist(Artist());
    }
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
