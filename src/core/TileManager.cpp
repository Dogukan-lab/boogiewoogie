//
// Created by doguk on 10/16/2024.
//

#include "TileManager.hpp"
#include "Tile.hpp"


std::map<char, std::pair<SDL_Colour, int> > TileManager::types;

TileManager::TileManager(): TileManager(5) {
    types.emplace('W', std::pair{SDL_Colour{255, 255, 255, 255}, 0});
}

TileManager::TileManager(int capacity) {
    _tiles.reserve(capacity);
}

std::vector<std::vector<std::unique_ptr<Tile> > > &TileManager::getTiles() {
    return _tiles;
}
