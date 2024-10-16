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

//Filereader virtual Read() = 0; virtual openStream(const std::string& path) = 0;
//Webreader Read() override;

//Standard
class FileReader {
public:
    FileReader() = default;

    ~FileReader() = default;

    // virtual void extractData(const std::string& path) = 0;
    virtual std::vector<std::string> openFile(const std::string &path) {
        // std::fstream stream(path);
        // printf(path.c_str());
        // std::vector<std::string> sourceData{};
        // try {
        //     std::string line{};
        //     while (std::getline(stream, line)) {
        //         std::cout << "LINE: " << line << "\n";
        //         sourceData.emplace_back(line);
        //     }
        //     std::cout << std::endl;
        // } catch (const std::runtime_error &ex) {
        //     std::cerr << ex.what() << std::endl;
        // }
        //
        // stream.close();
        // return sourceData;

        std::ifstream file(path);
        std::cout << path.c_str() << std::endl;

        if (!file.is_open()) {
            std::cerr << "Error opening CSV file." << std::endl;
        }

        std::string line;
        std::vector<std::string> data;

        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string cell;

            while (std::getline(lineStream, cell, ',')) {
                data.push_back(cell);
            }

            data.push_back("\n");
        }

        file.close();
        return data;
    }; //Deze standaard gedrag?
};

class WebReader : public FileReader {
public:
    std::vector<std::string> openFile(const std::string &path) override {
        //Curl stream
        std::cout << "READING STREAM FROM WEB" << "\n";

        //Read stream
        for (int i = 0; i < 10; i++) {
            std::cout << "READ " << i << "\n";
        }
        std::cout << "\n";

        //Close stream
        std::cout << "CLOSING STREAM FROM WEB" << std::endl;

        return std::vector<std::string>{};
    }
};

class DiskReader : public FileReader {
};

#endif //FILEREADER_HPP
