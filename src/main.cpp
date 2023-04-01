#include "HashMap/HashMap.cpp"
#include "HashEntry/HashEntry.cpp"
#include "Sequence/Sequence.h"
#include "DataReader/DataReader.h"
#include "AirportRecord/AirportRecord.h"

using namespace std; // TODO: remove this line

int main() {


    DataReader dr = DataReader();
    auto hm = dr.inputAirportDataFromFile("/Users/garrison/CLionProjects/Assignment4GarrisonCreek/Data/AirportData/air128.dat");
    hm.display();
    cout << "-------------------------------------------" << endl;
    auto hm2 = dr.inputAirportDataFromFile("/Users/garrison/CLionProjects/Assignment4GarrisonCreek/Data/AirportData/air16.dat");
    hm2.display();
    //TODO: implement a file putter to put data into a file
    return 0;
}