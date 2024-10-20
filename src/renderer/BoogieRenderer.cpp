//
// Created by doguk on 10/9/2024.
//

#include "BoogieRenderer.hpp"
#include <SDL_render.h>

BoogieRenderer::BoogieRenderer(SDL_Window* window): renderContext(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) {
}

BoogieRenderer::~BoogieRenderer() {
    _tiles.clear();
    SDL_DestroyRenderer(renderContext);
}

void BoogieRenderer::RegisterTiles(const std::vector<std::unique_ptr<DummyTile>>& tiles) {
    for(auto& tile: tiles) {
        _tiles.emplace_back(tile.get());
    }
}

void BoogieRenderer::Draw() const {
    SDL_SetRenderDrawColor(renderContext, 255,255,255,255);
    SDL_RenderClear(renderContext);
    for(const auto& tile: _tiles) {
        auto& shape = tile->shape;
        auto& colour = tile->type.colour;
        SDL_Rect rect{shape.getX()*shape.getWidth(), shape.getY()*shape.getHeight(), shape.getWidth(), shape.getHeight()};
        SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderFillRect(renderContext, &rect);
    }

    SDL_RenderPresent(renderContext);
}
