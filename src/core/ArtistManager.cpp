//
// Created by doguk on 10/21/2024.
//

#include "ArtistManager.hpp"
#include "Artist.hpp"

#define GLM_ENABLE_EXPERIMENTAL

#include <algorithm>
#include <BoogieRenderer.hpp>
#include <glm.hpp>
#include <iostream>
#include <TileManager.hpp>
#include <gtx/string_cast.hpp>

// ArtistManager::ArtistManager(const BoogieRenderer& renderer): ArtistManager(10, renderer){
// }

// ArtistManager::ArtistManager(int capacity, const BoogieRenderer& renderer) {
//     _artists.resize(capacity);
//     _renderer = renderer;
// }

ArtistManager::ArtistManager(BoogieRenderer &renderer): ArtistManager(10, renderer) {
}

ArtistManager::ArtistManager(int capacity, BoogieRenderer &renderer): _renderer(renderer) {
    _artists.resize(capacity);
}

Artist* ArtistManager::AddArtist(Artist &&artist) {
    if(_artists.size() >= 125)
        return nullptr;

    const auto &art = _artists.emplace_back(std::make_unique<Artist>(artist));
    _renderer.RegisterArtist(*art);
    return art.get();
}

void ArtistManager::RemoveArtist(Artist &artist) const {
    artist.shouldBeDeleted = true;
    _renderer.DeleteArtist(artist);
}

std::vector<std::unique_ptr<Artist> > &ArtistManager::GetArtists() {
    return _artists;
}

//Update movement of artists
void ArtistManager::UpdateArtists(const float deltaTime,
                                  const std::vector<std::vector<std::unique_ptr<Tile> > > &grid) {
    for (const auto &artist: _artists) {
        if (!artist)
            continue;
        auto &position = artist->GetPosition();
        auto &lastTile = artist->GetLastTile();
        auto &direction = artist->GetDirection();
        const auto &dimension = artist->GetShape().GetDimension();
        const auto size = dimension / 2.f;
        const auto offset = dimension / 4.f;
        position += direction * deltaTime;

        //Bounds check
        if (position.x * dimension.x <= -offset.x) direction.x = abs(direction.x);
        if (position.x * dimension.x >= 600.f - size.x - offset.x) direction.x = abs(direction.x) * -1;
        if (position.y * dimension.y <= -offset.y) direction.y = abs(direction.y);
        if (position.y * dimension.y >= 600.f - size.y - offset.y) direction.y = abs(direction.y) * -1;

        glm::ivec2 tilePos = glm::ivec2(glm::round(position));


        if (tilePos.y < grid.size() && tilePos.x < grid[0].size() &&
            tilePos.y >= 0 && tilePos.x >= 0) {
            if (tilePos.x != lastTile.x || tilePos.y != lastTile.y) {
                lastTile = tilePos;
                auto &tile = grid[tilePos.y][tilePos.x];
                tile->handleTileInteraction(artist.get());
            }
        }
    }

    //Delete artist, if any are existing
    const auto it = std::remove_if(_artists.begin(), _artists.end(), [](const std::unique_ptr<Artist> &
                               pArtist) {
                                       return pArtist->shouldBeDeleted;
                                   });
    if (it != _artists.end()) {
        _artists.erase(it, _artists.end());
    }
}

std::vector<artistCopy> ArtistManager::Save() {
    std::vector<artistCopy> artistsCopy;

    for (auto& artist: _artists) {
        artistsCopy.push_back(artistCopy{artist->GetShape(),artist->GetColour(),artist->GetPosition(),artist->GetDirection(), artist->GetLastTile()});
    }

    return artistsCopy;
}
