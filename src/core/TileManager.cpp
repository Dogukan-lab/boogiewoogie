//
// Created by doguk on 10/16/2024.
//

#include "TileManager.hpp"
#include "Tile.hpp"


std::map<char, std::pair<SDL_Colour, int> > TileManager::types{};

TileManager::TileManager(BoogieRenderer& renderer): TileManager(5, renderer) {
    types.emplace('W', std::pair{SDL_Colour{255, 255, 255, 255}, 0});
}

TileManager::TileManager(int capacity, BoogieRenderer& renderer): _renderer(renderer) {
    _tiles.reserve(capacity);
}

std::vector<std::vector<std::unique_ptr<Tile> > > &TileManager::getTiles() {
    return _tiles;
}
