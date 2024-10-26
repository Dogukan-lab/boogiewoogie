//
// Created by doguk on 10/26/2024.
//

#ifndef REDTYPE_HPP
#define REDTYPE_HPP
#include "TileType.hpp"

class RedType: public TileType {
public:
    RedType(): TileType('R'){}

    ~RedType() override = default;

    void handleInteract() override {}
};

#endif //REDTYPE_HPP
