//
// Created by hmkam on 06/11/2024.
//

#ifndef MOMENTO_HPP
#define MOMENTO_HPP

#include <string>
#include <ctime>
#include <utility>
#include <vector>

#include "Tile.hpp"
#include "Artist.hpp"

struct tileCopy {
    const glm::vec2 pos;
    const Shape shape;
};

struct artistCopy {
    const Shape shape;
    const SDL_Colour colour;
    const glm::vec2 startPos;
    const glm::vec2 direction;
};

class Memento {
private:
    std::string date_;
    std::vector<Tile> tiles_{};
    std::vector<artistCopy> artists_{};

public:
    Memento(std::vector<Tile> tiles, std::vector<artistCopy> artists) : tiles_(std::move(tiles)),
                                                                        artists_(std::move(artists)) {
        std::time_t now = std::time(0);
        date_ = std::ctime(&now);
    }

    virtual ~Memento() = default;

    /**
    * The rest of the methods are used by the Caretaker to display metadata.
    */

    const std::string &GetDate() const {
        return date_;
    }

    const std::vector<Tile> &GetTiles() const {
        return tiles_;
    }

    const std::vector<artistCopy> &GetAritsts() const {
        return artists_;
    }
};

#endif //MOMENTO_HPP
