//
// Created by doguk on 10/21/2024.
//

#ifndef ARTISTMANAGER_HPP
#define ARTISTMANAGER_HPP
#include <memory>
#include <vector>

#include "dummydata/DummyArtist.hpp"

class ArtistManager {
public:
    ArtistManager();

    explicit ArtistManager(int capacity);

    void AddArtist(Artist&& artist);

    //TODO implement this eventually
    void RemoveAritst(const Artist& artist);

    std::vector<std::unique_ptr<Artist>>& GetArtists();

    void UpdateArtists();

private:
    std::vector<std::unique_ptr<Artist>> _artists;

};



#endif //ARTISTMANAGER_HPP
