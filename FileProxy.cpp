//
// Created by hmkam on 03/10/2024.
//

#include "FileProxy.hpp"

#include "FileReader.hpp"
#include "WebReader.hpp"

std::string FileProxy::ReadFile(std::string fileLocation) {
    if (fileLocation == "web") {
        WebReader fileReader;
        return fileReader.ReadFile(fileLocation);
    }

    FileReader fileReader;
    return fileReader.ReadFile(fileLocation);
}
