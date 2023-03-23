//
// Created by Garrison Creek on 3/23/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_HASHMAP_H
#define ASSIGNMENT4GARRISONCREEK_HASHMAP_H

#include "../HashEntry/HashEntry.h"

template<class T>
class HashMap {
private:
    HashEntry<T> **map;
public:

    HashMap();

    ~HashMap();

    T get(T key);

    void put(T key, T value);

    // TODO: Implement the following methods, remove, and clear, maybe an add im not sure

//    void remove(T &key);

//    void output();

};


#endif //ASSIGNMENT4GARRISONCREEK_HASHMAP_H
