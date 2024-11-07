//
// Created by doguk on 10/27/2024.
//

#include "BlueType.hpp"

#include <algorithm>
#include <Tile.hpp>
#include <vector>
#include <YellowType.hpp>
#include <random>

void BlueType::handleInteract(Tile *currentTile, Artist *currentArtist) {
//    std::cout << "CURRENT TILE NEIGHBOURS SIZE: " << currentTile->neighbours.size() << std::endl;
    //Templist neighbours
    std::random_device device;
    std::vector<Tile*> tiles = currentTile->neighbours;

    //Get first tile, and set to blue
    std::shuffle(tiles.begin(), tiles.end(), device);
    const auto& tile1 = tiles[0];
    tile1->SetType<BlueType>();
    //Remove from list
    tiles.erase(tiles.begin());

    //Get second tile, and set to blue
    std::shuffle(tiles.begin(), tiles.end(), device);
    const auto& tile2 = tiles[0];
    tile2->SetType<BlueType>();
    //Remove from list
    tiles.erase(tiles.begin());

    currentTile->SetType<YellowType>();
}