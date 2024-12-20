//
// Created by doguk on 10/24/2024.
//

#include "FileReaderFactory.hpp"

#include "DiskReader.hpp"
#include "WebReader.hpp"

std::unique_ptr<FileReader> FileReaderFactory::CreateFileReader(const std::string &source) {
    if (isWebUrl(source))
        return std::make_unique<WebReader>(source);

    return std::make_unique<DiskReader>(source);
}

bool FileReaderFactory::isWebUrl(const std::string &sourceType) {
    return sourceType.find("http") != std::string::npos;
}
