//
// Created by doguk on 10/16/2024.
//

#include "TileManager.hpp"
#include <algorithm>
#include "dummydata/DummyTile.hpp"

TileManager::TileManager(): TileManager(5) {
}

TileManager::TileManager(int capacity) {
    _tiles.reserve(capacity);
}

void TileManager::AddTile(const DummyTile &tile) {
    _tiles.emplace_back(std::make_shared<DummyTile>(tile));
}

//TODO Worry about this later
void TileManager::RemoveTile(const DummyTile &tile) {
}

std::vector<std::shared_ptr<DummyTile> > &TileManager::getTiles() {
    return _tiles;
}
