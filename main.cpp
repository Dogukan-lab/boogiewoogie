#include <iostream>

#include "FileReading/FileReader.hpp"
#include "Builders/AritistBuilder.hpp"
#include "Builders/MapBuilder.hpp"
#include "Parsing/CSVParser.hpp"
#include "Parsing/TXTParser.hpp"
#include "Parsing/XMLParser.hpp"

#define DEBUG 1

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


std::vector<std::shared_ptr<Tile> > getMapTXT() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/grid.txt)", dReader);

    if (DEBUG && printDebug(file_data)) {}

    TXTParser txtParser;
    auto tileVec = txtParser.Pars<Tile>(file_data);

    if (DEBUG && printDebug(tileVec)) {}
    return tileVec;
}

std::vector<std::shared_ptr<Tile> > getMapXML() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/graph.xml)", dReader);

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
    ArtistsObject artists = getArtists();

    auto tileVec0 = getMapTXT();
    Map map0 = builMap(tileVec0);

    auto tileVec1 = getMapXML();
    Map map1 = builMap(tileVec1);


    return 0;
}
