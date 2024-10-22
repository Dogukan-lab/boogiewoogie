//
// Created by hmkam on 09/10/2024.
//

#ifndef MAPBUILDER_HPP
#define MAPBUILDER_HPP

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
            // Use an iterator to loop through neighbours
            for (auto it = tile->neighbours.begin(); it != tile->neighbours.end();) {
                std::shared_ptr<Tile> *foundNeighbour = nullptr;
                if (this->doesExist((*it)->position, foundNeighbour)) {
                    // If the neighbour exists, update the shared pointer
                    *it = *foundNeighbour;
                    ++it;
                } else {
                    // Remove the neighbour if it doesn't exist
                    it = tile->neighbours.erase(it);
                }
            }
        }

        return map;
    }

private:
    bool doesExist(const Vector2D<int> &tilePosition, std::shared_ptr<Tile> *&_tile) {
        for (std::shared_ptr<Tile> &tile: map.tiles) {
            if (tilePosition == tile->position) {
                _tile = &tile;
                return true;
            }
        }

        _tile = nullptr;
        return false;
    }

    Map map;
};


#endif //MAPBUILDER_HPP