//
// Created by hmkam on 06/11/2024.
//

#ifndef MOMENTO_HPP
#define MOMENTO_HPP

#include <string>
#include <ctime>
#include <SDL_pixels.h>
#include <Shape.hpp>
#include <utility>
#include <vec2.hpp>
#include <vector>


struct tileCopy {
    glm::vec2 pos;
    Shape shape;
    SDL_Colour colour;
};

struct artistCopy {
    Shape shape;
    SDL_Colour colour;
    glm::vec2 startPos;
    glm::vec2 direction;
    glm::ivec2 lastTile{};
};

class Memento {
private:
    std::string date_;
    std::vector<tileCopy> tiles_{};
    std::vector<artistCopy> artists_{};

public:
    Memento(std::vector<artistCopy> artists,std::vector<tileCopy> tiles) : artists_(std::move(artists)) , tiles_(std::move(tiles)){
        // std::time_t now = std::time(0);
        // date_ = std::ctime(&now);
    }

    Memento();

    virtual ~Memento() = default;

    /**
    * The rest of the methods are used by the Caretaker to display metadata.
    */

    const std::string &GetDate() const {
        return date_;
    }

    std::vector<tileCopy> &GetTiles() {
        return tiles_;
    }

    std::vector<artistCopy> &GetAritsts() {
        return artists_;
    }
};

#endif //MOMENTO_HPP
