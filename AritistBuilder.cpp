//
// Created by hmkam on 23/09/2024.
//

#include "AritistBuilder.hpp"

#include <iostream>

#include "FileProxy.hpp"

void BuildAritistCsv(std::string fileLocation) {
    std::cout << "build csv\n";
}
void BuildAritistXml(std::string fileLocation) {
    std::cout << "build xml\n";
}

enum FileType { csv, xml, txt };

void AritistBuilder::BuildAritist(std::string fileLocation) {
    FileProxy file;
    std::string fileData = file.ReadFile(fileLocation);

    FileType fileType = csv;

    switch(fileType) {
        case csv  : {
            std::cout << "read csv\n";
            BuildAritistCsv(fileLocation);
        }

        case xml : {
            std::cout << "read xml\n";
            BuildAritistXml(fileLocation);
        }

        case txt : {
            std::cout << "read txt ...\n";
        }

        default: {
        }
    }
}
