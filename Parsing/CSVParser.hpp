//
// Created by hmkam on 10/10/2024.
//

#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP
#include <string>
#include <vector>
#include <regex>

#include "Parser.hpp"

class CSVParser : public Parser {
public:
    CSVParser() = default;

    ~CSVParser() override = default;

    template<typename T>
    std::vector<T> Pars(const std::vector<std::string> &csv) {
        std::vector<T> result;

        T artist;

        for (const auto &line: csv) {
            bool first = true;
            if (first) {
                first = false;
                std::istringstream lineStream(line);
                std::string cell;

                while (std::getline(lineStream, cell, ',')) {
                    if (cell == "x" || cell == "y" || cell == "vx" || cell == "vy") {}
                    //todo: do something with layout of the position and speed
                }
            }

            std::regex tilePattern(R"((\d+(\.\d+)?),(\d+(\.\d+)?),(\d+(\.\d+)?),(\d+(\.\d+)?))");
            std::smatch matches;

            if (std::regex_search(line, matches, tilePattern)) {
                artist.position.x = stod(matches[1]);
                artist.position.y = stod(matches[3]);
                artist.direction.x = stod(matches[5]);
                artist.direction.y = stod(matches[7]);

                result.push_back(artist);
            }
        }
        return result; // Return the parsed result
    }
};

#endif //CSVPARSER_HPP


