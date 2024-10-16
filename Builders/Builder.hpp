//
// Created by hmkam on 09/10/2024.
//

#ifndef BUILDER_HPP
#define BUILDER_HPP


#include <string>
#include <vector>

struct Vector2D {
    int x;
    int y;

    bool operator==(const Vector2D &other) const {
        return x == other.x && y == other.y;
    }
};

struct Shape {
    int width;
    int height;
};

enum class Tag {
    Y, // Yellow
    B, // Blue
    R, // Red
    G // Green
};

struct TileType {
    Tag tag;
    std::string name;
    int rgb[3];
    int weight;
};

struct Tile {
    Vector2D position;
    std::vector<Tile> neighbours;
    TileType *type;
    Shape shape;
};

struct Map {
    std::vector<Tile> tiles;
};

struct Artist {
    Vector2D position;
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
