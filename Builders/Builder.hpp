//
// Created by hmkam on 09/10/2024.
//

#ifndef BUILDER_HPP
#define BUILDER_HPP


#include <memory>
#include <string>
#include <vector>

template<typename T>
struct Vector2D {
    T x;
    T y;

    bool operator==(const Vector2D &other) const {
        return x == other.x && y == other.y;
    }
};

template<typename T>
struct Shape {
    T width;
    T height;
};


struct TileType {
    std::string name;
    int rgb[3];
    int weight;
};

struct Tile {
    Vector2D<int> position;
    std::vector<std::shared_ptr<Tile> > neighbours;
    std::shared_ptr<TileType> type; //todo: cant be deleted if no refrences, becouse of later use
    Shape<int> shape = {1, 1};
};

struct Map {
    std::vector<std::shared_ptr<Tile> > tiles;
};

struct Artist {
    Vector2D<double> position;
    Vector2D<double> direction;
    Shape<double> shape = {0.1, 0.1};
};

struct ArtistsObject {
    std::vector<Artist> artists;
};

template<typename T>
class Builder {
public:
    virtual ~Builder() = default;

    virtual T &build() = 0;
};

#endif //BUILDER_HPP
