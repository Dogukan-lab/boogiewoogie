//
// Created by doguk on 11/7/2024.
//

#ifndef BOOGIEWOOGIE_FIXTUREARTISTBUILDER_HPP
#define BOOGIEWOOGIE_FIXTUREARTISTBUILDER_HPP

#include "FileReaderFactory.hpp"
#include "FileReader.hpp"
#include "AritistBuilder.hpp"
#include "CsvParser.hpp"
#include <gtest/gtest.h>

class FixtureArtistBuilder: public ::testing::Test {
protected:

    void SetUp() override {
        builder = std::make_unique<ArtistBuilder>();
        auto data = FileReaderFactory::CreateFileReader(R"(../assets/artists/artist.csv)")->ReadContent().second;
        CSVParser parser;
        entries = parser.ParseData(data);
    }

    void TearDown() override {
        builder.reset();
        entries.clear();
    }

    std::unique_ptr<ArtistBuilder> builder;
    std::vector<DataEntry> entries;
};


#endif //BOOGIEWOOGIE_FIXTUREARTISTBUILDER_HPP