//
// Created by doguk on 10/16/2024.
//

#include "TileManager.hpp"
#include "Tile.hpp"

TileManager::TileManager(): TileManager(5) {
}

TileManager::TileManager(int capacity) {
    _tiles.reserve(capacity);
}

void TileManager::AddTile(const Tile &tile) {
    _tiles.emplace_back(std::make_unique<Tile>(tile));
}

//TODO Worry about this later
void TileManager::RemoveTile(const Tile &tile) {
}

std::vector<std::unique_ptr<Tile>> &TileManager::getTiles() {
    return _tiles;
}
