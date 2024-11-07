//
// Created by doguk on 10/24/2024.
//

#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class FileReader {
public:
    explicit FileReader(std::string sourceFile): source(std::move(sourceFile)){}

    virtual ~FileReader() = default;

    /**
     * @brief Template method function for reading a file (disk or web)
     * It will always:
     * 1. Extract the fileType for the eventual Strategy to use for parsing;
     * 2. Open its stream, file stream or web stream;
     * 3. Read the data that is inside of the file stream;
     * 4. Close the stream and cleanup properly.
     * @return a list of lines to be parsed into a standard format, of whatever fileType we read.
     */
    std::pair<std::string, std::vector<std::string> > ReadContent() {
        try {
            std::string fileType = ExtractFileType();
            OpenStream();
            std::vector<std::string> lines = ReadLines();
            CloseStream();
            return std::pair{fileType, lines};
        } catch (const std::exception &exception) {
            std::cerr << exception.what() <<  std::endl;
            return {};
        }
    }

protected:
    /**
     * @brief Extracts the file type from 
     * @return the file type found within the url or path
     */
    virtual std::string ExtractFileType() = 0;

    /**
     * @brief Opens the corresponding stream to read data from.
     */
    virtual void OpenStream() = 0;

    /**
     * @brief Reads contents of the stream and returns a list of lines.
     * @return the raw lines from the given source.
     */
    virtual std::vector<std::string> ReadLines() = 0;

    /**
     * @brief Closes the corresponding stream.
     */
    virtual void CloseStream() = 0;

    std::string source;
};


#endif //FILEREADER_HPP