//
// Created by hmkam on 03/10/2024.
//

#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class FileReader {
public:
    FileReader() = default;

    virtual ~FileReader() = default;

    // virtual void extractData(const std::string& path) = 0;
    virtual std::vector<std::string> openFile(const std::string& path) {
        std::ifstream file(path);
        std::cout << path << std::endl;

        if (!file.is_open()) {
            // throw std::runtime_error("Error opening file: " + path);
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
