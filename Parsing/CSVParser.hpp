//
// Created by hmkam on 10/10/2024.
//

#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP
#include <string>
#include <vector>

#include "Parser.hpp"

class CSVParser : public Parser {
public:
    CSVParser() = default;

    ~CSVParser() override = default;

    template<typename T>
    std::vector<T> Pars(const std::vector<std::string> &csv) {
        std::vector<T> result;

        T artist;

        for (std::size_t i = 0; i < csv.size(); ++i) {
            if (i <= 4) {
                continue;
            }
            if (csv[i] == "\n") {
                result.push_back(artist);
                continue;
            }

            switch (i % 5) {
                case 0:
                    artist.position.x = stod(csv[i]);
                    break;

                case 1:
                    artist.position.y = stod(csv[i]);
                    break;

                case 2:
                    artist.direction.x = stod(csv[i]);
                    break;

                case 3:
                    artist.direction.y = stod(csv[i]);
                    break;
            }
        }
        return result; // Return the parsed result
    }
};


#endif //CSVPARSER_HPP


