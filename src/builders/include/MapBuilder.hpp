//
// Created by hmkam on 09/10/2024.
//

#ifndef MAPBUILDER_HPP
#define MAPBUILDER_HPP

#include "Builder.hpp"
#include <memory>
#include <vec2.hpp>
#include <vector>

class Tile;

//TODO Might be needed to make these uptrs instead
class MapBuilder : public Builder<std::vector<std::vector<Tile>>> {
public:
    MapBuilder();
    ~MapBuilder() override;

    MapBuilder& setNeighbours();

    MapBuilder& setMapSize(const int rows, const int cols);

    MapBuilder& addTile(const Tile& tile);
    MapBuilder& addTiles(const std::vector<Tile>& tiles);

    //Why???
    MapBuilder& replaceTiles(const std::vector<Tile>& tiles);

    std::vector<std::vector<Tile>> && build() override;
private:
    static bool doesExist(const glm::vec2 &tilePosition, std::shared_ptr<Tile>*&_tile);

    std::vector<std::vector<Tile>> tileMap;
};


#endif //MAPBUILDER_HPP
