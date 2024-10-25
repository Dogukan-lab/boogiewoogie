//
// Created by doguk on 10/16/2024.
//

#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP
#include <memory>
#include <vector>

class Tile;

class TileManager {
public:

    TileManager();

    explicit TileManager(int capacity);

    void AddTile(const Tile& tile);

    //Iterator for removing it from the list.
    void RemoveTile(const Tile& tile);

    //Getters for tiles
    // DummyTile& getTile();
    std::vector<std::unique_ptr<Tile>>& getTiles();

private:
    std::vector<std::unique_ptr<Tile>> _tiles;
};



#endif //TILEMANAGER_HPP
