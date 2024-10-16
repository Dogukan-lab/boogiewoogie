//
// Created by hmkam on 11/10/2024.
//

#ifndef TXTPARSER_HPP
#define TXTPARSER_HPP
#include <string>
#include <vector>

#include "Parser.hpp"

class TXTParser : public Parser {
public:
    TXTParser() = default;

    ~TXTParser() override = default;

    template<typename T>
    std::vector<T> Pars(const std::vector<std::string> &txt) {
        std::vector<T> result;

        //todo: convert to graph

        return result; // Return the parsed result
    }
};

#endif //TXTPARSER_HPP
