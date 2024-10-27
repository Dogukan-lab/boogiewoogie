//
// Created by hmkam on 21/10/2024.
//

#include "Dijkstra.hpp"

bool Dijkstra::calculatePath(const Tile *src, const Tile *dest, const std::vector<const Tile *> &tiles) {
    bool destFound = false;

    std::unordered_map<const Tile *, int> dist;
    std::unordered_map<const Tile *, bool> shortestPathSet;
    std::unordered_map<const Tile *, const Tile *> reversePath;

    exploredPath.clear();
    solvedPaths.clear();
    shortestPathWeight = (INT_MAX);
    source = src;
    destination = dest;

    // Initialize distances as INFINITE and shortestPathSet[] as false
    for (const Tile *tile: tiles) {
        dist[tile] = INT_MAX;
        shortestPathSet[tile] = false;
    }
    dist[src] = 0;

    // Find shortest path
    for (size_t count = 0; count < tiles.size(); count++) {
        const Tile *tile = minDistance(dist, shortestPathSet);

        if (tile->position == dest->position) {
            destFound = true;
            break;
        }
        shortestPathSet[tile] = true;

        // Update dist value of the neighboring tiles of the picked tile
        for (Tile *neighbour: tile->neighbours) {
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

    // if destination tile is found but can't be connected to source tile
    if (solvedPaths[0].empty()) { return false; }

    return destFound;
}


void Dijkstra::printPath() const {
    if (source == nullptr || destination == nullptr || solvedPaths.empty()) {
        std::cout << "Empty path" << std::endl;
        return;
    }

    std::cout << "Shortest distance from " << source->type->tag << " to " << destination->type->tag << " is " <<
            shortestPathWeight
            << "\n";
    std::cout << "Path: " << source->type->tag << std::endl;

    for (const auto &it: solvedPaths[0]) {
        std::cout << it->type->tag << ": " << it->position.x << ";" << it->position.y << std::endl;
    }

    std::cout << "size viewed: " << exploredPath.size() << "\n";
    std::cout << std::endl;
}

const Tile *Dijkstra::minDistance(const std::unordered_map<const Tile *, int> &dist,
                                  std::unordered_map<const Tile *, bool> &shortestPathSet) const {
    int min = INT_MAX;
    const Tile *minTile = nullptr;

    for (const auto [tile, distance]: dist) {
        if (!shortestPathSet[tile] && distance <= min) {
            min = distance;
            minTile = tile;
        }
    }
    return minTile;
}

void Dijkstra::solvePaths(std::unordered_map<const Tile *, const Tile *> &reversePath,
                          const Tile *dest,
                          std::vector<std::vector<const Tile *> > &solvedPaths) const {
    if (reversePath[dest] == nullptr) {
        return;
    }
    solvePaths(reversePath, reversePath[dest], solvedPaths);
    solvedPaths[0].emplace_back(dest);
}

void Dijkstra::setsolvedPaths(std::unordered_map<const Tile *, int> &dist,
                              std::unordered_map<const Tile *, const Tile *> &reversePath,
                              const Tile *dest,
                              std::vector<std::vector<const Tile *> > &solvedPaths) const {
    solvedPaths.emplace_back();
    solvePaths(reversePath, dest, solvedPaths);

    shortestPathWeight = dist[dest];
}
