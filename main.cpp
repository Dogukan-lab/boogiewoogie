#include <iostream>

#include "FileReading/FileReader.hpp"
#include "Builders/AritistBuilder.hpp"
#include "Builders/MapBuilder.hpp"
#include "FileReading/DiskReader.hpp"
#include "FileReading/WebReader.hpp"
#include "Parsing/CSVParser.hpp"
#include "Parsing/TXTParser.hpp"
#include "Parsing/XMLParser.hpp"
#include <string>
#include <regex>

#include "Algorithms/Dijkstra.hpp"

#define DEBUG 0

bool printDebug(const std::vector<std::string> &file_data) {
    for (const auto &celData: file_data) {
        if (celData == "\n")
            std::cout << "/n" << std::endl;
        else
            std::cout << celData << ",";
    }
    std::cout << std::endl;

    return DEBUG;
}

bool printDebug(const std::vector<std::shared_ptr<Tile> > &tileVec) {
    for (const auto &tile: tileVec) {
        std::cout << "Tile Type: " << tile->type->name
                << ", Position: (" << tile->position.x << ", " << tile->position.y << ")"
                << ", Weight: (" << tile->type->weight << ")"
                << ", Neighbours: " << tile->neighbours.size() << std::endl;

        for (const auto &neighbour: tile->neighbours) {
            std::cout << "  Neighbour Position: (" << neighbour->position.x << ", " << neighbour->position.y << ")" <<
                    std::endl;
        }
    }
    std::cout << std::endl;

    return DEBUG;
}

bool printDebug(const Map &map) {
    printDebug(map.tiles);

    return DEBUG;
}

bool printDebug(const std::vector<Artist> &artistsCSV) {
    std::cout << std::endl;
    for (auto artist: artistsCSV) {
        std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    }

    return DEBUG;
}

bool printDebug(const ArtistsObject &artists) {
    std::cout << std::endl;
    for (auto artist: artists.artists) {
        std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    }

    return DEBUG;
}

struct Data {
    int data;
};

std::vector<std::string> readFromFile(const std::string &path, FileReader &reader) {
    return reader.openFile(path);
}

ArtistsObject getArtists() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/artists.csv)", dReader);

    if (DEBUG && printDebug(file_data)) {}

    CSVParser csvParser;
    std::vector<Artist> artistsCSV = csvParser.Pars<Artist>(file_data);

    if (DEBUG && printDebug(artistsCSV)) {}
    auto artists = ArtistBuilder().replaceArtists(artistsCSV).build();

    if (DEBUG && printDebug(artists)) {}
    return artists;
}

bool isLocalFile(const std::string &location) {
    // Regular expression to match common URL protocols (e.g., http, https, ftp)
    std::regex urlPattern(R"((https?|ftp)://)");

    // Check if the location matches the URL pattern
    if (std::regex_search(location, urlPattern)) {
        return false; // It's a URL, not a local file
    }

    return true; // If no URL pattern is detected, assume it's a local file
}

std::vector<std::string> readFile(const std::string &location) {
    std::vector<std::string> file_data;

    if (isLocalFile(location)) {
        DiskReader dReader{};
        file_data = readFromFile(location, dReader);
    } else {
        WebReader wReader{};
        file_data = readFromFile(location, wReader);
    }

    return file_data;
}


std::vector<std::shared_ptr<Tile> > getMapTXT(const std::string &location) {
    std::vector<std::string> file_data = readFile(location);

    if (DEBUG && printDebug(file_data)) {}

    TXTParser txtParser;
    auto tileVec = txtParser.Pars<Tile>(file_data);

    if (DEBUG && printDebug(tileVec)) {}
    return tileVec;
}

std::vector<std::shared_ptr<Tile> > getMapXML(const std::string &location) {
    std::vector<std::string> file_data = readFile(location);

    if (DEBUG && printDebug(file_data)) {}

    XMLParser xmlParser;
    auto tileVec = xmlParser.Pars<Tile>(file_data);

    if (DEBUG && printDebug(tileVec)) {}
    return tileVec;
}

Map builMap(const std::vector<std::shared_ptr<Tile> > &tileVec) {
    Map map = MapBuilder().replaceTiles(tileVec).build();

    if (DEBUG && printDebug(map)) {}
    return map;
}


int main() {
    std::string gridUrl = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media";
    std::string graphUrl = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/graph.xml?alt=media";
    std::string gridDisk = "D:/GitHub/boogiewoogie/Files/grid.txt";
    std::string graphDisk = "D:/GitHub/boogiewoogie/Files/graph.xml";

    ArtistsObject artists = getArtists();

    Map map0 = builMap(getMapTXT(gridDisk));
    Map map1 = builMap(getMapXML(graphDisk));

    std::shared_ptr<Tile> src = nullptr;
    std::shared_ptr<Tile> dest = nullptr;

    src = map0.tiles.front();
    dest = map0.tiles.at(50);
    if (!Dijkstra().IsPath(src, dest, map0.tiles)) { std::cout << "No path found 1" << std::endl; }
    src = map0.tiles.front();
    dest = map0.tiles.at(100);
    if (!Dijkstra().IsPath(src, dest, map0.tiles)) { std::cout << "No path found 2" << std::endl; }

    src = map1.tiles.front();
    dest = map1.tiles.at(150);
    if (!Dijkstra().IsPath(src, dest, map1.tiles)) { std::cout << "No path found 3" << std::endl; }
    src = map1.tiles.front();
    dest = map1.tiles.back();
    if (!Dijkstra().IsPath(src, dest, map1.tiles)) { std::cout << "No path found 4" << std::endl; }

    if (!Dijkstra().IsPath(src, dest, map0.tiles)) { std::cout << "No path found 5" << std::endl; } //todo: not consistent when run sometimes IsPath() returns true some false.

    return 0;
}
