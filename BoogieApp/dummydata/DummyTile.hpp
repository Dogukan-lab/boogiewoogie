//
// Created by doguk on 10/17/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP

#include <matrix.hpp>
#include <SDL_rect.h>

struct DummyTile {
    glm::mat2 dimensions; //First row coords, second row width and height.
    SDL_Rect rectangle;
};

#endif //DUMMYTILE_HPP