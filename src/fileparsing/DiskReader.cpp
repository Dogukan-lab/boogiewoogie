//
// Created by doguk on 10/24/2024.
//

#include "DiskReader.hpp"
#include <filesystem>

DiskReader::DiskReader() = default;

DiskReader::~DiskReader() = default;

std::string DiskReader::ExtractFileType(const std::string &sourceFile) {
    return sourceFile.substr(sourceFile.find_last_of('.'));
}

void DiskReader::OpenStream(const std::string &sourceFile) {
        if (std::filesystem::exists(sourceFile))
            fileStream.open(sourceFile);
        else
            throw std::runtime_error("File does not exist!");
}

std::vector<std::string> DiskReader::ReadLines() {
    std::vector<std::string> data;
    std::string line{};
    while(std::getline(fileStream, line)) {
        data.emplace_back(line);
    }


    return data;
}

void DiskReader::CloseStream() {
    fileStream.close();
}
