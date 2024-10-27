//
// Created by hmkam on 09/10/2024.
//

#include "MapBuilder.hpp"

#include <DataEntry.hpp>
#include <stdexcept>
#include <TileManager.hpp>

#include "BlueType.hpp"
#include "GreyType.hpp"
#include "RedType.hpp"
#include "Tile.hpp"
#include "WhiteType.hpp"
#include "YellowType.hpp"

MapBuilder &MapBuilder::setNeighbours() {
    return *this;
}

MapBuilder &MapBuilder::setMapSize(DataEntry &entry) {
    //Try to resize tilemap.
    tileMap.resize(std::stoi(entry["rows"]));
    for (auto &rows: tileMap) {
        rows.resize(std::stoi(entry["cols"]));

    }

    for(int y = 0; y < tileMap.size(); y++) {
        for(int x =0; x < tileMap[0].size(); x++) {
            std::unique_ptr<Tile> tile = std::make_unique<Tile>(glm::vec2(x,y), Shape());
            tile->SetType<WhiteType>();
            tileMap[y][x] = std::move(tile);
        }
    }

    return *this;
}

MapBuilder &MapBuilder::addTile(DataEntry &entry) {
    glm::vec2 tilePos(std::stof(entry["x"]), std::stof(entry["y"]));
    auto tile = std::make_unique<Tile>(tilePos, Shape());
    //Checking for type
    switch (entry["type"][0]) {
        case '_':
            tile->SetType<WhiteType>();
        break;
        case 'Y':
            tile->SetType<YellowType>();
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

    tileMap[static_cast<int>(tilePos.y)][static_cast<int>(tilePos.x)] = std::move(tile);

    return *this;
}

MapBuilder &MapBuilder::addTileType(DataEntry &entry) {
    //Order tiles by type.
    const char tag = entry["type"][0];
    const std::pair configuration = {
        SDL_Colour{
            static_cast<Uint8>(std::stoi(entry["r"])),
            static_cast<Uint8>(std::stoi(entry["g"])),
            static_cast<Uint8>(std::stoi(entry["b"])),
            255
        },
        std::stoi(entry["weight"])
    };
    TileManager::SetType(tag, configuration);

    return *this;
}

std::vector<std::vector<std::unique_ptr<Tile> > > &&MapBuilder::build() {
    //Loop through 2d array and set neighbours
    for (int y = 0; y < tileMap.size(); y++) {
        for (int x = 0; x < tileMap[0].size(); x++) {
            const auto &tile = tileMap[y][x];

            if (y > 0) //Check to add upper neighbour
                checkAndAddNeighbour(*tile, *tileMap[y - 1][x]);
            if (y < tileMap.size() - 1) //Check to add lower neighbour
                checkAndAddNeighbour(*tile, *tileMap[y + 1][x]);
            if (x > 0) //Check to add left neighbour
                checkAndAddNeighbour(*tile, *tileMap[y][x - 1]);
            if (x < tileMap[0].size() - 1) //Check to add right neighbour
                checkAndAddNeighbour(*tile, *tileMap[y][x + 1]);
        }
    }

    return std::move(tileMap);
}

void MapBuilder::checkAndAddNeighbour(Tile &cur, Tile &neighbour) {
    if (neighbour.type->tag == 'W')
        return;
    cur.neighbours.push_back(&neighbour);
}
