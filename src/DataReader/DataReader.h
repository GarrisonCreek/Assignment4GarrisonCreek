//
// Created by Garrison Creek on 3/25/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_DATAREADER_H
#define ASSIGNMENT4GARRISONCREEK_DATAREADER_H


#include <string>

class DataReader {
private:

public:
    static void inputFile(const std::string& file); // creates map from a file
    void outputFile(); // outputs the map to a file

};


#endif //ASSIGNMENT4GARRISONCREEK_DATAREADER_H
