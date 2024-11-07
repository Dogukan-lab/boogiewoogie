//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <memory>
#include <vector>
#include "Shape.hpp"
#include "TileType.hpp"

class Tile {
public:
    Tile(const glm::vec2 pos, const Shape shape): shape(shape), position(pos),
    type(nullptr) {
    }

    ~Tile() {
        neighbours.clear();
    }

    Tile(const Tile& other) {
        char tag = type->tag;
        switch (tag) {
            case '_':
                SetType<WhiteType>();
                break;
            case 'Y':
                SetType<YellowType>();
                break;
            case 'R':
                tile->SetType<RedType>();
                break;
            case 'G':
                tile->SetType<GreyType>();
                break;
            case 'B':
                tile->SetType<BlueType>();
                break;
            default: break;
        }
    }

    template<typename T>
    void SetType() {
        type = std::make_unique<T>();
    }

    inline void handleTileInteraction(Artist* currentArtist) {
        type->handleInteract(this, currentArtist);
    }

    Shape shape;
    glm::vec2 position;
    std::unique_ptr<TileType> type;
    std::vector<Tile*> neighbours{};
};
#endif //DUMMYTILE_HPP