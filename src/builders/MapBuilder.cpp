//
// Created by hmkam on 09/10/2024.
//

#include "MapBuilder.hpp"
#include "Tile.hpp"

MapBuilder::MapBuilder(): tileMap(std::vector<std::vector<Tile>>()) {
}

//TODO Figure out how to set neighbours properly
MapBuilder& MapBuilder::setNeighbours() {
    //Loop through the tile map, but only look for the four cardinal directions.
    for(int i = 0; i < tileMap.size(); i++) {
        for(int j = 0; j < tileMap[0].size(); j++) {
            auto& tile = tileMap[i][j];
            const glm::ivec2& tilePos = tile.shape.GetPosition();

            //North
            tile.neighbours.emplace_back(&tileMap[tilePos.x][tilePos.y-1]);
            //South
            tile.neighbours.emplace_back(&tileMap[tilePos.x][tilePos.y+1]);
            //East
            tile.neighbours.emplace_back(&tileMap[tilePos.x+1][tilePos.y]);
            //West
            tile.neighbours.emplace_back(&tileMap[tilePos.x-1][tilePos.y]);
        }
    }

    return *this;
}

//TODO Debug if this allocated properly!
MapBuilder& MapBuilder::setMapSize(const int rows, const int cols) {
    tileMap.resize(rows);
    for(auto& row: tileMap) {
        row.resize(cols);
    }
    return *this;
}

MapBuilder& MapBuilder::addTile(const Tile &tile) {
    //Checks the type, and converts it to integer for tile map lookup
    const glm::ivec2& position = tile.shape.GetPosition();
    tileMap[position.x][position.y] = tile;
    return *this;
}

MapBuilder& MapBuilder::addTiles(const std::vector<Tile> &tiles) {
    //Loop through each tile that we have parsed and add them to the
    for(const auto& tile: tiles) {
        addTile(tile);
    }
    return *this;
}

std::vector<std::vector<Tile>> && MapBuilder::build() {
    return std::move(tileMap);
}
