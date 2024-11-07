//
// Created by doguk on 10/27/2024.
//

#ifndef XMLPARSER_HPP
#define XMLPARSER_HPP
#include "Parser.hpp"

class XMLParser: public Parser  {
public:
    std::vector<DataEntry> ParseData(std::vector<std::string> &data) override;
};



#endif //XMLPARSER_HPP