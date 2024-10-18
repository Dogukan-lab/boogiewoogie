//
// Created by hmkam on 03/10/2024.
//

#ifndef WEBREADER_HPP
#define WEBREADER_HPP
#include <string>
#include <sstream>
// #include <curl>
#include "../curl/curl.h" // Include libcurl for HTTP requests

//Filereader virtual Read() = 0; virtual openStream(const std::string& path) = 0;
//Webreader Read() override;

#include "FileReader.hpp"


//todo: make web reader

// Helper function to handle data received from libcurl
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t totalSize = size * nmemb;
    output->append((char *) contents, totalSize);
    return totalSize;
}

// WebReader class to read data from a URL
class WebReader : public FileReader {
public:
    // std::vector<std::string> openFile(const std::string &url) override {
    //     CURL *curl;
    //     CURLcode res;
    //     std::string readBuffer;
    //
    //     curl = curl_easy_init();
    //     if (curl) {
    //         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    //         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    //         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    //
    //         // Perform the request, and get the response
    //         res = curl_easy_perform(curl);
    //         if (res != CURLE_OK) {
    //             std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    //         }
    //
    //         // Cleanup
    //         curl_easy_cleanup(curl);
    //     } else {
    //         throw std::runtime_error("Failed to initialize CURL.");
    //     }
    //
    //     // Parse the readBuffer into lines and return as vector of strings
    //     std::vector<std::string> data;
    //     std::istringstream stream(readBuffer);
    //     std::string line;
    //     while (std::getline(stream, line)) {
    //         data.push_back(line);
    //     }
    //
    //     return data;
    // }
};


#endif //WEBREADER_HPP
