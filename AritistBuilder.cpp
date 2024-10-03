//
// Created by hmkam on 23/09/2024.
//

#include "AritistBuilder.hpp"

#include <iostream>

#include "FileProxy.hpp"

void BuildAritistCsv(std::string fileData) {
    std::cout << "build csv:   " << fileData << std::endl;
}
void BuildAritistXml(std::string fileData) {
    std::cout << "build xml:   " << fileData << std::endl;
}

enum FileType { csv, xml, txt };

void AritistBuilder::BuildAritist(std::string fileLocation) {
    FileProxy file;
    std::cout << "read file\n";
    std::string fileData = file.ReadFile(fileLocation);

    FileType fileType = csv;

    switch(fileType) {
        case csv  : {
            BuildAritistCsv(fileData);
            break;
        }

        case xml : {
            std::cout << "read xml\n";
            BuildAritistXml(fileLocation);
            break;
        }

        case txt : {
            std::cout << "read txt ...\n";
            break;
        }

        default: {
        }
    }
}
