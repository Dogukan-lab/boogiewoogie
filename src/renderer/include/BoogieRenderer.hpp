//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIERENDERER_HPP
#define BOOGIERENDERER_HPP
#include <memory>
#include <SDL_render.h>
#include <vector>

#include "Tile.hpp"
#include "Artist.hpp"



//TODO Figure out how this will function
class BoogieRenderer {
public:
    explicit BoogieRenderer(SDL_Window* window);

    ~BoogieRenderer();

    void RegisterTiles(const std::vector<std::vector<std::unique_ptr<Tile>>>& tile);
    void RegisterArtists(const std::vector<std::unique_ptr<Artist>>& artists);

    void Draw() const;
    void DrawInstance();

private:
    std::vector<Tile*> _tiles;
    std::vector<Artist*> _artists;
    SDL_Renderer* renderContext;
};

#endif //BOOGIERENDERER_HPP
