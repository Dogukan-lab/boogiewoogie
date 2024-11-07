//
// Created by doguk on 11/7/2024.
//
#include "ParserSuite.hpp"

TEST_F(ParserSuite, CSVCheckArtistData) {
    auto entries = csvParser->ParseData(csvData);

    auto &artist = entries[0];

    EXPECT_EQ(artist.tag, DataEntry::Artist);
    EXPECT_EQ(artist["x"], "0");
    EXPECT_EQ(artist["y"], "0");
    EXPECT_EQ(artist["vx"], "2");
    EXPECT_EQ(artist["vy"], "1");
}

TEST_F(ParserSuite, CSVHandleEmptyEntries) {
    auto entries = csvParser->ParseData(emptyData);

    EXPECT_TRUE(entries.empty());
}