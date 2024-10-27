#include <DataEntry.hpp>
#include <FileReader.hpp>
#include <FileReaderFactory.hpp>
#include <MapBuilder.hpp>
#include <string>
#include <XmlParser.hpp>

#include "BoogieWoogieApp.hpp"

void PrintEntries(const std::vector<DataEntry> &entries) {
    for (const auto &[tag, data]: entries) {
        std::cout << "ENTRY TAG: " << tag << "\n";

        for (const auto &[key, val]: data) {
            std::cout << "KEY: " << key << " " << "VALUE: " << val << "\n";
        }

        std::cout << std::endl;
    }
}

void testParser() {
    std::string mapSource = R"(../assets/graph.xml)";
    std::string artistSource = R"(../assets/artists.csv)";

    auto reader = FileReaderFactory::CreateFileReader(mapSource);
    auto [type, list] = reader->ReadContent();

    TileManager manager{};
    auto& holder = TileManager::types;
    XMLParser parser;
    MapBuilder builder;
    auto entries = parser.ParseData(list);

    PrintEntries(entries);

    for (auto &entry: entries) {
        switch (entry.tag) {
            case DataEntry::GridSize:
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
    builder.build();
    // manager.AddTiles(std::move(builder.build()));
}

int main(void) {
    BoogieWoogieApp app{};
    app.SetupSimulation();
    app.RunSimulation();

    // testParser();

    return 0;
}
