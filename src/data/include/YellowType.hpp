//
// Created by doguk on 10/26/2024.
//

#ifndef YELLOWTYPE_HPP
#define YELLOWTYPE_HPP
#include "TileType.hpp"

class YellowType: public TileType{
public:
    explicit YellowType()
        : TileType('Y') {
    }

    void handleInteract(Tile *currentTile, Artist *currentArtist, ArtistManager &manager) override;
};

#endif //YELLOWTYPE_HPP
