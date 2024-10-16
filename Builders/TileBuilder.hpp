//
// Created by hmkam on 09/10/2024.
//

#ifndef TILEBUILDER_HPP
#define TILEBUILDER_HPP
#include "Builder.hpp"


class TileBuilder : public Builder<Tile> {
public:
    // TileBuilder &addShape(/*SDL2Shape*/) {
    //     //Tile kunnen reffen
    // }

    Tile &build() override {
        return tiles;
    };

private:
    Tile tiles;
};

#endif //TILEBUILDER_HPP
