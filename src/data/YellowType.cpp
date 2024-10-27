//
// Created by doguk on 10/27/2024.
//
#include "YellowType.hpp"

#include <ArtistManager.hpp>
#include <GreyType.hpp>
#include <random>

void YellowType::handleInteract(Tile *currentTile, Artist *currentArtist, ArtistManager& manager) {
    //Create artist on tile position with random normalized direction
    std::random_device device;
    std::uniform_real_distribution<float> disX(-7.5f, 7.5f);
    std::uniform_real_distribution<float> disY(-7.5f, 7.5f);
    glm::vec2 randDir = glm::vec2(disX(device), disY(device));
    auto artist = manager.AddArtist(Artist(currentTile->position, randDir));
    if(artist) artist->GetLastTile() = currentTile->position;

    if(interactions == 2) {
        currentTile->SetType<GreyType>();
    }

    interactions++;
}
