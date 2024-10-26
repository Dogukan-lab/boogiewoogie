//
// Created by doguk on 10/25/2024.
//

#include "CsvParser.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>

void CSVParser::ParseData(std::vector<std::string> &data) {
    //Read the header.
    std::rotate(data.begin(), data.begin() + 1, data.end());
    const auto header = *(data.end() - 1);
    data.pop_back();
    //Split headers into their own qualifier.
    const auto headers=  checkFormatting(header);

    //Read the actual data
    for (auto &line: data) {
        std::stringstream stream(line);
        int index{0};
        std::string token{};
        while (std::getline(stream, token, ',')) {
            if (index < headers.size()) {
                //Map data to token
                csvMapping[headers[index]].emplace_back(token);
                index++;
            }
        }
    }
}

std::vector<std::string> CSVParser::checkFormatting(const std::string &format) {
    //Get first line
    std::vector<std::string> headers;
    std::stringstream sstream(format);
    std::string token;
    while (std::getline(sstream, token, ',')) {
        headers.emplace_back(token);
    }

    return headers;
}
