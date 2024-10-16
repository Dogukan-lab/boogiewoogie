//
// Created by hmkam on 09/10/2024.
//

#ifndef MAPBUILDER_HPP
#define MAPBUILDER_HPP
#include <iostream>
#include <stdexcept>

#include "Builder.hpp"


class MapBuilder : public Builder<Map> {
public:
    MapBuilder &addTile(const Tile &tile) {
        map.tiles.emplace_back(tile);
        return *this;
    }

    MapBuilder &addTiles(const std::vector<Tile> &tiles) {
        for (const auto &tile : tiles) {
            map.tiles.emplace_back(tile);
        }
        return *this;
    }

    MapBuilder &replaceTiles(const std::vector<Tile> &tiles) {
        map.tiles.clear();
        map.tiles = tiles;
        return *this;
    }

    Map &build() override {
        // Link tiles to neighbours
        for (Tile &tile : map.tiles) {
            std::cout << "P: " << tile.position.x << " " << tile.position.y << std::endl;
            for (auto &neighbour : tile.neighbours) {
                Tile *foundNeighbour = nullptr;
                if (this->doesExist(neighbour.position, foundNeighbour)) {
                    neighbour = *foundNeighbour; //std::make_shared<Tile>(*foundNeighbour);
                } else {
                    throw std::runtime_error("Neighbour tile not found at position (" +
                                             std::to_string(neighbour.position.x) + ", " +
                                             std::to_string(neighbour.position.y) + ")");
                }
            }
        }

        return map;
    }

    bool doesExist(const Vector2D &tilePosition, Tile *& _tile) {
        for (Tile &tile : map.tiles) {
            if (tilePosition == tile.position) {
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
