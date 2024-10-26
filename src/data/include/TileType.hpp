//
// Created by doguk on 10/26/2024.
//

#ifndef TILETYPE_HPP
#define TILETYPE_HPP
#include <SDL_pixels.h>

class TileType {
public:
    explicit TileType(char tag);
    virtual ~TileType() = default;

    char tag;
    SDL_Colour colour{};
    int weight;
    int interactions;

    virtual void handleInteract() = 0;
};

#endif //TILETYPE_HPP
