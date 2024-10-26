//
// Created by hmkam on 09/10/2024.
//

#ifndef MAPBUILDER_HPP
#define MAPBUILDER_HPP

#include <algorithm>
#include <Tile.hpp>

#include "Builder.hpp"
#include <vector>

class DataEntry;

//TODO Remove the templating, and just accept to use a singleton instance of the manager
class MapBuilder : public Builder<std::vector<std::vector<std::unique_ptr<Tile>>>> {
public:
    MapBuilder();
    ~MapBuilder() override;

    MapBuilder& setNeighbours();
    MapBuilder& setMapSize(const int rows, const int cols);
    MapBuilder& addTile(DataEntry& entry);
    MapBuilder& addTileType(DataEntry& entry);
    MapBuilder& addTiles(std::vector<DataEntry>& entries);

    std::vector<std::vector<std::unique_ptr<Tile>>>&& build() override;

private:
    std::vector<std::vector<std::unique_ptr<Tile>>> tileMap;
    std::vector<std::unique_ptr<TileType>> tileTypes;

    static void checkAndAddNeighbour(Tile& cur, Tile& neighbour);
};


#endif //MAPBUILDER_HPP
