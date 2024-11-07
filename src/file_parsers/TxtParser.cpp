//
// Created by doguk on 10/25/2024.
//

#include "TxtParser.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>


std::vector<DataEntry> TXTParser::ParseData(std::vector<std::string> &data) {
    if(data.empty()) {
        return {};
    }
    //tile = index, data: type, x, y
    //type: letter, rgb, weight
    //Header part: rows, cols, letter, rgb, weight
    //Read header
    DataEntry entry{DataEntry::GridSize, {}};
    auto posA = data[0].find_first_of('=');
    auto posB = data[0].find_first_of(',');
    entry.AddEntry("rows", data[0].substr(data[0].find_first_of('=') + 1, posB - posA - 1));
    entry.AddEntry("cols", data[0].substr(data[0].find_last_of('=') + 1));
    _entries.emplace_back(entry);

    //Remove the cols and rows
    std::rotate(data.begin(), data.begin() + 1, data.end());
    data.pop_back();

    //Remove the formatting letter,rgb,weight
    std::rotate(data.begin(), data.begin() + 1, data.end());
    data.pop_back();

    //Data entry for a type
    //  tag
    //  r
    //  g
    //  b
    // weight
    //Read tile map structure, each character is a tile
    auto it = std::find_if(data.begin(), data.end(), [&entries=_entries](std::string &l) {
        if (l.empty()) return true;
        entries.emplace_back(ParseTileType(l));
        return false;
    });
    data.erase(data.begin(), ++it);

    //Data entry for a tile
    // tag
    // x
    // y
    //Read tiles
    int currentRow{0};
    int rows = std::stoi(entry["rows"]), cols = std::stoi(entry["cols"]);
    for (const auto &line: data) {
        if (currentRow > rows && line.empty())
            break;
        auto rowEntries = ParseTiles(currentRow, cols, line);
        for (const auto &tile: rowEntries) {
            _entries.emplace_back(tile);
        }
        currentRow++;
    }
//    std::cout << std::endl;

    return _entries;
}

DataEntry &&TXTParser::ParseColour(DataEntry &entry, const std::string &data) {
    //[255,255,255]
    //Trim the [] off
    const std::string rgb[] = {"r", "g", "b"};
    std::string trimmedData = data.substr(1, data.size() - 2);
    std::istringstream rgbStream(trimmedData);

    //Read the integers.
    int i{0};
    std::string token;
    while (std::getline(rgbStream, token, ',')) {
        entry.AddEntry(rgb[i], token);
        i++;
    }
    return std::move(entry);
}

std::vector<DataEntry> TXTParser::ParseTiles(const int &row, const int &cols, const std::string &tileRow) {
    const size_t size = cols > tileRow.size() ? tileRow.size() : cols;
    std::vector<DataEntry> tempEntries{};
    for (int i = 0; i < size; i++) {
        DataEntry tileEntry{DataEntry::Tile, {}};
        const char current = tileRow[i];

        tileEntry.AddEntry("type", std::string{current});
        tileEntry.AddEntry("x", std::to_string(i));
        tileEntry.AddEntry("y", std::to_string(row));
        tempEntries.emplace_back(tileEntry);
    }

    return std::move(tempEntries);
}

DataEntry TXTParser::ParseTileType(const std::string &tileType) {
    DataEntry typeEntry{DataEntry::TileType, {}};
    std::istringstream typeStream(tileType);
    //Add the tag first
    std::string token;
    std::getline(typeStream, token, ',');
    typeEntry.AddEntry("type", token);
    //Add The rgb values
    std::getline(typeStream, token, ',');
    if (token.front() == '[') {
        std::string colorToken = token;

        while (colorToken.back() != ']') {
            std::getline(typeStream, token, ',');
            colorToken += ',' + token;
        }
        ParseColour(typeEntry, colorToken);
    }

    //Add the weight
    std::getline(typeStream, token, ',');
    typeEntry.AddEntry("weight", token);

    return std::move(typeEntry);
}