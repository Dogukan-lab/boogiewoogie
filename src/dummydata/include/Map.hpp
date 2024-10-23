//
// Created by doguk on 10/9/2024.
//

#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
struct DummyTile;

struct Map {
    Map() = default;

    std::vector<DummyTile> tiles;
};



#endif //MAP_HPP
