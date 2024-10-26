#include <filesystem>
#include <iostream>
#include "file_readers/FileReader.hpp"
#include "file_readers/FileReaderFactory.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <AritistBuilder.hpp>
#include <DataEntry.hpp>
#include <MapBuilder.hpp>
#include <gtx/string_cast.hpp>
#include "BoogieWoogieApp.hpp"
#include "file_parsers/CsvParser.hpp"
#include "file_parsers/TxtParser.hpp"

struct TestArtist {
    glm::vec2 position;
    glm::vec2 direction;
};

void testfun(const std::string &source) {
    const auto reader = FileReaderFactory::CreateFileReader(source);
    auto [fileType, data] = reader->ReadContent();

    CSVParser parser;
    parser.ParseData(data);
    auto map = parser.getMapping();

    std::vector<TestArtist> artists{};
    if (map.empty())
        return;

    //Artist builder example
    for (int i = 0; i < map["x"].size(); i++) {
        TestArtist artist{
            glm::vec2(stof(map["x"].at(i)), stof(map["y"].at(i))),
            glm::vec2(stof(map["vx"].at(i)), stof(map["vy"].at(i)))
        };
        artist.direction = glm::normalize(artist.direction);
        artists.emplace_back(artist);
    }

    for (const auto &artist: artists) {
        std::cout << glm::to_string(artist.position) << ":" << glm::to_string
                (artist.direction) << "\n";
    }
}


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
    parser.ParseData(data);


    return 0;
}
