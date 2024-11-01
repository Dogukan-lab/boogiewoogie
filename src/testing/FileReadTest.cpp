//
// Created by doguk on 10/27/2024.
//

#include "FileReadTest.hpp"

TEST_F(FileReadTest, CreateFileReader) {
    EXPECT_NE(reader, nullptr);
}

TEST_F(FileReadTest, CheckFileExtension) {
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ("csv", type);
}

TEST_F(FileReadTest, CheckFirstLineOfData) {
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ('x', data[0][0]);
}
