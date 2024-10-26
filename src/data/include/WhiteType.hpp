//
// Created by doguk on 10/26/2024.
//

#ifndef WHITETYPE_HPP
#define WHITETYPE_HPP
#include "TileType.hpp"

class WhiteType: public TileType {
public:
    WhiteType(): TileType('W') {}

    void handleInteract() override {}
};

#endif //WHITETYPE_HPP
