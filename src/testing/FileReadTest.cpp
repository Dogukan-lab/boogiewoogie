//
// Created by doguk on 10/27/2024.
//

#include "FileReadTest.hpp"

#include <FileReaderFactory.hpp>
#include <WebReader.hpp>

static std::string _webSource{R"(https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media)"};
static std::string _artistSource{R"(../assets/artists/artist.csv)"};
static std::string _mapSource{R"(../assets/map/grid.txt)"};

TEST_F(FileReadTest, CreateFileReader) {
    EXPECT_NE(reader, nullptr);
}

TEST_F(FileReadTest, CheckFileExtension) {
    reader = FileReaderFactory::CreateFileReader(_artistSource);
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ("csv", type);
}

TEST_F(FileReadTest, CheckWrongExtension) {
    reader = FileReaderFactory::CreateFileReader(_mapSource);
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ(type, "txt");
    EXPECT_NE(type, "csv");
}

TEST_F(FileReadTest, CheckArtistFormat) {
    reader = FileReaderFactory::CreateFileReader(_artistSource);
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ(data[0], "x,y,vx,vy");
}

TEST_F(FileReadTest, CheckFirstLineMap) {
    auto [type, data] = reader->ReadContent();
    EXPECT_EQ("rows=53,cols=53", data[0]);
}

TEST_F(FileReadTest, FileFactoryInstances) {
    EXPECT_EQ(FileReaderFactory::isWebUrl(_webSource), true);
    EXPECT_EQ(FileReaderFactory::isWebUrl(_artistSource), false);
}

TEST_F(FileReadTest, FileReaderHandleIncorrectFile) {
    reader = FileReaderFactory::CreateFileReader(R"(../assets/wrongfile.txt)");
    ASSERT_THROW(reader->ReadContent(), std::runtime_error);
}