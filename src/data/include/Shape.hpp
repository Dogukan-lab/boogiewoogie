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
    Shape(): Shape(32,32, ShapeType::Rectangle){}

    Shape(int width, int height): Shape(width, height, ShapeType::Rectangle){}

    Shape(int width, int height, ShapeType type): dimensions(width, height), shape(type){}

    glm::vec2 GetDimension() const { return dimensions;}
    ShapeType GetShape() const{ return shape;}

private:
    ShapeType shape;
    glm::vec2 dimensions;
};
#endif //SHAPE_HPP
