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
    bool calculatePath();

    // Helper function to calculate Euclidean distance between two tiles
    int calculateDistance(std::shared_ptr<Tile> a, std::shared_ptr<Tile> b) {
        return std::sqrt(std::pow(a->position.x - b->position.x, 2) + std::pow(a->position.y - b->position.y, 2));
    }

    // Function to find the Tile with the minimum distance value
    std::shared_ptr<Tile> minDistance(std::unordered_map<std::shared_ptr<Tile>, int> &dist,
                                      std::unordered_map<std::shared_ptr<Tile>, bool> &sptSet) {
        int min = INT_MAX;
        std::shared_ptr<Tile> minTile = nullptr;

        for (const auto &pair: dist) {
            std::shared_ptr<Tile> tile = pair.first;
            int distance = pair.second;

            if (!sptSet[tile] && distance <= min) {
                min = distance;
                minTile = tile;
            }
        }
        return minTile;
    }

    // Function to print the shortest path from source to destination
    void printPath(std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > &reverceDijkstraPath,
                   std::shared_ptr<Tile> dest) {
        if (reverceDijkstraPath[dest] == nullptr) {
            return;
        }
        printPath(reverceDijkstraPath, reverceDijkstraPath[dest]);
        std::cout << dest->type->name << ": " << dest->position.x << ";" << dest->position.y << std::endl;
    }

    void printSolution(std::unordered_map<std::shared_ptr<Tile>, int> &dist,
                       std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > &reverceDijkstraPath,
                       std::shared_ptr<Tile> src,
                       std::shared_ptr<Tile> dest) {
        std::cout << "Shortest distance from " << src->type->name << " to " << dest->type->name << " is " << dist[dest]
                << "\n";
        std::cout << "Path: " << src->type->name << std::endl;
        printPath(reverceDijkstraPath, dest);
        std::cout << "\n";
    }

    bool IsPath(std::shared_ptr<Tile> src, std::shared_ptr<Tile> dest,
                const std::vector<std::shared_ptr<Tile> > &tiles) {
        bool destFound = false;

        std::unordered_map<std::shared_ptr<Tile>, int> dist;
        std::unordered_map<std::shared_ptr<Tile>, bool> sptSet;
        std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > reverceDijkstraPath;

        std::vector<std::shared_ptr<Tile> > viewedPath;
        std::vector<std::vector<std::shared_ptr<Tile> > > solvedPaths;


        // Initialize distances as INFINITE and sptSet[] as false
        for (std::shared_ptr<Tile> tile: tiles) {
            dist[tile] = INT_MAX;
            sptSet[tile] = false;
            reverceDijkstraPath[tile] = nullptr;
        }

        dist[src] = 0;

        // Find shortest path from source to destination
        for (size_t count = 0; count < tiles.size() - 1; count++) {
            std::shared_ptr<Tile> u = minDistance(dist, sptSet);

            if (u == dest) {
                destFound = true;
                break;
            }

            sptSet[u] = true;

            // Update dist value of the neighboring tiles of the picked tile
            for (const std::shared_ptr<Tile> &v: u->neighbours) {
                int weight = calculateDistance(u, v);
                if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    reverceDijkstraPath[v] = u; // Record the reverceDijkstraPath
                    viewedPath.push_back(u);
                }
            }
        }

        // Print the shortest path from source to destination
        printSolution(dist, reverceDijkstraPath, src, dest);

        // setsolvedPaths(dist, viewedPath);
        std::cout << "size viewed: " << viewedPath.size() << "\n";

        return destFound;
    }

private:
    void dijkstra();

    bool findPath(int source, int destination);
};


#endif //DIJKSTRA_HPP
