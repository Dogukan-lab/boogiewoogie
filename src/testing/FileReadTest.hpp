//
// Created by doguk on 10/27/2024.
//

#ifndef FILEREADTEST_HPP
#define FILEREADTEST_HPP

#include <FileReader.hpp>
#include <FileReaderFactory.hpp>

#include "gtest/gtest.h"

class FileReadTest: public ::testing::Test {
public:

    void SetUp() override {
        std::string source = R"(../assets/artist.csv)";
        reader = FileReaderFactory::CreateFileReader(source);
    }

    void TearDown() override {
        reader.reset();
    }
    std::unique_ptr<FileReader> reader;
};

#endif //FILEREADTEST_HPP
