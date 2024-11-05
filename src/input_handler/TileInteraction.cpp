//
// Created by doguk on 10/27/2024.
//

#include "TileInteraction.hpp"

#include <BoogieWoogieApp.hpp>
#include <SDL_mouse.h>

void TileInteraction::Execute() const {
    int x,y;
    SDL_GetMouseState(&x, &y);

    constexpr glm::vec2 tileSize(11.32);

    const int tileX = static_cast<int>(static_cast<float>(x)/tileSize.x);
    const int tileY = static_cast<int>(static_cast<float>(y)/tileSize.y);

    const auto& tile = BoogieWoogieApp::GetInstance().GetTileManager().getTiles()[tileY][tileX];
    //Tile type function needs to be done by the Tile itself.
    tile->handleTileInteraction(nullptr);
}