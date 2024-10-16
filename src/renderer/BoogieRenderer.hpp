//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIERENDERER_HPP
#define BOOGIERENDERER_HPP
#include <memory>
#include <SDL_render.h>
#include <vector>
#include "../dummydata/DummyTile.hpp"

struct SDL_Renderer;
struct SDL_Window;

//TODO Figure out how this will function
class BoogieRenderer {
public:
    explicit BoogieRenderer(SDL_Window* window);

    void RegisterTiles(std::shared_ptr<DummyTile> tile);

    void Draw();
    void DrawInstance();

private:
    std::vector<std::weak_ptr<DummyTile>> _tiles;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderContext;
};



#endif //BOOGIERENDERER_HPP
