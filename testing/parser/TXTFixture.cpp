//
// Created by doguk on 11/6/2024.
//
#include <algorithm>
#include "ParserSuite.hpp"

TEST_F(ParserSuite, TXTCheckGridSize) {
    auto entries = txtParser->ParseData(txtData);

    auto &rowCols = entries[0];

    EXPECT_EQ(rowCols.tag, DataEntry::GridSize);
    EXPECT_EQ(rowCols["rows"], "53");
    EXPECT_EQ(rowCols["cols"], "53");
}

TEST_F(ParserSuite, TXTHandleEmtpyEntries) {
    auto entries = txtParser->ParseData(emptyData);

    EXPECT_TRUE(entries.empty());
}

//Data entries have enums defining what type of data it will store,
//thus we want to verify if these are set correctly
TEST_F(ParserSuite, TXTCheckTyping) {
    auto entries = txtParser->ParseData(txtData);

    auto& gridSize = entries[0]; //Grid size
    auto& tileType = entries[1]; //First Tile Type
    auto& tile = entries[5]; // First Tile

    EXPECT_EQ(gridSize.tag, DataEntry::GridSize);
    EXPECT_EQ(tileType.tag, DataEntry::TileType);
    EXPECT_EQ(tile.tag, DataEntry::Tile) << "Expected DataEntry::Tile, but got: " << tile.tag;
}

//TODO test case with weirdly formatted data
TEST_F(ParserSuite, TXTTileTypeData) {
    auto entries = txtParser->ParseData(txtData);

    std::vector<DataEntry> tileType = {
            entries[1],
            entries[2],
            entries[3],
            entries[4],
    };

    EXPECT_EQ(tileType[0].tag, DataEntry::TileType);
    EXPECT_EQ(tileType[0].entries["type"], "Y");
    EXPECT_EQ(tileType[0].entries["r"], "250");
    EXPECT_EQ(tileType[0].entries["g"], "201");
    EXPECT_EQ(tileType[0].entries["b"], "1");
    EXPECT_EQ(tileType[0].entries["weight"], "1");
}

TEST_F(ParserSuite, TXTTileData) {
    auto entries = txtParser->ParseData(txtData);

    auto iterator = std::find_if(entries.begin(), entries.end(), [](const DataEntry& entry){
        return entry.tag == DataEntry::Tile;
    });

    auto& tile = *iterator;

    EXPECT_EQ(tile["type"], "B");
    EXPECT_EQ(tile["x"], "0");
    EXPECT_EQ(tile["y"], "0");
}