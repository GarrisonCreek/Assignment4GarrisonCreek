//
// Created by Garrison Creek on 3/25/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_AIRPORTRECORD_H
#define ASSIGNMENT4GARRISONCREEK_AIRPORTRECORD_H

#include <string>
#include <iostream>
#include <sstream>

class AirportRecord {
public:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latDeg;
    int latMin;
    int latSec;
    std::string latDir;
    int longDeg;
    int longMin;
    int longSec;
    std::string longDir;
    int altitude;

    AirportRecord() {}

    ~AirportRecord() {}

void clear(void) {
        code = "";
        name = "";
        city = "";
        country = "";
        latDeg = 0;
        latMin = 0;
        latSec = 0;
        latDir = "";
        longDeg = 0;
        longMin = 0;
        longSec = 0;
        longDir = "";
        altitude = 0;
    } // clear

AirportRecord &operator=(AirportRecord &rhs) {
        code = rhs.code;
        name = rhs.name;
        city = rhs.city;
        country = rhs.country;
        latDeg = rhs.latDeg;
        latMin = rhs.latMin;
        latSec = rhs.latSec;
        latDir = rhs.latDir;
        longDeg = rhs.longDeg;
        longMin = rhs.longMin;
        longSec = rhs.longSec;
        longDir = rhs.longDir;
        altitude = rhs.altitude;

        return *this;
    } // operator =

    std::string output() {
        std::stringstream ss;
        ss << "[";
        ss << code << ",";
        ss << name << ",";
        ss << city << ",";
        ss << country << ",";
        ss << latDeg << ",";
        ss << latMin << ",";
        ss << latSec << ",";
        ss << latDir << ",";
        ss << longDeg << ",";
        ss << longMin << ",";
        ss << longSec << ",";
        ss << longDir << ",";
        ss << altitude;
        ss << "]";
        return ss.str();
    }

void transferFrom(AirportRecord &source) {
        code = source.code;
        name = source.name;
        city = source.city;
        country = source.country;
        latDeg = source.latDeg;
        latMin = source.latMin;
        latSec = source.latSec;
        latDir = source.latDir;
        longDeg = source.longDeg;
        longMin = source.longMin;
        longSec = source.longSec;
        longDir = source.longDir;
        altitude = source.altitude;
    } // transferFrom

// overloading the output operator.The outputSequence function will make use
// of this. Must be friend becuse AirportRecord is not primitive type.
    friend std::ostream &operator<<(std::ostream &os, AirportRecord &r) {
        os << "(" << r.code << "," << r.name << "," << r.city << "," << r.country << "," << r.latDeg << "," << r.latMin << "," << r.latSec << "," << r.latDir << "," << r.longDeg << "," << r.longMin << "," << r.longSec << "," << r.longDir << "," << r.altitude << ")";
        return os;
    } // operator <<
};


#endif //ASSIGNMENT4GARRISONCREEK_AIRPORTRECORD_H
