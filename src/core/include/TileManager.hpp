//
// Created by doguk on 10/16/2024.
//

#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP
#include "Tile.hpp"
#include <map>

class TileManager {
public:
    TileManager();

    explicit TileManager(int capacity);

    void AddTiles(std::vector<std::vector<std::unique_ptr<Tile> > > &&tileMap) { _tiles = std::move(tileMap); }

    static std::pair<SDL_Colour, int>& GetType(const char c) {
        return types.at(c);
    }

    static void SetType(const char tag, const std::pair<SDL_Colour, int> config) {
        types[tag] = config;
    }

    std::vector<std::vector<std::unique_ptr<Tile> > > &getTiles();

    static std::map<char, std::pair<SDL_Colour, int> > types;
private:
    std::vector<std::vector<std::unique_ptr<Tile> > > _tiles;
};


#endif //TILEMANAGER_HPP
