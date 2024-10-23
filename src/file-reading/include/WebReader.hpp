//
// Created by hmkam on 03/10/2024.
//
#ifndef WEBREADER_HPP
#define WEBREADER_HPP
#include <memory>
#include <curl/curl.h>
#include "FileReader.hpp"

// WebReader class to read data from a URL
class WebReader : public FileReader {
public:
    WebReader();

    std::vector<std::string> openFile(const std::string& url) override;

private:
    /**
     * @param contents the contents downloaded from the server
     * @param size The size of each element, most of the time 1 byte
     * @param nmemb Indication of the number of elements
     * @param userp User defined pointer, to store and/or manipulate data.
     * @return total number of bytes processed gets returned.
     */
    static size_t StreamCallback(void *contents, size_t size, size_t nmemb, std::stringstream* userp);

    std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curlptr;
    CURLcode result;
};

#endif //WEBREADER_HPP

