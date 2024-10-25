//
// Created by doguk on 10/23/2024.
//

#ifndef FILEREADINGTEST_HPP
#define FILEREADINGTEST_HPP
#include <memory>
#include <string>
#include <vector>
#include "Builder.hpp"
#include "FileReader.hpp"

class FileReadingTest {
public:
    void runFileTests();

private:
    struct Data {
        int data;
    };

    bool printDebug(const std::vector<std::string> &file_data);

    bool printDebug(const std::vector<std::shared_ptr<Tile> > &tileVec);

    bool printDebug(const Map &map);

    bool printDebug(const std::vector<Artist> &artistsCSV);

    bool printDebug(const ArtistsObject &artists);

    std::vector<std::string> readFromFile(const std::string &path, FileReader &reader);

    bool isLocalFile(const std::string &location);

    std::vector<std::string> readFile(const std::string &location);

    std::vector<std::shared_ptr<Tile>> getMapTXT(const std::string &location);

    Map builMap(const std::vector<std::shared_ptr<Tile> > &tileVec);

    std::vector<std::shared_ptr<Tile>> getMapXML(const std::string &location);


    ArtistsObject getArtists();
};


#endif //FILEREADINGTEST_HPP
