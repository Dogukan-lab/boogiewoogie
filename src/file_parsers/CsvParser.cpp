//
// Created by doguk on 10/25/2024.
//

#include "include/CsvParser.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>

std::vector<DataEntry> CSVParser::ParseData(std::vector<std::string> &data) {
    if(data.empty()) {
        return {};
    }
    //Read the header.
    std::rotate(data.begin(), data.begin() + 1, data.end());
    const auto header = *(data.end() - 1);
    data.pop_back();
    //Split headers into their own qualifier.
    const auto headers = checkFormatting(header);

    //Read the actual data
    for (auto &line: data) {
        std::stringstream stream(line);
        DataEntry entry {DataEntry::Artist, {}};
        int index{0};
        std::string token{};
        while (std::getline(stream, token, ',')) {
            if (index < headers.size()) {
                //Map data to token
                entry.AddEntry(headers[index], token);
                index++;
            }
        }
        _entries.emplace_back(entry);
    }

    return _entries;
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