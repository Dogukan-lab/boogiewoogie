//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <SDL_rect.h>

namespace bw {
    struct vec2 {
        int x, y;

        //Adds a vector 2 with default value 0
        vec2(): vec2(0) {
        }

        //Adds a vector 2 integer with a default value of 0 for x and y.
        explicit vec2(const int scalar): vec2(scalar, scalar){}
        vec2(const int posX, const int posY): x(posX), y(posY) {
        }
    };

    struct vec2f {
        float x, y;
        //Adds a vector 2 float with a default value of 0 for x and y.
        vec2f(): vec2f(0.f) {}
        vec2f(const float posX, const float posY): x(posX), y(posY) {}
        explicit vec2f(const float scalar): x(scalar), y(scalar) {}
    };
}

struct Shape {
    Shape() = default;
    virtual ~Shape() = default;
};

struct Rectangle final : Shape {
    //Initialize SDL_Rect with standard units of 50,50 pixels.
    Rectangle(): Rectangle(50, 50) {}

    Rectangle(const int newWidth, const int newHeight): Rectangle(newWidth, newHeight, 0, 0) {}

    Rectangle(const int newWidth, const int newHeight, const int newPosX, const int
              newPosY) {
        rectangle.w = newWidth;
        rectangle.h = newHeight;
        rectangle.x = newPosX;
        rectangle.y = newPosY;
    }

    SDL_Rect rectangle{};
};

struct DummyTileType {
    char tag;
    int rgb[3];
    int weight; //Not relevant for now
    //Maybe use shape here instead?
};

struct DummyTile {
    DummyTile(): DummyTile(DummyTileType(), Shape(), bw::vec2(0, 0)) {
    }

    DummyTile(const DummyTileType &type, const Shape &newShape,
              const bw::vec2 &newPos): shape(newShape), type(type), position(newPos) {
    }

    Shape shape;
    DummyTileType type;
    bw::vec2 position;
};
#endif //DUMMYTILE_HPP
