//
// Created by doguk on 10/16/2024.
//

#ifndef TILEMANAGER_HPP
#define TILEMANAGER_HPP
#include <memory>
#include <vector>

class DummyTile;

class TileManager {
public:

    TileManager();

    explicit TileManager(int capacity);

    void AddTile(const DummyTile& tile);

    //Iterator for removing it from the list.
    void RemoveTile(DummyTile tile);

    //Getters for tiles
    // DummyTile& getTile();
    std::vector<std::unique_ptr<DummyTile>>& getTiles();

private:
    std::vector<std::shared_ptr<DummyTile>> _tiles;
};



#endif //TILEMANAGER_HPP
