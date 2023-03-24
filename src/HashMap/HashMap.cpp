//
// Created by Garrison Creek on 3/23/23.
//

#include "HashMap.h"

template<class K, class V>
HashMap<K,V>::HashMap() {
    map = new HashEntry<K,V> *[MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        map[i] = nullptr;
    }

}

template<class K, class V>
HashMap<K, V>::~HashMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        HashEntry<K, V>* entry = map[i];
        while (entry != nullptr) {
            HashEntry<K, V>* prev = entry;
            entry = entry->getNext();
            delete prev;
        }
    }
    delete[] map;
}

template<class K, class V>
V HashMap<K,V>::get(K key) {
    int hash = (key % MAP_SIZE);
    while (map[hash] != NULL && map[hash]->getKey() != key)
        hash = (hash + 1) % MAP_SIZE;
    if (map[hash] == NULL) {
        return -1;
    } else {
        return map[hash]->getValue();
    }
}

template<class K, class V>
void HashMap<K,V>::put(K key, V value) {
    int hash = (key % MAP_SIZE); // make a hash function
    auto *newEntry = new HashEntry<K,V>(key, value, nullptr);
    if(map[hash] == nullptr) {
        map[hash] = newEntry;
    } else {
        HashEntry<K,V> *previous = nullptr;
        HashEntry<K,V> *current = map[hash];

        while(current != nullptr) {
            if(current->getKey() == key) {
                if(previous == nullptr) {
                    newEntry->getNext() = current->getNext();
                    map[hash] = newEntry;
                    return;
                } else {
                    newEntry->getNext() = current->getNext();
                    previous->getNext() = newEntry;
                    return;
                }
            }
            previous = current;
            current = current->getNext();
        }
        previous->getNext() = newEntry;
    }
}