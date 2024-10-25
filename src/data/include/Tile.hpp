//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <SDL_rect.h>
#include "Shape.hpp"

struct TileType {
    char tag;
    SDL_Colour colour;
    int weight;

    TileType(const char &character, const SDL_Colour& colour, const int &weight): tag(character), colour(colour), weight(weight) {
    }
};

class Tile {
public:
    Tile(const TileType &type, const Shape& shape): type(type), shape(shape) {
    }

    ~Tile() {
        neighbours.clear();
    }

    Shape shape;
    TileType type;
    std::vector<Tile*> neighbours;
};
#endif //DUMMYTILE_HPP
