//
// Created by doguk on 10/21/2024.
//

#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vec2.hpp>

enum class ShapeType {
    Rectangle,
    Other,
};

//TODO Shape doesnt need a position, becuase the object owning it already has it.
struct Shape {
    Shape(): Shape(32,32,0,0,ShapeType::Rectangle){}

    Shape(int width, int height): Shape(width, height, 0,0,ShapeType::Rectangle){}

    Shape(int width, int height, int newPosX, int newPosY, ShapeType type): dimensions(width, height), position(newPosX, newPosY),shape(type){}

    glm::vec2 GetDimension() const { return dimensions;}
    glm::vec2 GetPosition() const { return dimensions;}
    ShapeType GetShape() const{ return shape;}

private:
    ShapeType shape;
    glm::vec2 dimensions;
    glm::vec2 position;
};
#endif //SHAPE_HPP
