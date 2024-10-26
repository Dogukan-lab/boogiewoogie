//
// Created by hmkam on 09/10/2024.
//

#include "MapBuilder.hpp"

#include <DataEntry.hpp>
#include <stdexcept>

#include "Tile.hpp"

MapBuilder &MapBuilder::setNeighbours() {
    return *this;
}

MapBuilder &MapBuilder::setMapSize(const int rows, const int cols) {
    //Try to resize tilemap.
    tileMap.resize(rows);
    for (auto &buffer: tileMap) {
        buffer.resize(cols);
    }

    return *this;
}

MapBuilder &MapBuilder::addTile(DataEntry &entry) {
    glm::vec2 tilePos(std::stof(entry["x"]),std::stof(entry["y"]));
    char tag = entry["tag"][0];
    const auto it = std::find_if(tileTypes.begin(), tileTypes.end(), [&tag=tag](const std::unique_ptr<TileType> &type) {return type->tag == tag;});

    if(it == tileTypes.end())
        return *this;

    Tile tile{
        **it, //Disgusting...
        tilePos,
        Shape()
    };

    tileMap[static_cast<int>(tilePos.y)][static_cast<int>(tilePos.x)];

    return *this;
}

MapBuilder &MapBuilder::addTileType(DataEntry &entry) {
    TileType type{
        entry["tag"][0],
        SDL_Colour{
            static_cast<Uint8>(std::stoi(entry["r"])),
            static_cast<Uint8>(std::stoi(entry["g"])),
            static_cast<Uint8>(std::stoi(entry["b"])),
            255
        },
        std::stoi(entry["weight"])
    };

    tileTypes.emplace_back(std::make_unique<TileType>(type));

    return *this;
}

std::vector<std::vector<std::unique_ptr<Tile>>> &&MapBuilder::build() {
    //Loop through 2d array and set neighbours
    for(int y = 0; y < tileMap.size(); y++ ) {
        for(int x = 0; x < tileMap[0].size(); x++) {
            const auto& tile = tileMap[y][x];

            if(y > 0) //Check to add upper neighbour
                checkAndAddNeighbour(*tile, *tileMap[y-1][x]);
            if(y < tileMap.size() - 1) //Check to add lower neighbour
                checkAndAddNeighbour(*tile, *tileMap[y+1][x]);
            if(x > 0) //Check to add left neighbour
                checkAndAddNeighbour(*tile, *tileMap[y][x-1]);
            if(x < tileMap[0].size() -1) //Check to add right neighbour
                checkAndAddNeighbour(*tile, *tileMap[y][x+1]);
        }
    }

    return std::move(tileMap);
}

void MapBuilder::checkAndAddNeighbour(Tile& cur, Tile& neighbour) {
    if(neighbour.type.tag == 'W')
        return;
    cur.neighbours.push_back(&neighbour);
}
