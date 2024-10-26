//
// Created by doguk on 10/25/2024.
//

#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP
#include <map>
#include "Parser.hpp"

class CSVParser : public Parser {
public:
    ~CSVParser() override = default;

    std::vector<DataEntry> ParseData(std::vector<std::string> &data) override;

    inline std::map<std::string, std::vector<std::string>>&
    getMapping() { return csvMapping; }

private:
    std::map<std::string, std::vector<std::string>> csvMapping{};

    static std::vector<std::string> checkFormatting(const std::string &format);
};

#endif //CSVPARSER_HPP
