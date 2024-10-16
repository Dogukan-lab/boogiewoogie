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

void TileManager::AddTile(const DummyTile& tile) {
    const auto foundTile = std::find(_tiles.begin(), _tiles.end(), tile);

    if(foundTile == _tiles.end())
    _tiles.emplace_back(std::make_shared<DummyTile>(tile));
}

void TileManager::RemoveTile(DummyTile tile) {
    const auto foundTile = std::remove_if(_tiles.begin(), _tiles.end(), [&tile](const auto& t){return &t == &tile;});

    if(foundTile != _tiles.end())
        _tiles.erase(foundTile);
}
