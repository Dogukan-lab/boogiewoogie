//
// Created by doguk on 10/21/2024.
//

#ifndef ARTISTMANAGER_HPP
#define ARTISTMANAGER_HPP

#include <Artist.hpp>
#include <memory>
#include <vector>


class ArtistManager {
public:
    ArtistManager();

    explicit ArtistManager(int capacity);

    void AddArtist(Artist&& artist);
    void SetArtists(std::vector<std::unique_ptr<Artist>>&& artists) {
        _artists = std::move(artists);
    }

    //TODO implement this eventually
    void RemoveArtist(const Artist& artist);

    std::vector<std::unique_ptr<Artist>>& GetArtists();

    void UpdateArtists(const float deltaTime) const;

private:
    std::vector<std::unique_ptr<Artist>> _artists{};

};



#endif //ARTISTMANAGER_HPP
