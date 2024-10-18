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
    std::vector<std::shared_ptr<T> > Pars(const std::vector<std::string> &txt) {
        std::vector<std::shared_ptr<T> > tiles;
        lineIndex = 0;

        std::string line = getLine(txt);

        std::regex rowColPattern(R"(rows=(\d+),cols=(\d+))"); //todo: what if change in order
        std::smatch matches;

        if (!line.empty() && std::regex_search(line, matches, rowColPattern) && matches.size() == 3) {
            rows = std::stoi(matches[1].str());
            cols = std::stoi(matches[2].str());
        } else {
            std::cerr << "Could not set rows and columns." << std::endl;
        }

        line = getLine(txt);
        // 2: Parse the tile definitions header
        if (line != "letter,rgb,weight") {
            //todo: what if change in order
            std::cerr << "Expected 'letter,rgb,weight' header line, got: '" << line << "'" << std::endl;
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
            for (int columIndex = 0; columIndex < line.length() && columIndex < cols; ++columIndex) {
                char c = line[columIndex];

                if (c == '_') {
                    // continue;
                }
                // Create a Tile if the character is Y, R, G, or B
                else if (c == 'Y' || c == 'R' || c == 'G' || c == 'B') {
                    //todo tile type names
                    // Create a new Tile
                    auto tile = std::make_shared<T>();

                    // Set the position based on the index
                    tile->position = {(columIndex), rowIndex};

                    // Determine the TileType based on the character
                    std::string typeName(1, c); // Convert char to string (e.g., 'Y' -> "Y")
                    tile->type = getTileType(typeName);

                    setTileNeighbours(tile);

                    // Check if TileType was found and report an error if not
                    if (tile->type == nullptr) {
                        std::cerr << "Error: TileType not found for character '" << c << "' at index " << columIndex <<
                                std::endl;
                    }

                    // Add the Tile to the vector
                    tiles.push_back(tile);
                } else {
                    std::cerr << "Error: Unknown tile type '" << c << "'" << std::endl;
                }
            }
        }

        return tiles;
    }

    std::shared_ptr<TileType> getTileType(const std::string &name) {
        for (auto &tileType: tileTypes) {
            if (tileType->name == name) {
                return tileType;
            }
        }
        return nullptr; // Return nullptr if no matching type is found
    }

private:
#////// nodeTypes //////
    std::vector<std::shared_ptr<TileType> > tileTypes; //todo: set global tiletypes
    int lineIndex = 0;
    int rows = 0;
    int cols = 0;

    bool parseTileType(const std::string &line) {
        std::regex tilePattern(R"((\w),\[(\d+),(\d+),(\d+)\],(\d+))");
        std::smatch matches;

        if (std::regex_search(line, matches, tilePattern)) {
            std::shared_ptr<TileType> tileType = std::make_shared<TileType>();
            tileType->name = matches[1].str()[0];
            tileType->rgb[0] = std::stoi(matches[2]);
            tileType->rgb[1] = std::stoi(matches[3]);
            tileType->rgb[2] = std::stoi(matches[4]);
            tileType->weight = std::stoi(matches[5]);

            tileTypes.push_back(tileType);
            return true;
        }

        return false;
    }

    std::string getLine(const std::vector<std::string> &txt) {
        if (lineIndex >= txt.size()) {
            return "";
        }

        std::string line = txt[lineIndex];
        lineIndex++;

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

    template<typename T>
    void setTileNeighbours(std::shared_ptr<T> &tile) {
        int x = tile->position.x;
        int y = tile->position.y;

        // Define relative positions for neighbors: left, right, up, down
        std::vector<std::pair<int, int> > offsets = {
            {x - 1, y}, // Left
            {x + 1, y}, // Right
            {x, y - 1}, // Up
            {x, y + 1} // Down
        };

        // Create neighbors based on valid offsets
        for (const auto &[nx, ny]: offsets) {
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                // Ensure non-negative positions
                auto neighbour = std::make_shared<T>();
                neighbour->position.x = nx;
                neighbour->position.y = ny;
                tile->neighbours.push_back(neighbour);
            }
        }
    }
};

#endif //TXTPARSER_HPP
