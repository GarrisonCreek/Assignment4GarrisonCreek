#include "HashMap/HashMap.cpp"
#include "HashEntry/HashEntry.cpp"
#include "DataReader/DataReader.h"
#include "AirportRecord/AirportRecord.h"

using namespace std; // TODO: remove this line

int main() {


    DataReader dr = DataReader();
    auto hm = DataReader::inputAirportDataFromFile(
            "/Users/garrison/CLionProjects/Assignment4GarrisonCreek/InputData/AirportData/air16.dat");
    cout << hm.display();
    cout << "-------------------------------------------" << endl;
    DataReader::outputFile(
            (string &) "/Users/garrison/CLionProjects/Assignment4GarrisonCreek/OutputData/outputfile.txt", hm);
    //TODO: implement a file putter to put data into a file
    return 0;
}