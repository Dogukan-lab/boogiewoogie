//
// Created by doguk on 10/9/2024.
//

#include "BoogieRenderer.hpp"
#include <algorithm>
#include <BoogieWoogieApp.hpp>
#include <SDL_render.h>

BoogieRenderer::BoogieRenderer(SDL_Window *window): renderContext(
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)),
shouldRenderArtist(true){
}

BoogieRenderer::~BoogieRenderer() {
    _tiles.clear();
    _artists.clear();
    SDL_DestroyRenderer(renderContext);
}

void BoogieRenderer::RegisterArtist(Artist &artist) {
    auto it = std::find_if(_artists.begin(), _artists.end(), [&artist=artist](const Artist *pArtist) {
        return &artist ==
               pArtist;
    });
    if (it == _artists.end())
        _artists.emplace_back(&artist);
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

void BoogieRenderer::DeleteArtist(const Artist &artist) {
    auto it = std::remove_if(_artists.begin(), _artists.end(), [&elemToDelete=artist](const Artist *artist) {
        return &elemToDelete == artist;
    });
    if (it != _artists.end())
        _artists.erase(it);
}

void BoogieRenderer::ClearTiles() {
    _tiles.clear();
}

void BoogieRenderer::ClearArtists() {
    _artists.clear();
}

void BoogieRenderer::Draw() const {
    SDL_SetRenderDrawColor(renderContext, 255, 255, 255, 255);
    SDL_RenderClear(renderContext);

    //Draw tiles
    for (const auto &tile: _tiles) {
        const auto &pos = tile->position;
        auto &shape = tile->shape;
        const auto &colour = tile->type->colour;
        SDL_FRect rect{
            pos.x * shape.GetDimension().x,
            pos.y * shape.GetDimension().y,
            shape.GetDimension().x,
            shape.GetDimension().y
        };
        SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderFillRectF(renderContext, &rect);
    }

    if (shouldRenderArtist) {
        //Draw Artists
        for (const auto &artist: _artists) {
            auto &dimension = artist->GetShape().GetDimension();
            auto &pos = artist->GetPosition();
            auto &colour = artist->GetColour();
            //TODO have shape always scaled
            SDL_FRect rect{
                dimension.x * pos.x + dimension.x / 4.f,
                dimension.y * pos.y + dimension.y / 4.f,
                dimension.x / 2.f,
                dimension.y / 2.f
            };
            SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
            SDL_RenderFillRectF(renderContext, &rect);
        }
    }
    SDL_RenderPresent(renderContext);
}


void BoogieRenderer::DrawInstance(Memento &memento) {
    SDL_SetRenderDrawColor(renderContext, 255, 255, 255, 255);
    SDL_RenderClear(renderContext);

    //Draw tiles
    for (auto &tile: memento.GetTiles()) {
        auto &pos = tile.pos;
        auto &shape = tile.shape;
        auto &colour = tile.colour;
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
    for (auto &artist: memento.GetArtists()) {
        auto &dimension = artist.shape.GetDimension();
        auto &pos = artist.position;
        auto &colour = artist.colour;
        SDL_FRect rect{
            dimension.x * pos.x + dimension.x / 4.f,
            dimension.y * pos.y + dimension.y / 4.f,
            dimension.x / 2.f,
            dimension.y / 2.f
        };
        SDL_SetRenderDrawColor(renderContext, colour.r, colour.g, colour.b, colour.a);
        SDL_RenderFillRectF(renderContext, &rect);
    }

    SDL_RenderPresent(renderContext);
}