//
// Created by hmkam on 21/10/2024.
//

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

#include <cmath>
#include <iostream>

#include "Pathfinder.hpp"
#include "../Builders/Builder.hpp"

class Dijkstra : Pathfinder {
public:
    bool calculatePath(const std::shared_ptr<Tile> &src, const std::shared_ptr<Tile> &dest,
                       const std::vector<std::shared_ptr<Tile> > &tiles) {
        bool destFound = false;

        std::unordered_map<std::shared_ptr<Tile>, int> dist;
        std::unordered_map<std::shared_ptr<Tile>, bool> shortestPathSet;
        std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > reversePath;

        exploredPath.clear();
        solvedPaths.clear();
        shortestPathWeight = (INT_MAX);
        source = src;
        destination = dest;

        // Initialize distances as INFINITE and shortestPathSet[] as false
        for (std::shared_ptr<Tile> tile: tiles) {
            dist[tile] = INT_MAX;
            shortestPathSet[tile] = false;
            reversePath[tile] = nullptr;
        }
        dist[src] = 0;

        // Find shortest path
        for (size_t count = 0; count < tiles.size(); count++) {
            std::shared_ptr<Tile> tile = minDistance(dist, shortestPathSet);

            if (tile == dest) {
                destFound = true;
                break;
            }
            shortestPathSet[tile] = true;

            // Update dist value of the neighboring tiles of the picked tile
            for (const std::shared_ptr<Tile> &neighbour: tile->neighbours) {
                int weight = neighbour->type->weight;
                // if shorter path
                if (!shortestPathSet[neighbour] && dist[tile] != INT_MAX && dist[tile] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[tile] + weight;
                    reversePath[neighbour] = tile;
                    exploredPath.push_back(tile);
                }
            }
        }

        if (!destFound) { return false; }

        setsolvedPaths(dist, reversePath, dest, solvedPaths);

        // if destenation tile is found but can't be connected to source tile
        if (solvedPaths[0].empty()) { return false; }

        return destFound;
    }

    void printPath() {
        if (source == nullptr || destination == nullptr || solvedPaths.empty()) {
            std::cout << "Empty path" << std::endl;
            return;
        }

        std::cout << "Shortest distance from " << source->type->name << " to " << destination->type->name << " is " <<
                shortestPathWeight
                << "\n";
        std::cout << "Path: " << source->type->name << std::endl;

        for (const auto &it: solvedPaths[0]) {
            std::cout << it->type->name << ": " << it->position.x << ";" << it->position.y << std::endl;
        }

        std::cout << "size viewed: " << exploredPath.size() << "\n";

        std::cout << std::endl;
    }

    std::vector<std::shared_ptr<Tile> > exploredPath;
    std::vector<std::vector<std::shared_ptr<Tile> > > solvedPaths;
    int shortestPathWeight = (INT_MAX);
    std::shared_ptr<Tile> source = nullptr;
    std::shared_ptr<Tile> destination = nullptr;

private:
    // find Tile with the minimum dist value that is not set in shortestPathSet //todo: speed improvement? sorted list?
    std::shared_ptr<Tile> minDistance(const std::unordered_map<std::shared_ptr<Tile>, int> &dist,
                                      std::unordered_map<std::shared_ptr<Tile>, bool> &shortestPathSet) {
        int min = INT_MAX;
        std::shared_ptr<Tile> minTile = nullptr;

        for (const auto &pair: dist) {
            std::shared_ptr<Tile> tile = pair.first;
            int distance = pair.second;

            if (!shortestPathSet[tile] && distance <= min) {
                min = distance;
                minTile = tile;
            }
        }
        return minTile;
    }

    //todo: Punten 5: Omgaan met meerdere goedkoopste paden
    void solvePaths(std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > &reversePath,
                    const std::shared_ptr<Tile> &dest,
                    std::vector<std::vector<std::shared_ptr<Tile> > > &solvedPaths) {
        if (reversePath[dest] == nullptr) {
            return;
        }
        solvePaths(reversePath, reversePath[dest], solvedPaths);
        solvedPaths[0].emplace_back(dest);
    }

    void setsolvedPaths(std::unordered_map<std::shared_ptr<Tile>, int> &dist,
                        std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > &reversePath,
                        const std::shared_ptr<Tile> &dest,
                        std::vector<std::vector<std::shared_ptr<Tile> > > &solvedPaths) {
        solvedPaths.emplace_back();
        solvePaths(reversePath, dest, solvedPaths);

        shortestPathWeight = dist[dest];
    }
};


#endif //DIJKSTRA_HPP
