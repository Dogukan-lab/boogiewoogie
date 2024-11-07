//
// Created by doguk on 10/21/2024.
//

#ifndef DUMMYARTIST_HPP
#define DUMMYARTIST_HPP
#include <cstdio>
#include <Memento.hpp>
#include <SDL_Rect.h>
#include <Shape.hpp>
#include <vec2.hpp>

class Artist {
public:
    Artist();
    Artist(const glm::vec2 startPos, const glm::vec2 direction);

    Artist(const Shape shape, const SDL_Colour colour, const glm::vec2 startPos, const glm::vec2 direction, glm::ivec2 lastTile = glm::ivec2(0));

    void Move(float deltaTime);

    Shape &GetShape() { return artistbody; }
    SDL_Colour &GetColour() { return colour; }
    glm::vec2 &GetPosition() { return position; }
    glm::vec2 &GetDirection() { return direction; }

    glm::ivec2& GetLastTile() { return lastTile;}

    bool shouldBeDeleted = false;
private:
    SDL_Colour colour;
    Shape artistbody;
    glm::vec2 position;
    glm::vec2 direction; //This will always be a normalized vector
    glm::ivec2 lastTile{};
};


#endif //DUMMYARTIST_HPP