//
// Created by hmkam on 23/09/2024.
//

#ifndef ARITISTBUILDER_HPP
#define ARITISTBUILDER_HPP
#include "Builder.hpp"

class ArtistBuilder : public Builder<ArtistsObject> {
public:
    ArtistBuilder &addArtist(const Artist &artist) {
        artistsObject.artists.emplace_back(artist);
        return *this;
    }

    ArtistBuilder &addArtists(const std::vector<Artist> &artists) {
        for (auto artist: artists) {
            artistsObject.artists.emplace_back(artist);
        }
        return *this;
    }

    ArtistBuilder &replaceArtists(const std::vector<Artist> &artists) {
        artistsObject.artists.clear();
        artistsObject.artists = artists;
        return *this;
    }

    ArtistsObject &build() override {
        return artistsObject;
    }

private:
    ArtistsObject artistsObject;
};


#endif //ARITISTBUILDER_HPP
