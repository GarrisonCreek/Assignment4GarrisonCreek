////
//// Created by Garrison Creek on 3/24/23.
////
//
//
//#include <fstream>
//#include<iostream>
//#include "../../src/Sequence/Sequence.hpp"
//
//using namespace std;
//
//typedef Sequence<AirportData> AirportSequence;
//
//void doInputPersonDataFromFile(AirportSequence &airData) {
//    string filename = "air16.dat";
//    ifstream infile(filename);
//    bool successful;
//    AirportData r;
//    int dataSize;
//
//    if (!infile) {
//        cout << "Unable to open file";
//        exit(1); // terminate with error
//    }
//    //input.openFile(filename, File::openForRead, successful);
//    if (infile.is_open()) {
//        // The first item in the data file is an integer
//        // it represents how many records are in the data file.
//        infile >> dataSize;
//        cout << "Number of Records :" << dataSize;
//        for (int j = 0; j < dataSize; j++) {
//            infile >> r.name;
//            infile >> r.address;
//
//            infile >> r.state;
//            infile >> r.zip;
//
//            airData.add(r, 0);
//        } // end for
//        infile.close();
//
//    } // end if
//
//} // doInputPersonDataFromFile>
//
//
//
////int main(int argc, char *argv[]) {
////
////    AirportSequence eSequence;
////
////    cout << "Reading AirportDatas from file" << endl;
////    doInputPersonDataFromFile(eSequence);
////    cout << "\nCompleted Reading, File contains following Employee Records" << endl;
////    eSequence.outputSequence();
////    cout << endl;
////
////    return 0;
////}
//
