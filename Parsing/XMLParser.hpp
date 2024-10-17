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
    std::vector<std::shared_ptr<T> > Pars(const std::vector<std::string> &xml) {
        std::vector<std::shared_ptr<T> > result;

        // Create a pugi::xml_document object
        pugi::xml_document doc;

        // Combine the XML data from the vector of strings
        std::string xml_data;
        for (const auto &line: xml) {
            xml_data += line;
        }

        // Load the XML data from the combined string
        if (!doc.load_string(xml_data.c_str())) {
            std::cerr << "Failed to parse XML data." << std::endl;
            return result;
        }

        pugi::xml_node nodeTypes = doc.child("canvas").child("nodeTypes");

        std::vector<std::shared_ptr<TileType> > tileTypes; //todo: set global tiletypes
        std::shared_ptr<TileType> tileType;

#////// nodeTypes //////
        for (pugi::xml_node nodeType = nodeTypes.child("nodeType"); nodeType;
             nodeType = nodeType.next_sibling("nodeType")) {
            tileType = std::make_shared<TileType>();
            tileType->name = nodeType.attribute("tag").as_string();
            tileType->rgb[0] = nodeType.attribute("red").as_int();
            tileType->rgb[1] = nodeType.attribute("green").as_int();
            tileType->rgb[2] = nodeType.attribute("blue").as_int();
            tileType->weight = nodeType.attribute("weight").as_int();

            tileTypes.push_back(tileType);
        }


#////// nodes //////
        pugi::xml_node nodes = doc.child("canvas").child("nodes");
        for (pugi::xml_node node = nodes.first_child(); node; node = node.next_sibling()) {
            std::shared_ptr<T> tile = std::make_shared<T>();
            // Set tile type by matching tag names (e.g., "Y", "R")
            for (const auto &_tileType: tileTypes) {
                if (_tileType->name == node.name()) {
                    tile->type = *const_cast<std::shared_ptr<TileType> *>(&_tileType); // Assign tile type
                    break;
                }
            }

            // Get position of the tile
            tile->position.x = node.attribute("x").as_int();
            tile->position.y = node.attribute("y").as_int();

            // Get edges and position of neighbours
            pugi::xml_node edges = node.child("edges");
            for (pugi::xml_node edge = edges.child("edge"); edge; edge = edge.next_sibling("edge")) {
                std::shared_ptr<T> neighbour = std::make_shared<T>();
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
