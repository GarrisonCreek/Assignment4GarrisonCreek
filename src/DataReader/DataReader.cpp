//
// Created by Garrison Creek on 3/25/23.
//

#include "DataReader.h"

#include <iostream>
#include <fstream>
#include "../Sequence/Sequence.h"
#include "../HashMap/HashMap.cpp"
#include "../HashEntry/HashEntry.cpp"
#include <cstdlib>


void DataReader::inputFile(const std::string &file) { // creates map from a file
    HashMap<std::string, Sequence<std::string>> hm = HashMap<std::string, Sequence<std::string>>();
    Sequence<std::string> seq = Sequence<std::string>();
    std::string line;
    std::ifstream inFile(file);
    if (inFile.is_open()) {
        std::getline(inFile, line);
        while (inFile) {
            std::getline(inFile, line);
            std::size_t doubleSpace = line.find("  ");
            while (doubleSpace != std::string::npos)
            {
                line.erase(doubleSpace, 1);
                doubleSpace = line.find("  ");
            }
            auto key = line.substr(0, line.find(' '));
            string parsedLine;
            for (char i : line) {
                if (i == ' ') {
                    seq.add(parsedLine, seq.length());
                    parsedLine = "";
                } else {
                    parsedLine += i;
                }
            }
            hm.put(key, seq);
            seq.clear();

        }
    } else {
        std::cout << "Unable to open file";
    }
    // TODO: add key and value to map
    hm.display();
}


void outputFile() { // outputs the map to a file

}
