//
// Created by doguk on 10/25/2024.
//

#ifndef TXTPARSER_HPP
#define TXTPARSER_HPP
#include "Parser.hpp"

class TXTParser: public Parser {
public:

    ~TXTParser() override = default;
    std::vector<DataEntry> ParseData(std::vector<std::string> &data) override;

private:
    //Helper functions for parsing
    /**
     * @brief Helper function to parse the colour of a TileType
     * @param entry The entry to fill with the data.
     * @param data The line of data to parse into rgb values
     */
    static DataEntry&& ParseColour(DataEntry& entry, const std::string& data);
    /**
     * @brief Helper function to parse a Tile in the
     * @param row the current row of the tilemap
     * @param tileRow The line of data to parse into tile xy coordinates
     */
    static std::vector<DataEntry>ParseTiles(const int& row, const int& cols, const std::string &tileRow);
    /**
     * @brief Helper function to parse a TileType
     * @param tileType The line of data to parse into a TileType
     */
    static DataEntry ParseTileType(const std::string& tileType);
};



#endif //TXTPARSER_HPP
