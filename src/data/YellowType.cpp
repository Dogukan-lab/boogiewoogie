//
// Created by doguk on 10/27/2024.
//
#include "YellowType.hpp"

#include <ArtistManager.hpp>
#include <BoogieWoogieApp.hpp>
#include <GreyType.hpp>
#include <random>

//Create artist on tile position with random normalized direction
void YellowType::handleInteract(Tile *currentTile, Artist *currentArtist) {
    auto& manager = BoogieWoogieApp::GetInstance().GetArtistManager();

    std::random_device device;
    std::uniform_real_distribution disX(-7.5f, 7.5f);
    std::uniform_real_distribution disY(-7.5f, 7.5f);
    const auto randDir = glm::vec2(disX(device), disY(device));
    if (const auto artist = manager.AddArtist(Artist(currentTile->position, randDir)))
        artist->GetLastTile() = currentTile->position;

    if (interactions == 2) {
        currentTile->SetType<GreyType>();
    }

    interactions++;
}