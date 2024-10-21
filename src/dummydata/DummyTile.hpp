//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <SDL_rect.h>
#include "Shape.hpp"

struct DummyTileType {
    char tag;
    SDL_Colour colour;
    int weight; //Not relevant for now
    //Maybe use shape here instead?

    DummyTileType(const char &character, const SDL_Colour& colour, const int &weight): tag(character), colour(colour), weight(weight) {
    }
};

class DummyTile {
public:
    explicit DummyTile(const DummyTileType &type, const Shape& shape): type(type), shape(shape) {
    }

    Shape shape;
    DummyTileType type;
};
#endif //DUMMYTILE_HPP
