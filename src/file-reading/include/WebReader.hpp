//
// Created by hmkam on 03/10/2024.
//
#ifndef WEBREADER_HPP
#define WEBREADER_HPP
#include <string>
#include <vector>
//#include <urlmon.h>
#include <sstream>
#include <stdexcept>
// #pragma comment(lib, "urlmon.lib")

#include "FileReader.hpp"

// WebReader class to read data from a URL
class WebReader : public FileReader {
public:
    std::vector<std::string> openFile(const std::string &url) override {
        // Open the URL stream
 //       IStream *stream;
 //       HRESULT hr = URLOpenBlockingStream(0, url.c_str(), &stream, 0, nullptr);
 //       if (hr != S_OK) {
 //           throw std::runtime_error("Failed to open URL stream.");
 //       }
//
 //       // Read from the stream
 //       std::vector<std::string> data;
 //       char buffer[1024];
 //       unsigned long bytesRead;
//
 //       std::stringstream contentStream;
 //       while (true) {
 //           hr = stream->Read(buffer, sizeof(buffer), &bytesRead);
 //           if (hr != S_OK || bytesRead == 0) break;
 //           contentStream.write(buffer, bytesRead);
 //       }
//
 //       // Close the stream
 //       stream->Release();
//
 //       // Split content into lines and store in vector
 //       std::string line;
 //       while (std::getline(contentStream, line)) {
 //           data.push_back(line);
 //       }
//
 //       return data;

      return std::vector<std::string>();
    }
};

#endif //WEBREADER_HPP

