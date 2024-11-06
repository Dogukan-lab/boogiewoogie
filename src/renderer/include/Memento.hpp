//
// Created by hmkam on 06/11/2024.
//

#ifndef MOMENTO_HPP
#define MOMENTO_HPP

#include <string>
#include <ctime>
#include <utility>
#include <vector>


class Artist;
class Tile;

class Memento {
private:
    std::string date_;
    std::vector<Tile *> tiles_;
    std::vector<Artist *> artists_;

public:
    Memento(std::vector<Tile *> tiles, std::vector<Artist *> artists) : tiles_(std::move(tiles)),
                                                                        artists_(std::move(artists)) {
        std::time_t now = std::time(0);
        date_ = std::ctime(&now);
    }

    virtual ~Memento() {};

    /**
    * The rest of the methods are used by the Caretaker to display metadata.
    */

    const std::string &GetDate() const {
        return date_;
    }

    const std::vector<Tile *> &GetTiles() const {
        return tiles_;
    }

    const std::vector<Artist *> &GetAritsts() const {
        return artists_;
    }
};

#endif //MOMENTO_HPP
