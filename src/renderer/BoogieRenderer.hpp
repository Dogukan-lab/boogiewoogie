//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIERENDERER_HPP
#define BOOGIERENDERER_HPP
#include <memory>
#include <vector>
#include "../dummydata/DummyTile.hpp"

//TODO Figure out how this
class BoogieRenderer {
public:
    BoogieRenderer();

    void RegisterTiles(const DummyTile& tile);

    void Draw();
    void DrawInstance();

private:
    std::vector<std::shared_ptr<DummyTile>> _tiles;
};



#endif //BOOGIERENDERER_HPP
