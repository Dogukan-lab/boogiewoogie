//
// Created by doguk on 10/21/2024.
//

#ifndef ARTISTMANAGER_HPP
#define ARTISTMANAGER_HPP

#include <Artist.hpp>
#include <BoogieRenderer.hpp>

#include "Tile.hpp"
#include "Memento.hpp"
#include <memory>
#include <vector>

class ArtistManager {
public:
    explicit ArtistManager(BoogieRenderer& renderer);

    ArtistManager(int capacity, BoogieRenderer& renderer);

    Artist* AddArtist(Artist&& artist);
    void SetArtists(std::vector<std::unique_ptr<Artist>>&& artists);

    //TODO implement this eventually
    void RemoveArtist(Artist& artist) const;

    std::vector<std::unique_ptr<Artist>>& GetArtists();

    void UpdateArtists(const float deltaTime, const std::vector<std::vector<std::unique_ptr<Tile>>>& grid);

    void Restore(Memento *memento) ;

    void ClearArtists();

    std::vector<ArtistCopy> Save();

private:
    std::vector<std::unique_ptr<Artist>> _artists{};
    BoogieRenderer& _renderer;

};

#endif //ARTISTMANAGER_HPP