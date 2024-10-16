//
// Created by hmkam on 03/10/2024.
//

#ifndef FILEPROXY_HPP
#define FILEPROXY_HPP
#include <string>
#include <vector>


class FileProxy {
public:
    std::vector<std::string> ReadFile(std::string fileLocation);
};


#endif //FILEPROXY_HPP
