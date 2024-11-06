//
// Created by doguk on 10/27/2024.
//

#ifndef FILEREADTEST_HPP
#define FILEREADTEST_HPP
#include <FileReader.hpp>
#include <gtest/gtest.h>

class FileReadTest : public ::testing::Test {
protected:
    // void SetUp() override {
    //     reader = std::unique_ptr<FileReader>();
    // }
    //
    // void TearDown() override {
    //     reader.reset();
    // }

    std::unique_ptr<FileReader> reader;
};

#endif //FILEREADTEST_HPP