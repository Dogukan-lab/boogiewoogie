//
// Created by doguk on 10/24/2024.
//

#ifndef WEBREADER_HPP
#define WEBREADER_HPP
#include <memory>
#include <D:/GitHub/boogiewoogie/libs/curl/include/curl/curl.h>
#include "FileReader.hpp"

/**
 * @brief Reads URLs recieved from user input
 * @see Filereader.hpp for further info
 */
class WebReader : public FileReader {
public:
    explicit WebReader(const std::string &sourceFile);

    ~WebReader() override;

protected:
    std::string ExtractFileType() override;

    void OpenStream() override;

    std::vector<std::string> ReadLines() override;

    void CloseStream() override;

private:
    /**
      * @param contents the contents downloaded from the server
      * @param size The size of each element, most of the time 1 byte
      * @param nmemb Indication of the number of elements
      * @param userp User defined pointer, to store and/or manipulate data.
      * @return total number of bytes processed gets returned.
      */
    static size_t StreamCallback(void *contents, size_t size, size_t nmemb, std::stringstream *userp);

    //Unique pointer with custom deleter to call the cleanup function for the CURL webstream.
    std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curlptr;
    std::string url;
};

#endif //WEBREADER_HPP
