//
// Created by doguk on 10/21/2024.
//

#ifndef DUMMYARTIST_HPP
#define DUMMYARTIST_HPP
#include <cstdio>
#include <SDL_Rect.h>
#include <vec2.hpp>

#include "DummyTile.hpp"

class Artist {
public:
    Artist();

    Artist(Shape shape, SDL_Colour colour, glm::vec2 startPos, glm::vec2 direction);

    void Move(float deltaTime);

    Shape& GetShape() ;
    SDL_Colour& GetColour();
    glm::vec2& GetPosition();
    glm::vec2& GetDirection();

private:
    SDL_Colour colour;
    Shape artistbody;
    glm::vec2 position;
    glm::vec2 direction;//This will always be a normalized vector
};


#endif //DUMMYARTIST_HPP
