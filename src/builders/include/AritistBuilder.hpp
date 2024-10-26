//
// Created by hmkam on 23/09/2024.
//

#ifndef ARITISTBUILDER_HPP
#define ARITISTBUILDER_HPP
#include <vector>
#include "Builder.hpp"
#include "Artist.hpp"
#include "ArtistManager.hpp"

class DataEntry;

class ArtistBuilder : public Builder<std::vector<std::unique_ptr<Artist>>> {
public:
    ArtistBuilder& addArtist(DataEntry &artist);
    ArtistBuilder& addArtists(std::vector<DataEntry> &artists);

    std::vector<std::unique_ptr<Artist>> && build() override;

private:
    std::vector<std::unique_ptr<Artist>> _artists{};
};


#endif //ARITISTBUILDER_HPP
