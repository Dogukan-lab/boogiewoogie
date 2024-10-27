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
    Shape(): Shape(11.32075471698113f,11.32075471698113f, ShapeType::Rectangle){}

    Shape(const float width, const float height): Shape(width, height, ShapeType::Rectangle){}

    Shape(const float width, const float height, ShapeType type): dimensions(width, height), shape(type){}

    [[nodiscard]] glm::vec2& GetDimension() { return dimensions;}
    [[nodiscard]] ShapeType& GetShape() { return shape;}

private:
    ShapeType shape;
    glm::vec2 dimensions;
};
#endif //SHAPE_HPP
