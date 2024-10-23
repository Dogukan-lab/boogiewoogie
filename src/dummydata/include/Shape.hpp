//
// Created by doguk on 10/21/2024.
//

#ifndef SHAPE_HPP
#define SHAPE_HPP

enum class ShapeType {
    Rectangle,
    Other,
};

struct Shape {
    Shape(): Shape(32,32,0,0,ShapeType::Rectangle){}

    Shape(int width, int height): Shape(width, height, 0,0,ShapeType::Rectangle){}

    Shape(int width, int height, int newPosX, int newPosY, ShapeType type): width(width), height(height),posX(newPosX), posY(newPosY), shape(type){}

    int GetWidth() const{ return width;}
    int GetHeight() const{ return height;}
    int GetX() const{ return posX;}
    int GetY() const{ return posY;}
    ShapeType GetShape() const{ return shape;}

private:
    ShapeType shape;
    int width;
    int height;
    int posX;
    int posY;
};
#endif //SHAPE_HPP
