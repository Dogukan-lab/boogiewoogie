//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <SDL_rect.h>
#include <stdexcept>

enum class ShapeType {
    Rectangle,
    Other,
};

struct Shape {
    Shape(): Shape(32,32,0,0,ShapeType::Rectangle){}

    Shape(int width, int height): Shape(width, height, 0,0,ShapeType::Rectangle){}

    Shape(int width, int height, int newPosX, int newPosY, ShapeType type): width(width), height(height),posX(newPosX), posY(newPosY), shape(type){}

    int getWidth() const{ return width;}
    int getHeight() const{ return height;}
    int getX() const{ return posX;}
    int getY() const{ return posY;}
    ShapeType getShape() const{ return shape;}

private:
    ShapeType shape;
    int width;
    int height;
    int posX;
    int posY;
};

struct DummyTileType {
    char tag;
    SDL_Colour colour;
    int weight; //Not relevant for now
    //Maybe use shape here instead?

    DummyTileType(const char &character, const SDL_Colour& colour, const int &weight): tag(character), weight
    (weight), colour(colour) {
    }
};

class DummyTile {
public:
    explicit DummyTile(const DummyTileType &type, const Shape& shape): type(type), shape(shape) {
    }

    //Counter intuitive :(
    Shape shape;
    DummyTileType type;
};
#endif //DUMMYTILE_HPP
