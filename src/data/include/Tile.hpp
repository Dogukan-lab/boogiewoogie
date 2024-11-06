//
// Created by doguk on 10/9/2024.
//

#ifndef DUMMYTILE_HPP
#define DUMMYTILE_HPP
#include <BlueType.hpp>
#include <GreyType.hpp>
#include <memory>
#include <RedType.hpp>
#include <vector>
#include <WhiteType.hpp>
#include <YellowType.hpp>

#include "Shape.hpp"

class Tile {
public:
    Tile(const glm::vec2 pos, const Shape shape): shape(shape), position(pos),
    type(nullptr) {
    }

    ~Tile() {
        neighbours.clear();
    }

    // Copy to store momento //todo: SetType
    Tile(const Tile& other) : shape(other.shape), position(other.position) {
        // Copy the vector of neighbours, but shallow copy the pointers
        for (Tile* neighbour : other.neighbours) {
            neighbours.push_back(neighbour);
        }

        // type = std::unique_ptr<TileType>();
        // type = std::unique_ptr<>
        //
        // type = std::make_unique<TileType>(*other.type);

        auto tag = other.type->tag;

        switch (tag) {
            case '_':
                SetType<WhiteType>();
            break;
            case 'Y':
                SetType<YellowType>();
            break;
            case 'R':
                SetType<RedType>();
            break;
            case 'G':
                SetType<GreyType>();
            break;
            case 'B':
                SetType<BlueType>();
            break;
            default: break;
        }
    }

    // Copy to store momento //todo: SetType
    Tile& operator= (const Tile & other){
        if (this != &other) {
            shape = other.shape;
            position = other.position;

            for (Tile* neighbour : other.neighbours) {
                neighbours.push_back(neighbour);
            }

            auto tag = other.type->tag;

            switch (tag) {
                case '_':
                    type = std::make_unique<WhiteType>();
                break;
                case 'Y':
                    type = std::make_unique<YellowType>();
                break;
                case 'R':
                    type = std::make_unique<RedType>();
                break;
                case 'G':
                    type = std::make_unique<GreyType>();
                break;
                case 'B':
                    type = std::make_unique<BlueType>();
                break;
                default: break;
            }

        }
        return *this;
    }

    template<typename T>
    void SetType() {
        type = std::make_unique<T>();
    }

    inline void handleTileInteraction(Artist* currentArtist) {
        type->handleInteract(this, currentArtist);
    }

    Shape shape;
    glm::vec2 position;
    std::unique_ptr<TileType> type;
    std::vector<Tile*> neighbours{};
};
#endif //DUMMYTILE_HPP