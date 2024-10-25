//
// Created by hmkam on 23/09/2024.
//

#ifndef ARITISTBUILDER_HPP
#define ARITISTBUILDER_HPP
#include <vector>
#include "Builder.hpp"

class Artist;

class ArtistBuilder : public Builder<std::vector<Artist>> {
public:
    ArtistBuilder &addArtist(const Artist &artist);
    ArtistBuilder &addArtists(const std::vector<Artist> &artists);
    ArtistBuilder &replaceArtists(const std::vector<Artist> &artists);

private:
    std::vector<Artist> _artists;
};


#endif //ARITISTBUILDER_HPP
