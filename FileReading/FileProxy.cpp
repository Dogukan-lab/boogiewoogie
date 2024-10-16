//
// Created by hmkam on 03/10/2024.
//

#include "FileProxy.hpp"

#include "FileReader.hpp"
#include "WebReader.hpp"

std::vector<std::string> FileProxy::ReadFile(std::string fileLocation) {
    if (fileLocation == "web") {
        WebReader fileReader;
        return fileReader.openFile(fileLocation);
    }

    FileReader fileReader;
    return fileReader.openFile(fileLocation);
}
