//
// Created by doguk on 10/21/2024.
//
#include "Artist.hpp"
#include <geometric.hpp>
#include "Shape.hpp"

Artist::Artist(): Artist(Shape(), {0,0,0,255}, {1.f, 1.f}, {0.5f, 0.f}){}

Artist::Artist(const Shape shape, const SDL_Color colour, const glm::vec2 startPos, const glm::vec2 direction): colour(colour), artistbody(shape), position(startPos), direction(direction){}

// Certainly! This code snippet will provide an Artist to move with the glm::vec2 data type you have suggested.
void Artist::Move(const float deltaTime) {
    //TODO Bounds
    // std::cout << "MOVING: " << position.x << "," << position.y << "\n";
    // std::cout << "DIRECTION: " << direction.x << "," << direction.y << "\n";

    //Second option, which is kind of weird.
    position.x += direction.x * deltaTime / 10.f;
    position.y +=  direction.y * deltaTime / 10.f;
    direction = glm::normalize(direction);
}

Shape& Artist::GetShape() {
    return artistbody;
}


SDL_Color& Artist::GetColour() {
    return colour;
}

glm::vec2& Artist::GetPosition() {
    return position;
}

glm::vec2& Artist::GetDirection() {
    return direction;
}
