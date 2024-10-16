#include <iostream>

#include "FileReading/FileReader.hpp"
#include "Builders/AritistBuilder.hpp"
#include "Builders/MapBuilder.hpp"
#include "Parsing/CSVParser.hpp"
#include "Parsing/TXTParser.hpp"
#include "Parsing/XMLParser.hpp"

struct Data {
    int data;
};

//todo: check file reader is ok
std::vector<std::string> readFromFile(const std::string &path, FileReader &reader) {
    return reader.openFile(path);
}

ArtistsObject getArtists() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/artists.csv)", dReader);

    // for (auto csvCel: file_data) {
    //     if (csvCel == "\n")
    //         std::cout << "/n" << std::endl;
    //     else
    //         std::cout << csvCel << ",";
    // }

    CSVParser csvParser;
    std::vector<Artist> artistsCSV = csvParser.Pars<Artist>(file_data);

    // std::cout << std::endl;
    // for (auto artist: artistsCSV) {
    //     std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    // }

    auto artists = ArtistBuilder().replaceArtists(artistsCSV).build();

    // std::cout << std::endl;
    // for (auto artist: artists.artists) {
    //     std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    // }

    return artists;
}

std::vector<std::shared_ptr<Tile> > getMapTXT() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/grid.txt)", dReader);

    for (auto celData: file_data) {
        if (celData == "\n")
            std::cout << "/n" << std::endl;
        else
            std::cout << celData << ",";
    }

    TXTParser txtParser;
    // TXT //todo: implement
    auto tileVec = txtParser.Pars<std::shared_ptr<Tile> >(file_data);

    // std::cout << std::endl;
    // for (auto nodes: mapTXT) {
    //     std::cout << nodes.position.x << ", " << nodes.position.y << std::endl;
    // }

    return tileVec;
}

std::vector<std::shared_ptr<Tile> > getMapXML() {
    DiskReader dReader{};
    WebReader wReader{};
    std::vector<std::string> file_data = readFromFile(R"(D:/GitHub/boogiewoogie/Files/graph.xml)", dReader);

    // for (auto celData: file_data) {
    //     if (celData == "\n")
    //         std::cout << "/n" << std::endl;
    //     else
    //         std::cout << celData << ",";
    // }
    // std::cout << std::endl;

    XMLParser xmlParser;
    // TXT //todo: implement
    auto tileVec = xmlParser.Pars<std::shared_ptr<Tile> >(file_data);

    // for (const auto &tile: tileVec) {
    //     std::cout << "Tile Type: " << tile->type->name
    //             << ", Position: (" << tile->position.x << ", " << tile->position.y << ")"
    //             << ", Neighbours: " << tile->neighbours.size() << std::endl;
    //
    //     for (const auto &neighbour: tile->neighbours) {
    //         std::cout << "  Neighbour Position: (" << neighbour->position.x << ", " << neighbour->position.y << ")" <<
    //                 std::endl;
    //     }
    // }
    // std::cout << std::endl;
    return tileVec;
}

Map builMap(std::vector<std::shared_ptr<Tile> > tileVec) {
    //todo: catch Neighbour tile not found

    Map map = MapBuilder().replaceTiles(tileVec).build();

    for (const auto &tile: map.tiles) {
        std::cout << "Tile Type: " << tile->type
                << ", Position: (" << tile->position.x << ", " << tile->position.y << ")"
                << ", Neighbours: " << tile->neighbours.size() << std::endl;

        for (const auto &neighbour: tile->neighbours) {
            if (neighbour == nullptr) { continue; }
            std::cout << "  Neighbour Position: (" << neighbour->position.x << ", " << neighbour->position.y << ")" <<
                    std::endl;
        }
    }
    std::cout << std::endl;

    return map;
}


int main() {
    ArtistsObject artists = getArtists();

    // auto tileVec0 = getMapTXT();
    // Map map0 = builMap(tileVec0);

    auto tileVec1 = getMapXML();
    Map map1 = builMap(tileVec1);

    return 0;
}
