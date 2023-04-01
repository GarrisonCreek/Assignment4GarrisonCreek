//
// Created by Garrison Creek on 3/23/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_HASHMAP_H
#define ASSIGNMENT4GARRISONCREEK_HASHMAP_H

#include "../HashEntry/HashEntry.h"

template<class K, class V>
class HashMap {
private:
    HashEntry<K, V> **map;

public:
    const int MAP_SIZE = 128;

    HashMap();

    ~HashMap();

    /**
     * Description: Returns the value of the key
     * @param key
     * @return
     */
    V get(K key);

    void put(K key, V value);

    // TODO: Implement the following methods, remove, and clear, maybe an add im not sure

    bool remove(K key);

    std::string display();

    int hashCode(K key);

};

#endif //ASSIGNMENT4GARRISONCREEK_HASHMAP_H