//
// Created by doguk on 10/9/2024.
//

#include "BoogieRenderer.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/string_cast.hpp>
#include <iostream>
#include <SDL_render.h>

BoogieRenderer::BoogieRenderer(SDL_Window *window): renderContext(
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) {
}

BoogieRenderer::~BoogieRenderer() {
    _tiles.clear();
    SDL_DestroyRenderer(renderContext);
}

void BoogieRenderer::RegisterTiles(const std::vector<std::vector<std::unique_ptr<Tile> > > &tiles) {
    for (auto &row: tiles) {
        for (auto &tile: row) {
            _tiles.emplace_back(tile.get());
        }
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
        const auto &pos = tile->position;
        auto &shape = tile->shape;
        const auto &colour = tile->type->colour;
        //TODO have shape always scaled
        SDL_FRect rect{
            pos.x * shape.GetDimension().x,
            pos.y * shape.GetDimension().y,
            shape.GetDimension().x,
            shape.GetDimension().y
        };
        SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderFillRectF(renderContext, &rect);
    }

    //Draw Artists
    for (const auto &artist: _artists) {
        auto &dimension = artist->GetShape().GetDimension();
        auto &pos = artist->GetPosition();
        auto &colour = artist->GetColour();
        //TODO have shape always scaled
        SDL_FRect rect{
            dimension.x * pos.x + dimension.x / 4.f,
            dimension.y * pos.y + dimension.y / 4.f,
            dimension.x / 2.f ,
            dimension.y / 2.f
        };
        SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderFillRectF(renderContext, &rect);
    }

    SDL_RenderPresent(renderContext);
}
