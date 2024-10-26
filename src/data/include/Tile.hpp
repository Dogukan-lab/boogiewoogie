//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <SDL_rect.h>
#include <vector>
#include "Shape.hpp"

struct TileType {
    char tag;
    SDL_Colour colour;
    int weight;

    TileType(const char &character, const SDL_Colour& colour, const int &weight): tag(character), colour(colour), weight(weight) {
    }
    void handleInteract();
};

class Tile {
public:
    Tile(const TileType &type, const glm::vec2& pos,const Shape& shape): type(type), position(pos),shape(shape) {
    }

    ~Tile() {
        neighbours.clear();
    }

    template<typename T>
    void SetType() {
    }

    Shape shape;
    glm::vec2 position;
    TileType type;
    std::vector<Tile*> neighbours{};
};
#endif //DUMMYTILE_HPP
