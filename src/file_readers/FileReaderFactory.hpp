//
// Created by doguk on 10/24/2024.
//

#ifndef FILEREADERFACTORY_HPP
#define FILEREADERFACTORY_HPP
#include <memory>
#include <string>

class FileReader;

/**
 * @brief Factory method for creating either a web- or diskreader.
 */
class FileReaderFactory {
public:
    FileReaderFactory()=default;
    ~FileReaderFactory() = default;

    /**
     * @brief Creates a reader based on if the source is a web link or not.
     * @param source The source target it comes from
     * @return Corresponding reader for reading the data.
     */
    static std::unique_ptr<FileReader> CreateFileReader(const std::string& source);

    /**
     * @brief Helper function to determine if a web reader is necessary.
     * @param sourceType The assumed web link that we want to verify.
     * @return true if it needs to read from web, otherwise read from disk
     */
    static bool isWebUrl(const std::string& sourceType);
};

#endif //FILEREADERFACTORY_HPP