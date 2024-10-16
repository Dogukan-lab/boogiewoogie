//
// Created by hmkam on 09/10/2024.
//

#ifndef MAPBUILDER_HPP
#define MAPBUILDER_HPP
#include <iostream>
#include <stdexcept>

#include "Builder.hpp"
#include <memory>

class MapBuilder : public Builder<Map> {
public:
    MapBuilder &addTile(const std::shared_ptr<Tile> &tile) {
        map.tiles.emplace_back(tile);
        return *this;
    }

    MapBuilder &addTiles(const std::vector<std::shared_ptr<Tile> > &tiles) {
        for (const auto &tile: tiles) {
            addTile(tile);
        }
        return *this;
    }

    MapBuilder &replaceTiles(const std::vector<std::shared_ptr<Tile> > &tiles) {
        map.tiles.clear();
        map.tiles = tiles;
        return *this;
    }

    Map &build() override {
        // Link tiles to neighbours
        for (std::shared_ptr<Tile> &tile: map.tiles) {
            for (auto &neighbour: tile->neighbours) {
                std::shared_ptr<Tile> *foundNeighbour = nullptr;
                if (this->doesExist(neighbour->position, foundNeighbour)) {
                    neighbour = *foundNeighbour;
                } else {
                    throw std::runtime_error("Neighbour tile not found at position (" +
                                             std::to_string(neighbour->position.x) + ", " +
                                             std::to_string(neighbour->position.y) + ")");
                }
            }
        }

        return map;
    }

    bool doesExist(const Vector2D &tilePosition, std::shared_ptr<Tile> *&_tile) {
        for (std::shared_ptr<Tile> &tile: map.tiles) {
            if (tilePosition == tile->position) {
                _tile = &tile;
                return true;
            }
        }

        _tile = nullptr;
        return false;
    }

private:
    Map map;
};


#endif //MAPBUILDER_HPP
