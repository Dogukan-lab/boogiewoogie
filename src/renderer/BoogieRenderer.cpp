//
// Created by doguk on 10/9/2024.
//

#include "BoogieRenderer.hpp"
#include <SDL_render.h>

BoogieRenderer::BoogieRenderer(SDL_Window *window): renderContext(
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) {
}

BoogieRenderer::~BoogieRenderer() {
    _tiles.clear();
    SDL_DestroyRenderer(renderContext);
}

void BoogieRenderer::RegisterTiles(const std::vector<std::unique_ptr<Tile> > &tiles) {
    for (auto &tile: tiles) {
        _tiles.emplace_back(tile.get());
    }
}

void BoogieRenderer::RegisterArtists(const std::vector<std::unique_ptr<Artist> > &artists) {
    for (const auto &artist: artists) {
        _artists.emplace_back(artist.get());
    }
}

void BoogieRenderer::Draw() const {
    SDL_SetRenderDrawColor(renderContext, 255, 255, 255, 255);
    SDL_RenderClear(renderContext);
    //Draw tiles
    for (const auto &tile: _tiles) {
        auto &shape = tile->shape;
        // auto &colour = tile->type.colour;
        //TODO have shape always scaled
        // SDL_Rect rect{
            // shape.GetX() * shape.GetWidth(), shape.GetY() * shape.GetHeight(), shape.GetWidth(), shape.GetHeight()
        // };
        // SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        // SDL_RenderFillRect(renderContext, &rect);
    }

    //Draw Artists
    for (const auto &artist: _artists) {
        // auto &shape = artist->GetShape();
        // auto &colour = artist->GetColour();
        //TODO have shape always scaled
        // SDL_FRect rect{
            // shape.GetWidth() * artist->GetPosition().x,
            // shape.GetHeight() * artist->GetPosition().y,
            // shape.GetWidth() / 2.f,
            // shape.GetHeight() / 2.f
        // };
        // SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        // SDL_RenderFillRectF(renderContext, &rect);
    }

    SDL_RenderPresent(renderContext);
}
