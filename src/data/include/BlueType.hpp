//
// Created by doguk on 10/26/2024.
//

#ifndef BLUETYPE_HPP
#define BLUETYPE_HPP
#include "TileType.hpp"

class BlueType: public TileType {
public:
    BlueType(): TileType('B'){}
    void handleInteract() override {}

};
#endif //BLUETYPE_HPP
