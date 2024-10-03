//
// Created by hmkam on 03/10/2024.
//

#include "FileReader.hpp"

#include <iostream>

#include <fstream>
#include <string>

using namespace std;

string readFileIntoString(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }

    string content;
    string line;
    while (getline(file, line)) {
        content += line
                + "\n";
    }

    file.close();
    return content;
}


string FileReader::ReadFile(string fileLocation) {
    string content = readFileIntoString(fileLocation);
    return content;
}
