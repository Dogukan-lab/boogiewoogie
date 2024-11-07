//
// Created by doguk on 10/25/2024.
//

#ifndef DATAENTRY_HPP
#define DATAENTRY_HPP
#include <string>
#include <unordered_map>

struct DataEntry {
    enum EntryTag {
        Artist,
        Tile,
        TileType,
        GridSize
    };

    EntryTag tag;
    std::unordered_map<std::string, std::string> entries;

    void AddEntry(const std::string &key, const std::string &data) {
        entries[key] = data;
    }

    const std::string &operator[](const std::string &key){
        return entries.at(key);
    }
};

#endif //DATAENTRY_HPP