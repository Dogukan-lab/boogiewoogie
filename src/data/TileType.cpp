//
// Created by doguk on 10/26/2024.
//

#include "include/TileType.hpp"
#include "TileManager.hpp"

TileType::TileType(const char tag): tag(tag), interactions(0) {
    const auto& type = TileManager::GetType(tag);
    colour = type.first;
    weight = type.second;
}
