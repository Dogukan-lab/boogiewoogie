//
// Created by doguk on 10/21/2024.
//

#include "ArtistManager.hpp"
#include "Artist.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <AritistBuilder.hpp>
#include <AritistBuilder.hpp>
#include <AritistBuilder.hpp>
#include <AritistBuilder.hpp>
#include <glm.hpp>
#include <iostream>
#include <gtx/string_cast.hpp>

ArtistManager::ArtistManager(): ArtistManager(10) {
}

ArtistManager::ArtistManager(int capacity) {
    _artists.resize(capacity);
}

void ArtistManager::AddArtist(Artist &&artist) {
    _artists.emplace_back(std::make_unique<Artist>(artist));
}

std::vector<std::unique_ptr<Artist> > &ArtistManager::GetArtists() {
    return _artists;
}

//Update movement of artists
//TODO Boundcheck
void ArtistManager::UpdateArtists(const float deltaTime) const {
    for (const auto &artist: _artists) {
        // if(artist)
        auto &position = artist->GetPosition();
        auto &direction = artist->GetDirection();
        const auto& dimension = artist->GetShape().GetDimension();
        const auto size = dimension /2.f;
        const auto offset = dimension/4.f;
        position += direction * (deltaTime);

        //Bounds check
        if (position.x * dimension.x<= -offset.x) direction.x = abs(direction.x);
        if (position.x * dimension.x >= 600.f - size.x - offset.x) direction.x = abs(direction.x) * -1;
        if (position.y *dimension.y<= -offset.y) direction.y = abs(direction.y);
        if (position.y * dimension.y>= 600.f - size.y - offset.y) direction.y = abs(direction.y) * -1;

    }
}
