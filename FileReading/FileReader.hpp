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

#endif //FILEREADER_HPP
