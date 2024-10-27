//
// Created by hmkam on 21/10/2024.
//

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <unordered_map>
#include <Tile.hpp>

#include "Pathfinder.hpp"

class Dijkstra : Pathfinder {
public:
    bool calculatePath(Tile *src, Tile *dest, std::vector<Tile *> tiles);

    void printPath();

    std::vector<Tile *> exploredPath;
    std::vector<std::vector<Tile *> > solvedPaths;
    static int shortestPathWeight;
    const Tile *source;
    const Tile *destination;

private:
    // find Tile with the minimum dist value that is not set in shortestPathSet //todo: speed improvement? sorted list?
    static Tile *minDistance(const std::unordered_map<Tile *, int> &dist,
                             std::unordered_map<Tile *, bool> &shortestPathSet);

    //todo: Punten 5: Omgaan met meerdere goedkoopste paden
    static void solvePaths(std::unordered_map<Tile *, Tile *> &reversePath,
                           Tile *dest,
                           std::vector<std::vector<Tile *> > &solvedPaths);

    static void setsolvedPaths(std::unordered_map<Tile *, int> &dist,
                               std::unordered_map<Tile *, Tile *> &reversePath,
                               Tile *dest,
                               std::vector<std::vector<Tile *> > &solvedPaths);
};


#endif //DIJKSTRA_HPP
