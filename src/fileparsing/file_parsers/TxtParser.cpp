//
// Created by doguk on 10/25/2024.
//

#include "TxtParser.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>


void TXTParser::ParseData(std::vector<std::string> &data) {
    //tile = index, data: type, x, y
    //type: letter, rgb, weight
    //Header part: rows, cols, letter, rgb, weight
    //Read header
    //TODO holyyy please fix this... LarsGPT TM
    DataEntry entry;
    auto posA = data[0].find_first_of('=');
    auto posB = data[0].find_first_of(',');
    entry.AddEntry("rows", data[0].substr(data[0].find_first_of('=')+1, posB-posA-1));
    entry.AddEntry("cols", data[0].substr(data[0].find_last_of('=')+1));
    _entries.emplace_back(entry);

    std::rotate(data.begin(), data.begin()+1,data.end());
    data.pop_back();

    std::vector<std::string> headers{};

    std::stringstream sstream(data[0]);
    std::string token;
    while(std::getline(sstream, token, ',')) {
        headers.emplace_back(token);
    }

    std::rotate(data.begin(), data.begin()+1,data.end());
    data.pop_back();

    //Data entry for a tile
    // tag
    // x
    // y

    //Data entry for a type
    //  tag
    //  r
    //  g
    //  b
    // weight
    //Read tile map structure, each character is a tile
    for (const auto &line: data) {
        // Read first chunk of data
        // std::string token;
        // while(std::getline(sstream, token, ",")) {
        // }
        // DataEntry entry;
        std::cout << line << "\n";
        if (line.empty()) {
            std::cout << std::endl;
            break;
        }
    }
}
