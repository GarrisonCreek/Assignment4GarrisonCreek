cmake_minimum_required(VERSION 3.24)
project(Assignment4GarrisonCreek)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(Hash src/main.cpp src/HashEntry/HashEntry.cpp src/HashMap/HashMap.cpp src/HashEntry/HashEntry.h src/HashMap/HashMap.h)

# Add include directories
target_include_directories(Hash PRIVATE src/HashEntry src/HashMap)