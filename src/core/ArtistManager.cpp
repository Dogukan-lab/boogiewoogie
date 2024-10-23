//
// Created by doguk on 10/21/2024.
//

#include "ArtistManager.hpp"

ArtistManager::ArtistManager(): ArtistManager(10)
{
}

ArtistManager::ArtistManager(int capacity) {
    _artists.reserve(capacity);
}

void ArtistManager::AddArtist(Artist &&artist) {
    _artists.emplace_back(std::make_unique<Artist>(artist));
}

std::vector<std::unique_ptr<Artist>> & ArtistManager::GetArtists() {
    return _artists;
}

void ArtistManager::UpdateArtists() {
    for(const auto& artist: _artists) {
        // if(artist)
            artist->Move(0.166666666666667f);
    }
}