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

void TileManager::AddTiles(std::vector<std::vector<std::unique_ptr<Tile>>> &&tileMap) {
    _renderer.ClearTiles();
    _tiles = std::move(tileMap);
    _renderer.RegisterTiles(_tiles);
}

// void TileManager::AddTile(std::unique_ptr<Tile> tile) {
//     _tiles[tile->position.y][tile->position.x] = std::move(tile);
//     _renderer.RegisterTiles(_tiles);
// }

std::vector<std::vector<std::unique_ptr<Tile> > > &TileManager::getTiles() {
    return _tiles;
}

// void TileManager::Restore(Memento *memento) {
//     auto tiles = memento->GetTiles();
//
//     ClearTiles();
//
//     std::vector<std::vector<std::unique_ptr<Tile> > > tiles_result;
//
//     for (int y =0; y< tiles.size(); y++){
//         for (int x =0; x< tiles[0].size(); x++) {
//             auto tile = tiles[y][x];
//             tiles_result[y][x] = std::make_unique<Tile>(tile.pos,tile.shape,tile.type,);
//         }
//     }
// }

// void TileManager::ClearTiles() {
//     _renderer.ClearTiles();
//     _tiles.clear();
// }

std::vector<tileCopy> TileManager::Save() {
    std::vector<tileCopy> tiles_result;

    for (int y =0; y< _tiles.size(); y++){
        for (int x =0; x< _tiles[0].size(); x++) {
            auto& tile = _tiles[y][x];
            tiles_result.emplace_back(tileCopy{.pos = tile->position, .shape = tile->shape, .colour = tile->type->colour});
        }
    }

    return tiles_result;
}