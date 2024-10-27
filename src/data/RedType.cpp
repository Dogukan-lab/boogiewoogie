//
// Created by doguk on 10/27/2024.
//

#include "RedType.hpp"

#include <ArtistManager.hpp>
#include <BlueType.hpp>

void RedType::handleInteract(Tile *currentTile, Artist *currentArtist, ArtistManager& manager) {
    if(currentArtist == nullptr)
        return;
    manager.RemoveArtist(*currentArtist);
    currentTile->SetType<BlueType>();
}
