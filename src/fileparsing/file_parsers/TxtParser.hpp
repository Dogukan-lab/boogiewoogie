//
// Created by doguk on 10/25/2024.
//

#ifndef TXTPARSER_HPP
#define TXTPARSER_HPP
#include "Parser.hpp"

class TXTParser: public Parser {
public:

    ~TXTParser() override = default;
    void ParseData(std::vector<std::string> &data) override;
};



#endif //TXTPARSER_HPP
