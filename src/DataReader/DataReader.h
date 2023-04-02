//
// Created by Garrison Creek on 3/25/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_DATAREADER_H
#define ASSIGNMENT4GARRISONCREEK_DATAREADER_H


#include <string>
#include "../AirportRecord/AirportRecord.h"
#include "../HashMap/HashMap.h"

class DataReader {
private:

public:
    static HashMap<std::string, AirportRecord> inputAirportDataFromFile(const std::string& filename); // creates map from a file
    static void outputFile(std::string& filename, HashMap<std::string, AirportRecord> &hm); // outputs the map to a file

};


#endif //ASSIGNMENT4GARRISONCREEK_DATAREADER_H
