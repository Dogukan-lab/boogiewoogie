//
// Created by doguk on 10/26/2024.
//

#ifndef GREYTYPE_HPP
#define GREYTYPE_HPP
#include "TileType.hpp"

class GreyType: public TileType {
public:
    GreyType(): TileType('G') {}

    void handleInteract() override {}
};
#endif //GREYTYPE_HPP
