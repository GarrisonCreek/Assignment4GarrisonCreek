cmake_minimum_required(VERSION 3.24)
project(Assignment4GarrisonCreek)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(Hash src/main.cpp src/HashEntry/HashEntry.cpp src/HashMap/HashMap.cpp src/HashEntry/HashEntry.h src/HashMap/HashMap.h src/Sequence/Sequence.hpp src/Sequence/Sequence.h src/DataReader/DataReader.cpp src/DataReader/DataReader.h)

# Add include directories