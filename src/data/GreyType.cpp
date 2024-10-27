//
// Created by doguk on 10/27/2024.
//
#include "GreyType.hpp"

#include <RedType.hpp>
#include <Tile.hpp>

void GreyType::handleInteract(Tile *currentTile, Artist *currentArtist, ArtistManager &manager) {
    if(interactions == 3) {
        currentTile->SetType<RedType>();
    }
    interactions++;
}
