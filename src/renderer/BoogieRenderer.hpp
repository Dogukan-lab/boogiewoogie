//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIERENDERER_HPP
#define BOOGIERENDERER_HPP
#include <memory>
#include <SDL_render.h>
#include <vector>
#include "../dummydata/DummyTile.hpp"


//TODO Figure out how this will function
class BoogieRenderer {
public:
    explicit BoogieRenderer(SDL_Window* window);

    ~BoogieRenderer();

    void RegisterTiles(const std::vector<std::unique_ptr<DummyTile>>& tile);

    void Draw() const;
    void DrawInstance();

private:
    std::vector<DummyTile*> _tiles;
    SDL_Renderer* renderContext;
};



#endif //BOOGIERENDERER_HPP
