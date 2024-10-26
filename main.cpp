// struct TestArtist {
//     glm::vec2 position;
//     glm::vec2 direction;
// };
//
// void testfun(const std::string &source) {
//     const auto reader = FileReaderFactory::CreateFileReader(source);
//     auto [fileType, data] = reader->ReadContent();
//
//     CSVParser parser;
//     parser.ParseData(data);
//     auto map = parser.getMapping();
//
//     std::vector<TestArtist> artists{};
//     if (map.empty())
//         return;
//
//     //Artist builder example
//     for (int i = 0; i < map["x"].size(); i++) {
//         TestArtist artist{
//             glm::vec2(stof(map["x"].at(i)), stof(map["y"].at(i))),
//             glm::vec2(stof(map["vx"].at(i)), stof(map["vy"].at(i)))
//         };
//         artist.direction = glm::normalize(artist.direction);
//         artists.emplace_back(artist);
//     }
//
//     for (const auto &artist: artists) {
//         std::cout << glm::to_string(artist.position) << ":" << glm::to_string
//                 (artist.direction) << "\n";
//     }
// }


#include <TileManager.hpp>

#include "MapBuilder.hpp"
#include "FileReader.hpp"
#include "FileReaderFactory.hpp"
#include "TxtParser.hpp"

int main(void) {
    std::string webSource = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media";
    // std::string diskSource = R"(../assets/artists.csv)";
    // const std::string testSource = R"(../assets/map.csv)";
    // BoogieWoogieApp app{};
    // app.SetupSimulation(diskSource);
    // app.RunSimulation();
    const auto reader = FileReaderFactory::CreateFileReader(webSource);
    auto [fileType, data] = reader->ReadContent();
    TXTParser parser;

    // for (const auto &[tag, entries]: parser.ParseData(data)) {
    // std::cout << "ENTRY TAG: " << tag << "\n";
    // for (const auto &[key, value]: entries) {
    // std::cout << "KEY: " << key << " , " << "VALUE: " << value << "\n";
    // }
    // }
    // std::cout << std::endl;
    TileManager manager;
    MapBuilder builder;
    for (auto &entry: parser.ParseData(data)) {
        switch (entry.tag) {
            case DataEntry::Dimensions:
                builder.setMapSize(entry);
                break;
            case DataEntry::TileType:
                builder.addTileType(entry);
                break;
            case DataEntry::Tile:
                builder.addTile(entry);
                break;
            default: break;
        }
    }

    const auto grid = builder.build();

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[0].size(); x++) {
            const auto &tile = *grid[y][x];
            std::cout << tile.type->tag;
        }
        std::cout << std::endl;
    }

    return 0;
}
