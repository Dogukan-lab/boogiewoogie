//
// Created by hmkam on 23/09/2024.
//

#include "AritistBuilder.hpp"
#include "Artist.hpp"

ArtistBuilder & ArtistBuilder::addArtist(const Artist &artist) {
    _artists.emplace_back(artist);
    return *this;
}

ArtistBuilder & ArtistBuilder::addArtists(const std::vector<Artist> &artists) {
    for(const auto& artist: artists) {
        addArtist(artist);
    }

    return *this;
}