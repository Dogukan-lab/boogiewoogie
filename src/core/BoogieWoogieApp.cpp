//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"

#include "FileReader.hpp"
#include "FileReaderFactory.hpp"
#include <iostream>
#include <SDL.h>
#include <iostream>
#include <SDL_video.h>
#include <thread>

#include "TileManager.hpp"
#include "BoogieRenderer.hpp"

auto readData = [](const std::string& source) {
     auto reader = FileReaderFactory::CreateFileReader(source);

    auto [type, list] = reader->ReadContent();

    std::cout << "FILETYPE: " << type << std::endl;
    std::cout << "---START OF DATA----" << std::endl;
    for(const auto& line : list) {
        std::cout << line << "\n";
    }
    std::cout << "---END OF DATA---" << std::endl;

    //Key val <-- map<Type, Entry>
    //case 'Type':
    // entries doorlopen
    // builder.
};

std::thread readJob;
void BoogieWoogieApp::SetupSimulation(const std::string& source) {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....
    readJob = std::thread(readData, source);

    // _renderer->RegisterTiles(_tileManager->getTiles());
    // _renderer->RegisterArtists(_artistManager->GetArtists());
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
    //Wait on thread finishing its reading job.
    readJob.join();
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
        // _artistManager->UpdateArtists();

        //Render tiles
        // _renderer->Draw();
    }
}
