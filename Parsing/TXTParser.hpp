//
// Created by hmkam on 11/10/2024.
//

#ifndef TXTPARSER_HPP
#define TXTPARSER_HPP
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <regex>

#include "Parser.hpp"
#include "../Builders/Builder.hpp"

class TXTParser : public Parser {
public:
    TXTParser() = default;

    ~TXTParser() override = default;

    template<typename T>
    std::vector<T> Pars(const std::vector<std::string> &txt) {
        //<T> tile; //todo: not use tile
        std::vector<std::shared_ptr<Tile> > tiles;
        lineIndex = 0;

        std::string line = getLine(txt);

        if (line.empty() || txt.size() < 2) {
            std::cerr << "Not enough data to set rows and columns." << std::endl;
            return tiles;
        }
        int rows = extractValue(txt[0], "rows=");
        int cols = extractValue(txt[1], "cols=");

        line = getLine(txt);
        // 2: Parse the tile definitions header
        if (line != ",letter,rgb,weight") {
            std::cerr << "Expected ',letter,rgb,weight' header line, got: " << line << std::endl;
            return tiles;
        }

        // 3: Parse each tile definition
        while (!line.empty()) {
            line = getLine(txt);
            if (!parseTileType(line)) {
                break;
            }
        }

        // 4: Move past empty line(s)
        do {
            line = getLine(txt);
        } while (line.empty());

        // 5: Iterate through row
        for (int rowIndex = 0; !line.empty() && rowIndex < rows; line = getLine(txt), rowIndex++) {
            // 5: Iterate through each character
            for (int columIndex = 0; columIndex < line.size() && columIndex < cols; ++columIndex) {
                char c = line[columIndex];

                if (c == ',') {
                    std::cout << "\n";
                }
                std::cout << c;

                if (c == '_') {
                    continue;
                }

                // Create a Tile if the character is Y, R, G, or B
                if (c == 'Y' || c == 'R' || c == 'G' || c == 'B') {
                    // Create a new Tile
                    auto tile = std::make_shared<Tile>();

                    // Set the position based on the index
                    tile->position = {(columIndex), rowIndex};

                    // Determine the TileType based on the character
                    std::string typeName(1, c); // Convert char to string (e.g., 'Y' -> "Y")
                    tile->type = getTileType(typeName);

                    // Check if TileType was found and report an error if not
                    if (tile->type == nullptr) {
                        std::cerr << "Error: TileType not found for character '" << c << "' at index " << columIndex <<
                                std::endl;
                    }

                    // Add the Tile to the vector
                    tiles.push_back(tile);
                }
            }
        }

        return tiles;
    }

    TileType *getTileType(const std::string &name) {
        for (auto &tileType: tileTypes) {
            if (tileType.name == name) {
                return &tileType;
            }
        }
        return nullptr; // Return nullptr if no matching type is found
    }

    void printTileTypes() const {
        //todo: optional
        // std::cout << "Tile Types:" << std::endl;
        // for (const auto &pair: tileTypes) {
        //     const auto &tile = pair.second;
        //     std::cout << tile.letter << " => RGB(" << tile.color.red << ", " << tile.color.green << ", " << tile.color.
        //             blue << "), Weight: " << tile.weight << std::endl;
        // }
    }

    void printGrid() const {
        //todo: optional
        // std::cout << "Grid (" << grid.rows << "x" << grid.cols << "):" << std::endl;
        // for (const auto &row: grid.data) {
        //     std::cout << row << std::endl;
        // }
    }

private:
#////// nodeTypes //////
    std::vector<TileType> tileTypes; //todo: make persistand
    int lineIndex = 0;

    //todo: check if ok
    bool parseTileType(const std::string &line) {
        std::regex tilePattern(R"((\w),\[(\d+),(\d+),(\d+)\],(\d+))");
        std::smatch matches;

        if (std::regex_search(line, matches, tilePattern)) {
            TileType tileType;
            tileType.name = matches[1].str()[0];
            tileType.rgb[0] = std::stoi(matches[2]);
            tileType.rgb[1] = std::stoi(matches[3]);
            tileType.rgb[2] = std::stoi(matches[4]);
            tileType.weight = std::stoi(matches[5]);

            tileTypes.push_back(tileType);
            return true;
        }

        return false;
    }

    std::string getLine(const std::vector<std::string> &txt) {
        // if (lineIndex >= txt.size()) {
        //     throw std::runtime_error("Read line out of range lineIndex: " + lineIndex);
        // }
        std::string line;

        for (; lineIndex < txt.size(); ++lineIndex) {
            if (txt[lineIndex] == "\n") {
                lineIndex++;
                break;
            }
            line.append("," + txt[lineIndex]);
        }

        return line;
    }

    int extractValue(const std::string &text, const std::string &prefix) {
        size_t pos = text.find(prefix);
        if (pos != std::string::npos) {
            try {
                // Extract the part after the '=' sign
                return std::stoi(text.substr(pos + prefix.size()));
            } catch (const std::invalid_argument &e) {
                std::cerr << "Invalid value after '" << prefix << "': " << e.what() << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Value after '" << prefix << "' is out of range: " << e.what() << std::endl;
            }
        }
        return -1; // Return a negative value to indicate an error
    }
};

#endif //TXTPARSER_HPP
