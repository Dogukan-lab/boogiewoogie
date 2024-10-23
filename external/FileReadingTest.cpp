//
// Created by doguk on 10/23/2024.
//

#include "FileReadingTest.hpp"

#include <regex>

#include "builders/AritistBuilder.hpp"
#include "builders/MapBuilder.hpp"
#include "filereading/DiskReader.hpp"
#include "filereading/WebReader.hpp"
#include "parsing/CSVParser.hpp"
#include "parsing/TXTParser.hpp"
#define DEBUG 1

ArtistsObject FileReadingTest::getArtists() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/artists.csv)", dReader);

    if (DEBUG && printDebug(file_data)) {
    }

    CSVParser csvParser;
    std::vector<Artist> artistsCSV = csvParser.Pars<Artist>(file_data);

    if (DEBUG && printDebug(artistsCSV)) {
    }
    auto artists = ArtistBuilder().replaceArtists(artistsCSV).build();

    if (DEBUG && printDebug(artists)) {
    }
    return artists;
}

void FileReadingTest::runFileTests() {
    std::string gridUrl = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media";
    std::string graphUrl = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/graph.xml?alt=media";
    std::string gridDisk = "D:/GitHub/boogiewoogie/Files/grid.txt";
    std::string graphDisk = "D:/GitHub/boogiewoogie/Files/graph.xml";

    ArtistsObject artists = getArtists();

    auto tileVec0 = getMapTXT(gridDisk);
    Map map0 = builMap(tileVec0);

    auto tileVec1 = getMapXML(graphDisk);
    Map map1 = builMap(tileVec1);
}

bool FileReadingTest::printDebug(const std::vector<std::string> &file_data) {
    for (const auto &celData: file_data) {
        if (celData == "\n")
            std::cout << "/n" << std::endl;
        else
            std::cout << celData << ",";
    }
    std::cout << std::endl;

    return DEBUG;
}

bool FileReadingTest::printDebug(const std::vector<std::shared_ptr<Tile> > &tileVec) {
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

bool FileReadingTest::printDebug(const Map &map) {
    printDebug(map.tiles);

    return DEBUG;
}

bool FileReadingTest::printDebug(const std::vector<Artist> &artistsCSV) {
    std::cout << std::endl;
    for (auto artist: artistsCSV) {
        std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    }

    return DEBUG;
}

bool FileReadingTest::printDebug(const ArtistsObject &artists) {
    std::cout << std::endl;
    for (auto artist: artists.artists) {
        std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    }

    return DEBUG;
}

std::vector<std::string> FileReadingTest::readFromFile(const std::string &path, FileReader &reader) {
    return reader.openFile(path);
}

bool FileReadingTest::isLocalFile(const std::string &location) {
    // Regular expression to match common URL protocols (e.g., http, https, ftp)
    std::regex urlPattern(R"((https?|ftp)://)");

    // Check if the location matches the URL pattern
    if (std::regex_search(location, urlPattern)) {
        return false; // It's a URL, not a local file
    }

    return true; // If no URL pattern is detected, assume it's a local file
}

std::vector<std::string> FileReadingTest::readFile(const std::string &location) {
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

std::vector<std::shared_ptr<Tile> > FileReadingTest::getMapTXT(const std::string &location) {
    std::vector<std::string> file_data = readFile(location);

    if (DEBUG && printDebug(file_data)) {
    }

    TXTParser txtParser;
    auto tileVec = txtParser.Pars<Tile>(file_data);

    if (DEBUG && printDebug(tileVec)) {
    }
    return tileVec;
}

Map FileReadingTest::builMap(const std::vector<std::shared_ptr<Tile> > &tileVec) {
    Map map = MapBuilder().replaceTiles(tileVec).build();

    //What is this check even for...
    if (DEBUG && printDebug(map)) {
    }
    return map;
}
