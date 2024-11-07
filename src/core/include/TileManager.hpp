//
// Created by doguk on 10/16/2024.
//

#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP
#include <BoogieRenderer.hpp>
#include "Tile.hpp"
#include <map>

class TileManager {
public:
    explicit TileManager(BoogieRenderer& renderer);

    explicit TileManager(int capacity, BoogieRenderer& renderer);

    void AddTiles(std::vector<std::vector<std::unique_ptr<Tile> > > &&tileMap);

    static std::pair<SDL_Colour, int>& GetType(const char c) {
        return types.at(c);
    }

    static void SetType(const char tag, const std::pair<SDL_Colour, int> config) {
        types[tag] = config;
    }

    std::vector<std::vector<std::unique_ptr<Tile> > > &getTiles();

    static std::map<char, std::pair<SDL_Colour, int> > types;


    std::vector<tileCopy> Save() ;
private:
    std::vector<std::vector<std::unique_ptr<Tile> > > _tiles;
    BoogieRenderer& _renderer;
};


#endif //TILEMANAGER_HPP