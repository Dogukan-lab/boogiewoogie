//
// Created by doguk on 10/21/2024.
//

#ifndef DUMMYARTIST_HPP
#define DUMMYARTIST_HPP
#include <cstdio>
#include <SDL_Rect.h>
#include <Shape.hpp>
#include <vec2.hpp>


class Artist {
public:
    Artist();

    Artist(const Shape shape, const SDL_Colour colour, const glm::vec2 startPos, const glm::vec2 direction);

    void Move(float deltaTime);

    Shape &GetShape() { return artistbody; }
    SDL_Colour &GetColour() { return colour; }
    glm::vec2 &GetPosition() { return position; }
    glm::vec2 &GetDirection() { return direction; }

private:
    SDL_Colour colour;
    Shape artistbody;
    glm::vec2 position;
    glm::vec2 direction; //This will always be a normalized vector
};


#endif //DUMMYARTIST_HPP
