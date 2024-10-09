//
// Created by doguk on 10/9/2024.
//

#include "BoogieRenderer.hpp"

void BoogieRenderer::RegisterTiles(const DummyTile &tile) {
    _tiles.emplace_back(std::make_shared<DummyTile>(tile));
}

void BoogieRenderer::Draw() {

}
