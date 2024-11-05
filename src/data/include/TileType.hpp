//
// Created by doguk on 10/26/2024.
//

#ifndef TILETYPE_HPP
#define TILETYPE_HPP
#include <SDL_pixels.h>
#include <iostream>

class ArtistManager;
class Artist;
class Tile;

class TileType {
public:
    explicit TileType(char tag);
    virtual ~TileType() = default;

    char tag;
    SDL_Colour colour{};
    int weight;
    int interactions;

    virtual void handleInteract(Tile* currentTile, Artist* currentArtist) = 0;
};

#endif //TILETYPE_HPP