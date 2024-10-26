//
// Created by doguk on 10/25/2024.
//

#ifndef DATAENTRY_HPP
#define DATAENTRY_HPP
#include <string>
#include <unordered_map>

struct DataEntry {
    std::unordered_map<std::string, std::string> entries;

    void AddEntry(const std::string& tag, const std::string& data) {
        entries[tag] = data;
    }

    std::string& operator[](const std::string& tag) {
        return entries[tag];
    }

};

#endif //DATAENTRY_HPP
