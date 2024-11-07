//
// Created by doguk on 11/6/2024.
//

#ifndef PARSERSUITE_HPP
#define PARSERSUITE_HPP

#include <CsvParser.hpp>
#include <FileReader.hpp>
#include <FileReaderFactory.hpp>
#include <TxtParser.hpp>
#include <XmlParser.hpp>
#include <memory>
#include <gtest/gtest.h>

class ParserSuite: public ::testing::Test {
protected:

    void SetUp() override {
        txtParser = std::make_unique<TXTParser>();
        csvParser = std::make_unique<CSVParser>();
        xmlParser = std::make_unique<XMLParser>();

        txtData = FileReaderFactory::CreateFileReader(R"(../assets/map/testgrid.txt)")->ReadContent().second;
        xmlData = FileReaderFactory::CreateFileReader(R"(../assets/map/testgraph.xml)")->ReadContent().second;
        csvData = FileReaderFactory::CreateFileReader(R"(../assets/artists/artist.csv)")->ReadContent().second;
    }

    std::unique_ptr<TXTParser> txtParser;
    std::unique_ptr<CSVParser> csvParser;
    std::unique_ptr<XMLParser> xmlParser;

    std::vector<std::string> txtData{};
    std::vector<std::string> emptyData{};
    std::vector<std::string> csvData{};
    std::vector<std::string> xmlData{};
};



#endif //PARSERSUITE_HPP