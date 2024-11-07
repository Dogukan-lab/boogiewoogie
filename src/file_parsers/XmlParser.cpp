//
// Created by doguk on 10/27/2024.
//

#include "XmlParser.hpp"

#include <iostream>
#include <pugixml.hpp>

std::vector<DataEntry> XMLParser::ParseData(std::vector<std::string> &data) {
    if(data.empty()) {
        return {};
    }
    //Setup pugixml
    pugi::xml_document document;

    std::string xml_data;
    for (const auto &line: data) {
        xml_data += line;
    }

    if (!document.load_string(xml_data.c_str())) {
        std::cerr << "Failed to parse XML data." << std::endl;
        return {};
    }

    //Parse canvas size
    pugi::xml_node canvas = document.child("canvas");

    DataEntry entry{DataEntry::GridSize};
    entry.AddEntry("rows", canvas.attribute("rows").as_string());
    entry.AddEntry("cols", canvas.attribute("rows").next_attribute().as_string());
    _entries.emplace_back(entry);

    //Parse tile types
    const pugi::xml_node tileTypes = canvas.child("nodeTypes");

    for (pugi::xml_node type = tileTypes.child("nodeType"); type; type = type.next_sibling("nodeType")) {
        //Make tile type
        DataEntry tileType{DataEntry::TileType};
        tileType.AddEntry("type", type.attribute("tag").as_string());
        tileType.AddEntry("r", type.attribute("red").as_string());
        tileType.AddEntry("g", type.attribute("green").as_string());
        tileType.AddEntry("b", type.attribute("blue").as_string());
        tileType.AddEntry("weight", type.attribute("weight").as_string());

        _entries.emplace_back(tileType);
    }

    //Parse tile
    pugi::xml_node nodes = document.child("canvas").child("nodes");
    //Recursive search though...
    for(pugi::xml_node node = nodes.first_child(); node; node = node.next_sibling()) {
        DataEntry tile{DataEntry::Tile};
        tile.AddEntry("type", node.name());
        tile.AddEntry("x", node.attribute("x").as_string());
        tile.AddEntry("y", node.attribute("y").as_string());

        _entries.emplace_back(tile);
    }

    return _entries;
}