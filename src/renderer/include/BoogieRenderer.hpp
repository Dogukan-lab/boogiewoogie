//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIERENDERER_HPP
#define BOOGIERENDERER_HPP
#include <memory>
#include <SDL_render.h>
#include <vector>
#include "DummyTile.hpp"
#include "DummyArtist.hpp"

//TODO Figure out how this will function
class BoogieRenderer {
public:
    explicit BoogieRenderer(SDL_Window* window);

    ~BoogieRenderer();

    void RegisterTiles(const std::vector<std::unique_ptr<DummyTile>>& tile);
    void RegisterArtists(const std::vector<std::unique_ptr<Artist>>& artists);

    void Draw() const;
    void DrawInstance();

private:
    std::vector<DummyTile*> _tiles;
    std::vector<Artist*> _artists;
    SDL_Renderer* renderContext;
};

#endif //BOOGIERENDERER_HPP
