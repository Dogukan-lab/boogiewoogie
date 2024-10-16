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

Map getMapTXT() {
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
    std::vector<Map> mapTXT = txtParser.Pars<Map>(file_data);

    std::cout << std::endl;
    for (auto nodes: mapTXT) {
        //std::cout << nodes.position.x << ", " << nodes.position.y << std::endl;
    }

    // auto artists = ArtistBuilder().replaceArtists(artistsCSV).build();
    //
    // std::cout << std::endl;
    // for (auto artist: artists.artists) {
    //     std::cout << artist.position.x << ", " << artist.position.y << std::endl;
    // }
    //
    // return artists;
    Map map;
    return map;
}

Map getMapXML() {
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
    std::vector<std::shared_ptr<Tile> > tileVec = xmlParser.Pars<std::shared_ptr<Tile> >(file_data);

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

    auto map = MapBuilder().replaceTiles(tileVec).build();

    // for (const auto &tile: map.tiles) {
    //     std::cout << "Tile Type: " << tile->type
    //             << ", Position: (" << tile->position.x << ", " << tile->position.y << ")"
    //             << ", Neighbours: " << tile->neighbours.size() << std::endl;
    //
    //     for (const auto &neighbour: tile->neighbours) {
    //         std::cout << "  Neighbour Position: (" << neighbour->position.x << ", " << neighbour->position.y << ")" <<
    //                 std::endl;
    //     }
    // }
    // std::cout << std::endl;

    return map;
}


int main() {
    ArtistsObject artists = getArtists();
    Map map0 = getMapXML();
    // Map map1 = getMapTXT();

    return 0;
}
