//
// Created by doguk on 10/21/2024.
//
#include "Artist.hpp"
#include <geometric.hpp>
#include "Shape.hpp"

Artist::Artist(): Artist(Shape(), {0,0,0,255}, {1.f, 1.f}, {0.5f, 0.f}){}

Artist::Artist(const glm::vec2 startPos, const glm::vec2 direction): Artist(Shape(), {0,0,0,255}, startPos, direction) {
}

Artist::Artist(const Shape shape, const SDL_Color colour, const glm::vec2 startPos, const glm::vec2 direction): colour(colour), artistbody(shape), position(startPos), direction(direction){}
