//
// Created by doguk on 10/16/2024.
//

#include "TileManager.hpp"
#include "Tile.hpp"
#include "Memento.hpp"


std::map<char, std::pair<SDL_Colour, int> > TileManager::types{};

TileManager::TileManager(BoogieRenderer& renderer): TileManager(5, renderer) {
    types.emplace('W', std::pair{SDL_Colour{255, 255, 255, 255}, 0});
}

TileManager::TileManager(int capacity, BoogieRenderer& renderer): _renderer(renderer) {
    _tiles.reserve(capacity);
}

void TileManager::AddTiles(std::vector<std::vector<std::unique_ptr<Tile>>> &&tileMap) {
    _renderer.ClearTiles();
    _tiles = std::move(tileMap);
    _renderer.RegisterTiles(_tiles);
}

std::vector<std::vector<std::unique_ptr<Tile> > > &TileManager::getTiles() {
    return _tiles;
}

std::vector<TileCopy> TileManager::Save() {
    std::vector<TileCopy> tiles_result;

    for (int y =0; y< _tiles.size(); y++){
        for (int x =0; x< _tiles[0].size(); x++) {
            auto& tile = _tiles[y][x];
            tiles_result.emplace_back(TileCopy{.pos = tile->position, .shape = tile->shape, .colour = tile->type->colour});
        }
    }

    return tiles_result;
}