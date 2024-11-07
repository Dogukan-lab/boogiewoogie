//
// Created by hmkam on 23/09/2024.
//

#include "AritistBuilder.hpp"

#include "Artist.hpp"
#include "DataEntry.hpp"


ArtistBuilder& ArtistBuilder::addArtist(DataEntry &artist) {
    glm::vec2 pos{std::stof(artist.entries["x"]), std::stof(artist.entries["y"])};
    glm::vec2 dir{std::stof(artist.entries["vx"]), std::stof(artist.entries["vy"])};

    Artist art {
        Shape(),
        SDL_Colour {0, 0, 0, 255},
        pos,
        dir
    };


    _artists.emplace_back(std::make_unique<Artist>(art));
    return *this;
}

ArtistBuilder& ArtistBuilder::addArtists(std::vector<DataEntry> &artists) {
    for (auto &entry: artists) {
        addArtist(entry);
    }
    return *this;
}

std::vector<std::unique_ptr<Artist>>&& ArtistBuilder::build() {
    return std::move(_artists);
}