//
// Created by doguk on 10/24/2024.
//

#ifndef DISKREADER_HPP
#define DISKREADER_HPP
#include "FileReader.hpp"
#include <fstream>

/**
 * @brief Disk reader is responsible for chunking through a file saved inside of a folder
 * This will use the standard way of reading a file (non-web-based links).
 * @see FileReader.hpp for explanation
 */
class DiskReader : public FileReader {
public:
    DiskReader();

    ~DiskReader() override;

protected:
    std::string ExtractFileType(const std::string &sourceFile) override;

    void OpenStream(const std::string &sourceFile) override;

    std::vector<std::string> ReadLines() override;

    void CloseStream() override;

private:
    std::ifstream fileStream;
};

#endif //DISKREADER_HPP
