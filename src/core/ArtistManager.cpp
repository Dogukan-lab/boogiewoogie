//
// Created by doguk on 10/21/2024.
//

#include "ArtistManager.hpp"
#include "Artist.hpp"
#include <glm.hpp>

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
void ArtistManager::UpdateArtists() const {
    constexpr float deltaTime = 0.166666666666667f;
    for (const auto &artist: _artists) {
        // if(artist)
        auto position = artist->GetPosition();
        auto direction = artist->GetDirection();
        position.x += direction.x * deltaTime / 10.f;
        position.y += direction.y * deltaTime / 10.f;
        direction = glm::normalize(direction);
    }
}
