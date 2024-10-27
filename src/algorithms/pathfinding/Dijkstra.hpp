//
// Created by hmkam on 21/10/2024.
//

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <algorithm>
#include <unordered_map>
// Number of vertices in the graph
#define V 9

#include <cmath>
#include <iostream>
#include <Tile.hpp>

#include "Pathfinder.hpp"

class Dijkstra : Pathfinder {
public:
    bool calculatePath(const std::shared_ptr<Tile> &src, const std::shared_ptr<Tile> &dest,
                       const std::vector<std::shared_ptr<Tile> > &tiles);

    void printPath();

    std::vector<std::shared_ptr<Tile>> exploredPath;
    std::vector<std::vector<std::shared_ptr<Tile>>> solvedPaths;
    static int shortestPathWeight;
    std::shared_ptr<Tile> source = nullptr;
    std::shared_ptr<Tile> destination = nullptr;

private:
    // find Tile with the minimum dist value that is not set in shortestPathSet //todo: speed improvement? sorted list?
    static std::shared_ptr<Tile> minDistance(const std::unordered_map<std::shared_ptr<Tile>, int> &dist,
                                      std::unordered_map<std::shared_ptr<Tile>, bool> &shortestPathSet);

    //todo: Punten 5: Omgaan met meerdere goedkoopste paden
    static void solvePaths(std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > &reversePath,
                    const std::shared_ptr<Tile> &dest,
                    std::vector<std::vector<std::shared_ptr<Tile> > > &solvedPaths);

    static void setsolvedPaths(std::unordered_map<std::shared_ptr<Tile>, int> &dist,
                        std::unordered_map<std::shared_ptr<Tile>, std::shared_ptr<Tile> > &reversePath,
                        const std::shared_ptr<Tile> &dest,
                        std::vector<std::vector<std::shared_ptr<Tile> > > &solvedPaths);
};


#endif //DIJKSTRA_HPP
