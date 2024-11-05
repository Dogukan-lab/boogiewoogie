//
// Created by doguk on 10/27/2024.
//

#include "RedType.hpp"

#include <ArtistManager.hpp>
#include <BlueType.hpp>
#include <BoogieWoogieApp.hpp>

void RedType::handleInteract(Tile *currentTile, Artist *currentArtist) {
    const auto& manager = BoogieWoogieApp::GetInstance().GetArtistManager();
    if(currentArtist == nullptr)
        return;
    manager.RemoveArtist(*currentArtist);
    currentTile->SetType<BlueType>();
}