//
// Created by doguk on 10/9/2024.
//

#include "BoogieRenderer.hpp"

#include <SDL_render.h>

BoogieRenderer::BoogieRenderer(SDL_Window &window) {
    renderContext.reset(SDL_CreateRenderer(&window, -1, SDL_RENDERER_ACCELERATED));
}

void BoogieRenderer::RegisterTiles(std::shared_ptr<DummyTile> tile) {
    _tiles.emplace_back(tile);
}

void BoogieRenderer::Draw() {
    for(const auto& tileRef: _tiles) {
        if(auto tile = tileRef.lock()) {
            SDL_RenderDrawRect(renderContext.get(), &tile->getShape<Rectangle>().rectangle);
        }
    }
}
