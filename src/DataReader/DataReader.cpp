//
// Created by Garrison Creek on 3/25/23.
//

#include "DataReader.h"

#include <iostream>
#include "../HashMap/HashMap.cpp"
#include "../HashEntry/HashEntry.cpp"

#include <fstream>
using std::ifstream;
#include <cstdlib>

HashMap<string, AirportRecord> DataReader::inputAirportDataFromFile(const std::string &filename) { // creates map from a file
    ifstream file;
    file.open(filename);
    int dataSize;
    string line;
    AirportRecord ar = AirportRecord();
    HashMap<string, AirportRecord> hm = HashMap<string, AirportRecord>();
    if (file.is_open()) {
        file >> dataSize;
        std::cout << "dataSize: " << dataSize << std::endl;
        for (int i = 0; i < dataSize; i++) {
            file >> ar.code;
            file >> ar.name;
            file >> ar.city;
            file >> ar.country;
            file >> ar.latDeg;
            file >> ar.latMin;
            file >> ar.latSec;
            file >> ar.latDir;
            file >> ar.longDeg;
            file >> ar.longMin;
            file >> ar.longSec;
            file >> ar.longDir;
            file >> ar.altitude;
            hm.put(ar.code, ar);
        }
        file.close();
    } else {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    return hm;
}

void DataReader::outputFile(std::string &filename, HashMap<std::string, AirportRecord> hm) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        auto printer = hm.display();
        file << hm.display();



        file.close();
    } else {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

}
