//
// Created by doguk on 10/27/2024.
//

#include "FileReadTest.hpp"

#include <FileReaderFactory.hpp>
#include <WebReader.hpp>

//Static members for quickly creating a file Reader
static std::string webSource{R"(https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media)"};
static std::string artistSource{R"(../assets/artists/artist.csv)"};
static std::string mapSource{R"(../assets/map/grid.txt)"};

//Checks if the factory creates a Reader
TEST_F(FileReadTest, CreateFileReader) {
    reader = FileReaderFactory::CreateFileReader(artistSource);
    EXPECT_NE(reader, nullptr) << "Expected value is an initialized reader!";
}

//Tests if the factory creates the correct Reader instance
TEST_F(FileReadTest, FileFactoryInstances) {
    EXPECT_EQ(FileReaderFactory::isWebUrl(webSource), true);
    EXPECT_EQ(FileReaderFactory::isWebUrl(artistSource), false);
}


//Test for seeing if the reader can extract the correct extension from disk
TEST_F(FileReadTest, CheckExtensionDisk) {
    reader = FileReaderFactory::CreateFileReader(mapSource);
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ(type, "txt");
    EXPECT_NE(type, "csv");
}

//Test for seeing if the reader can extract the correct extension from web
TEST_F(FileReadTest, CheckExtensionWeb) {
    reader = FileReaderFactory::CreateFileReader(webSource);
    auto [webType, webData] = reader->ReadContent();

    EXPECT_EQ(webType, "txt");
}
//Checks the format of the artist.csv file
TEST_F(FileReadTest, CheckArtistFormat) {
    reader = FileReaderFactory::CreateFileReader(artistSource);
    auto [type, data] = reader->ReadContent();

    EXPECT_EQ(data[0], "x,y,vx,vy");
}

//Checks the format of the grid.txt file
TEST_F(FileReadTest, CheckFirstLineMap) {
    reader = FileReaderFactory::CreateFileReader(webSource);
    auto [type, data] = reader->ReadContent();
    EXPECT_EQ(data[0], "rows=53,cols=53");
}

//Test for checking if the exception is thrown properly
TEST_F(FileReadTest, FileReaderHandleIncorrectFile) {
    std::string nonExistantPath = "../assets/wronfile.txt";
    reader = FileReaderFactory::CreateFileReader(nonExistantPath);

    //Capture std::cerr log
    testing::internal::CaptureStderr();
    reader->ReadContent();
    std::string stringErr = testing::internal::GetCapturedStderr();

    //Reader if cerr has the expected errror message.
    EXPECT_TRUE(stringErr.find("File does not exist!") != std::string::npos) << "Expected error message was not logger. Captured: " << stringErr;
}

//Checks if the FileReader returns the expected empty pair reading from disk
TEST_F(FileReadTest, EmptyPairDisk) {
    const std::string nonExistantPath = "../assets/file.txt";
    reader = FileReaderFactory::CreateFileReader(nonExistantPath);

    auto pair = reader->ReadContent();
    EXPECT_TRUE(pair.first.empty());
    EXPECT_TRUE(pair.second.empty());
}

//Checks if the FileReader returns the expected empty pair reading from web
TEST_F(FileReadTest, EmptyPairWeb) {
    const std::string nonExistantPath = "http://catsndogs.io.com";
    reader = FileReaderFactory::CreateFileReader(nonExistantPath);

    auto pair = reader->ReadContent();
    EXPECT_TRUE(pair.first.empty());
    EXPECT_TRUE(pair.second.empty());
}