#include "HashMap/HashMap.cpp"
#include "HashEntry/HashEntry.cpp"
#include "DataReader/DataReader.h"
#include "AirportRecord/AirportRecord.h"

int main() {
    //air 16 data
    auto hm = DataReader::inputAirportDataFromFile(
            "/Users/garrison/CLionProjects/Assignment4GarrisonCreek/InputData/AirportData/air16.dat");
    std::cout << "air16.dat" << std::endl;
    std::cout << "Record Count: " << hm.getSize() << std::endl;
    if(hm.containsKey("YWG")){
        std::cout << "Map contains key YWG" << std::endl;
    } else {
        std::cout << "Map does not contain key YWG" << std::endl;
    }
    if(hm.containsKey("CMB")){
        std::cout << "Map contains key CMB" << std::endl;
    } else {
        std::cout << "Map does not contain key CMB" << std::endl;
    }
    if(hm.containsKey("HND")){
        std::cout << "Map contains key HND" << std::endl;
    } else {
        std::cout << "Map does not contain key HND" << std::endl;
    }
    hm.remove("HND");
    std::cout << "Key HND removed" << std::endl;
    std::cout << "Record Count: " << hm.getSize() << std::endl;
    DataReader::outputFile(
            (string &) "/Users/garrison/CLionProjects/Assignment4GarrisonCreek/OutputData/output16file.txt", hm);
    //air 128 data
    auto hm2 = DataReader::inputAirportDataFromFile(
            "/Users/garrison/CLionProjects/Assignment4GarrisonCreek/InputData/AirportData/air128.dat");
    std::cout << "air128.dat" << std::endl;
    std::cout << "Record Count: " << hm2.getSize() << std::endl;
    if(hm2.containsKey("YWG")){
        std::cout << "Map contains key YWG" << std::endl;
    } else {
        std::cout << "Map does not contain key YWG" << std::endl;
    }
    if(hm2.containsKey("CMB")){
        std::cout << "Map contains key CMB" << std::endl;
    } else {
        std::cout << "Map does not contain key CMB" << std::endl;
    }
    if(hm2.containsKey("HND")){
        std::cout << "Map contains key HND" << std::endl;
    } else {
        std::cout << "Map does not contain key HND" << std::endl;
    }
    hm2.remove("HND");
    std::cout << "Key HND removed" << std::endl;
    std::cout << "Record Count: " << hm2.getSize() << std::endl;
    DataReader::outputFile(
            (string &) "/Users/garrison/CLionProjects/Assignment4GarrisonCreek/OutputData/output128file.txt", hm2);
    return 0;
}