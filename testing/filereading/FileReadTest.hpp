//
// Created by doguk on 10/27/2024.
//

#ifndef FILEREADTEST_HPP
#define FILEREADTEST_HPP
#include <FileReader.hpp>
#include <gtest/gtest.h>

class FileReadTest : public ::testing::Test {
protected:
    std::unique_ptr<FileReader> reader;
};

#endif //FILEREADTEST_HPP