//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP

#include <memory>
#include <vector>

#include "TileType.hpp"
#include "Artist.hpp"
#include "Shape.hpp"

class Tile {
public:
    Tile(const glm::vec2 pos, const Shape shape) : shape(shape), position(pos),
                                                   type(nullptr) {
    }

    Tile(const glm::vec2 pos, const Shape shape, std::unique_ptr<TileType> type, std::vector<Tile*> neighbours)
        : shape(shape), position(pos), type(std::move(type)), neighbours(std::move(neighbours)) {
    }

    ~Tile() {
        neighbours.clear();
    }


    template<typename T>
    void SetType() {
        type = std::make_unique<T>();
    }

    void handleTileInteraction(Artist *currentArtist) {
        if (currentArtist == nullptr) {
            // Handle the error or return early
            return;
        }
        type->handleInteract(this, currentArtist);
    }

    Shape shape;
    glm::vec2 position;
    std::unique_ptr<TileType> type;
    std::vector<Tile *> neighbours{};
};

#endif //DUMMYTILE_HPP