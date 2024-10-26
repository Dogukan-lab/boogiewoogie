//
// Created by doguk on 10/25/2024.
//

#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
#include <vector>
#include "DataEntry.hpp"

/**
 * @brief This is the base of the parsing system, every parser is a strategy inside of the whole structure.
 */
class Parser {
public:
    virtual ~Parser() = default;
    virtual std::vector<DataEntry> ParseData(std::vector<std::string> &data) = 0;
protected:
    std::vector<DataEntry> _entries;
};

#endif //PARSER_HPP
