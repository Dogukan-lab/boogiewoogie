//
// Created by hmkam on 09/10/2024.
//

#ifndef MAPBUILDER_HPP
#define MAPBUILDER_HPP

#include "DataEntry.hpp"
#include "Tile.hpp"
#include "Builder.hpp"
#include <vector>

//TODO Remove the templating, and just accept to use a singleton instance of the manager
class MapBuilder : public Builder<std::vector<std::vector<std::unique_ptr<Tile>>>> {
public:
    MapBuilder() = default;
    ~MapBuilder() override = default;

    MapBuilder& setNeighbours();
    MapBuilder& setMapSize(DataEntry& entry);
    MapBuilder& addTile(DataEntry& entry);
    MapBuilder& addTileType(DataEntry& entry);
    MapBuilder& addTiles(const std::vector<DataEntry>& entries);

    std::vector<std::vector<std::unique_ptr<Tile>>>&& build() override;

private:
    std::vector<std::vector<std::unique_ptr<Tile>>> tileMap;

    static void checkAndAddNeighbour(Tile& cur, Tile& neighbour);
};


#endif //MAPBUILDER_HPP
