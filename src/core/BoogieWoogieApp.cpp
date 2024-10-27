//
// Created by doguk on 10/9/2024.
//

#include "BoogieWoogieApp.hpp"

#include <AritistBuilder.hpp>
#include <CsvParser.hpp>
#include <functional>

#include "FileReader.hpp"
#include "FileReaderFactory.hpp"
#include <iostream>
#include <SDL.h>
#include <iostream>
#include <MapBuilder.hpp>
#include <SDL_video.h>
#include <thread>
#include <TxtParser.hpp>
#include <XmlParser.hpp>

#include "TileManager.hpp"
#include "BoogieRenderer.hpp"

void BoogieWoogieApp::SetupSimulation() {
    //Setup tiles for now...
    //Surfaces?
    //Or just deprecated....
    std::string mapSource = R"(../assets/graph.xml)";
    std::string artistSource = R"(../assets/artists.csv)";
    CreateMap(mapSource);
    CreateArtists(artistSource);
    _renderer->RegisterTiles(_tileManager->getTiles());
    _renderer->RegisterArtists(_artistManager->GetArtists());
}

BoogieWoogieApp::BoogieWoogieApp(): BoogieWoogieApp("Boogie woogie Sim", true, 600, 600) {
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
    SDL_Event event;
    Uint32 prevTick = SDL_GetTicks();
    Uint32 fpsInterval = 1000;
    Uint32 fps = 0, frameCount = 0;

    while (isRunning) {
        Uint32 curTicks = SDL_GetTicks();
        Uint32 delta = curTicks - prevTick;
        prevTick = curTicks;
        //Poll keyboard events
        //Dude there has to be a better way XD
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            // std::cout << "PRESSING ESCAPE!" << std::endl;
                            isRunning = false;
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
        _artistManager->UpdateArtists(static_cast<float>(delta) / 1000.f);

        //Render tiles
        _renderer->Draw();

        frameCount++;
        fps += delta;
        if (fps >= fpsInterval) {
            //     std::cout << "FPS: " << frameCount << std::endl;
            fps = 0;
            frameCount = 0;
        }
    }
}

void BoogieWoogieApp::CreateMap(const std::string &source) const {
    auto reader = FileReaderFactory::CreateFileReader(source);
    auto [type, list] = reader->ReadContent();
    std::unordered_map<std::string, std::function<void()> > actions{
        {
            "txt", [&] {
                TXTParser parser;
                MapBuilder builder;
                auto entries = parser.ParseData(list);

                for (auto &entry: entries) {
                    switch (entry.tag) {
                        case DataEntry::GridSize:
                            builder.setMapSize(entry);
                            break;
                        case DataEntry::TileType:
                            builder.addTileType(entry);
                            break;
                        case DataEntry::Tile:
                            builder.addTile(entry);
                            break;
                        default: break;
                    }
                }
                _tileManager->AddTiles(std::move(builder.build()));
            }
        },
        {
            "xml", [&] {
                XMLParser parser;
                MapBuilder builder;
                auto entries = parser.ParseData(list);

                for (auto &entry: entries) {
                    switch (entry.tag) {
                        case DataEntry::GridSize:
                            builder.setMapSize(entry);
                            break;
                        case DataEntry::TileType:
                            builder.addTileType(entry);
                            break;
                        case DataEntry::Tile:
                            builder.addTile(entry);
                            break;
                        default: break;
                    }
                }
                _tileManager->AddTiles(std::move(builder.build()));
            }
        },
    };
    actions[type]();
}

void BoogieWoogieApp::CreateArtists(const std::string &source) {
    auto reader = FileReaderFactory::CreateFileReader(source);
    auto [type, data] = reader->ReadContent();
    std::unordered_map<std::string, std::function<void()>> actions{
        {
            "csv", [&] {
                CSVParser parser;
                ArtistBuilder builder;
                auto entries = parser.ParseData(data);

                for (auto &entry: entries) {
                    builder.addArtist(entry);
                }
                _artistManager->SetArtists(std::move(builder.build()));
            }
        },
    };
    actions[type]();
}
