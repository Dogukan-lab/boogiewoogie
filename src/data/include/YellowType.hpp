//
// Created by doguk on 10/26/2024.
//

#ifndef YELLOWTYPE_HPP
#define YELLOWTYPE_HPP
#include "TileType.hpp"

class YellowType: public TileType{
public:
    explicit YellowType()
        : TileType('Y') {
    }

    //Something something Artist.Create()
    void handleInteract() override {
    }
};

#endif //YELLOWTYPE_HPP
