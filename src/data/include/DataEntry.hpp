//
// Created by doguk on 10/25/2024.
//

#ifndef DATAENTRY_HPP
#define DATAENTRY_HPP
#include <string>
#include <unordered_map>

//TODO make the second part of map a std::variant of int,float,string,vector<type>
struct DataEntry {
    enum EntryTag {
        Artist,
        Tile,
        TileType,
        Dimensions
    };

    EntryTag tag;
    std::unordered_map<std::string, std::string> entries;

    void AddEntry(const std::string &tag, const std::string &data) {
        entries[tag] = data;
    }

    const std::string &operator[](const std::string &tag){
        return entries.at(tag);
    }
};

#endif //DATAENTRY_HPP
