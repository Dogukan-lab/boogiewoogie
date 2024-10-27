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
    bool calculatePath(const Tile *src, const Tile *dest, const std::vector<const Tile> &tiles);

    void printPath() const;

    std::vector<const Tile *> exploredPath;
    std::vector<std::vector<const Tile *> > solvedPaths;
    static int shortestPathWeight;
    const Tile *source;
    const Tile *destination;

private:
    // find Tile with the minimum dist value that is not set in shortestPathSet //todo: speed improvement? sorted list?
    const Tile *minDistance(const std::unordered_map<const Tile *, int> &dist,
                            std::unordered_map<const Tile *, bool> &shortestPathSet) const;

    //todo: Punten 5: Omgaan met meerdere goedkoopste paden
    void solvePaths(std::unordered_map<const Tile *, const Tile *> &reversePath,
                    const Tile *dest,
                    std::vector<std::vector<const Tile *> > &solvedPaths) const;

    void setsolvedPaths(std::unordered_map<const Tile *, int> &dist,
                        std::unordered_map<const Tile *, const Tile *> &reversePath,
                        const Tile *dest,
                        std::vector<std::vector<const Tile *> > &solvedPaths) const;
};


#endif //DIJKSTRA_HPP
