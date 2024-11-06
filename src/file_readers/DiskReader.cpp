//
// Created by doguk on 10/24/2024.
//

#include "DiskReader.hpp"
#include <filesystem>

DiskReader::DiskReader(const std::string &sourceFile): FileReader(sourceFile) {
}

DiskReader::~DiskReader() = default;

std::string DiskReader::ExtractFileType() {
    return source.substr(source.find_last_of('.') + 1);
}

void DiskReader::OpenStream() {
    if (!std::filesystem::exists(source)) {
        throw std::runtime_error("File does not exist!");
    }
    fileStream.open(source);
}

std::vector<std::string> DiskReader::ReadLines() {
    std::vector<std::string> data;
    std::string line{};
    while (std::getline(fileStream, line)) {
        data.emplace_back(line);
    }

    return data;
}

void DiskReader::CloseStream() {
    fileStream.close();
}