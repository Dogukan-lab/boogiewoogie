//
// Created by hmkam on 11/10/2024.
//

#ifndef XMLPARSER_HPP
#define XMLPARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Parser.hpp"
#include "../Builders/Builder.hpp"
#include "../pugixml/pugixml.hpp"  // for XML parsing

class XMLParser : public Parser {
public:
    XMLParser() = default;

    ~XMLParser() override = default;

    template<typename T>
    std::vector<T> Pars(const std::vector<std::string> &xml) {
        std::vector<T> result;
        //<T> tile; //todo: not use tile
        Tile tile;

        // Create a pugi::xml_document object
        pugi::xml_document doc;

        // Load the XML data from the vector of strings
        std::string xml_data = "";
        for (const auto &line: xml) {
            xml_data += line;
        }
        doc.load_string(xml_data.c_str());

        //

        //todo: use vector string
        if (!doc.load_file("D:/GitHub/boogiewoogie/Files/graph.xml")) return result;

        pugi::xml_node nodeTypes = doc.child("canvas").child("nodeTypes");

        std::vector<TileType> tileTypes; //todo: make persistand
        TileType tileType;

#////// nodeTypes //////
        for (pugi::xml_node nodeType = nodeTypes.child("nodeType"); nodeType;
             nodeType = nodeType.next_sibling("nodeType")) {
            tileType.name = nodeType.attribute("tag").as_string();
            tileType.rgb[0] = nodeType.attribute("red").as_int();
            tileType.rgb[1] = nodeType.attribute("green").as_int();
            tileType.rgb[2] = nodeType.attribute("blue").as_int();
            tileType.weight = nodeType.attribute("weight").as_int();

            tileTypes.push_back(tileType);
        }


#////// nodes //////
        pugi::xml_node nodes = doc.child("canvas").child("nodes");
        for (pugi::xml_node node = nodes.first_child(); node; node = node.next_sibling()) {
            std::shared_ptr<Tile> tile = std::make_shared<Tile>();
            // Set tile type by matching tag names (e.g., "Y", "R")
            for (const auto &tileType: tileTypes) {
                if (tileType.name == node.name()) {
                    tile->type = const_cast<TileType *>(&tileType); // Assign tile type
                    break;
                }
            }

            // Get position of the tile
            tile->position.x = node.attribute("x").as_int();
            tile->position.y = node.attribute("y").as_int();

            // Get edges and position of neighbours
            pugi::xml_node edges = node.child("edges");
            for (pugi::xml_node edge = edges.child("edge"); edge; edge = edge.next_sibling("edge")) {
                std::shared_ptr<Tile> neighbour = std::make_shared<Tile>();
                neighbour->position.x = edge.attribute("x").as_int();
                neighbour->position.y = edge.attribute("y").as_int();

                // Note: you may need to look up or assign the actual Tile object here if needed
                tile->neighbours.push_back(neighbour);
            }

            result.push_back(tile);
        }

        return result;
    }
};

#endif //XMLPARSER_HPP
