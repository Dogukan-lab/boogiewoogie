//
// Created by hmkam on 10/10/2024.
//

#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP
#include <string>
#include <vector>

#include "Parser.hpp"
#include "../Builders/Builder.hpp" //todo only vector2D

class CSVParser : public Parser {
public:
    CSVParser() = default;

    ~CSVParser() override = default;

    template<typename T>
    std::vector<T> Pars(const std::vector<std::string> &csv) {
        std::vector<T> result;

        T artist; //todo: expect artist, must be kinde unkown

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
                    artist.position.x = stoi(csv[i]); //todo: string(double/float) to int
                    break;

                case 1:
                    artist.position.y = stoi(csv[i]); //todo: string(double/float) to int
                    break;

                case 2:
                    // artist.position.xv = stoi(csv[i]);
                    break;

                case 3:
                    // artist.position.yv = stoi(csv[i]);
                    break;
            }
        }
        return result; // Return the parsed result
    }
};


#endif //CSVPARSER_HPP


