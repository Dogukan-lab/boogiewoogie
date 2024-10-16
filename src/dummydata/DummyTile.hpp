//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <SDL_rect.h>

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

    DummyTileType(const char& character, int* colours, const int& weight):
    tag(character), weight(weight) {
        std::copy(colours, colours + 3, rgb);
    }
};

struct DummyTile {
    DummyTile(const DummyTileType &type, const Shape &newShape): shape(newShape), type(type) {
    }

    template<typename T>
    T& getShape() {
        return static_cast<T&>(shape);
    }

    Shape shape;
    DummyTileType type;
};
#endif //DUMMYTILE_HPP
