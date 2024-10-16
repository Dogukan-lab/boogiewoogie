//
// Created by hmkam on 23/09/2024.
//

#include "AritistBuilder.hpp"

#include <iostream>

#include "../FileReading/FileProxy.hpp"

using namespace std;

string getFileExtension(const string &filename) {
    size_t lastDotPos = filename.find_last_of('.');
    if (lastDotPos == string::npos) {
        // No dot found, return an empty string as there's no extension
        return "";
    } else {
        return filename.substr(lastDotPos + 1);
    }
}

void BuildAritistCsv(std::string fileData) {
    std::cout << "build csv:   " << fileData << std::endl;
}

void BuildAritistXml(std::string fileData) {
    std::cout << "build xml:   " << fileData << std::endl;
}

// enum FileType { csv, xml, txt };

// void ArtistBuilder::BuildAritist(std::string fileLocation) {
// FileProxy file;
// std::cout << "read file\n";
// std::vector<std::string> fileData = file.ReadFile(fileLocation);
//
//
// string extension = getFileExtension(fileLocation);
//
// switch(extension[0]) {
//     case 'c'  : {
//         if (extension == "csv") {
//             BuildAritistCsv(fileData);
//         }
//         break;
//     }
//
//     case 'x': {
//         if (extension == "xml") {
//             BuildAritistXml(fileLocation);
//         }
//         break;
//     }
//
//     case 't': {
//         if (extension == "txt") {
//             // BuildAritistTxt(fileLocation);
//         }
//         break;
//     }
//
//     default: {
//     }
// }
// }
