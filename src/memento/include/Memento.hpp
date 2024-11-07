//
// Created by hmkam on 06/11/2024.
//

#ifndef MOMENTO_HPP
#define MOMENTO_HPP
#include <string>
#include <ctime>
#include "SDL_pixels.h"
#include "Shape.hpp"
#include <utility>
#include "vec2.hpp"
#include <vector>

struct TileCopy {
    glm::vec2 pos;
    Shape shape;
    SDL_Colour colour;
};

struct ArtistCopy {
    Shape shape;
    SDL_Colour colour;
    glm::vec2 position;
    glm::vec2 direction;
    glm::ivec2 lastTile{};

};

class Memento {
private:
    std::string date_;
    std::vector<TileCopy> tiles_;
    std::vector<ArtistCopy> artists_;

public:
    Memento(std::vector<ArtistCopy> artists, std::vector<TileCopy> tiles) : artists_(std::move(artists)) , tiles_(std::move(tiles)){
    }

    Memento() {
        tiles_ = {};
        artists_ = {};
        date_ = {};
    }

    virtual ~Memento() = default;

    /**
    * The rest of the methods are used by the Caretaker to display metadata.
    */

    [[nodiscard]] const std::string &GetDate() const {
        return date_;
    }

    std::vector<TileCopy> &GetTiles() {
        return tiles_;
    }

    std::vector<ArtistCopy> &GetArtists() {
        return artists_;
    }
};

#endif //MOMENTO_HPP