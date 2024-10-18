//
// Created by hmkam on 03/10/2024.
//

#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
// #include <curl>
#include "../curl/curl.h" // Include libcurl for HTTP requests

//Filereader virtual Read() = 0; virtual openStream(const std::string& path) = 0;
//Webreader Read() override;

//Standard
class FileReader {
public:
    FileReader() = default;

    ~FileReader() = default;

    // virtual void extractData(const std::string& path) = 0;
    virtual std::vector<std::string> openFile(const std::string &path) {
        std::ifstream file(path);
        std::cout << path.c_str() << std::endl;

        if (!file.is_open()) {
            throw std::runtime_error("Error opening file: " + path);
        }

        std::string line;
        std::vector<std::string> data;

        while (std::getline(file, line)) {
            data.push_back(line);
        }

        file.close(); //todo: smartpointer to clean up
        return data;
    };
};

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

// DiskReader class (for future extension)
class DiskReader : public FileReader {};

#endif //FILEREADER_HPP
