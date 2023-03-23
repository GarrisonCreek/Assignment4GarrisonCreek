//
// Created by Garrison Creek on 3/23/23.
//

#include "HashMap.h"
const int TABLE_SIZE = 128;


template <class T>
HashMap<T>::HashMap() {
    map = new HashEntry<T>*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        map[i] = NULL;
    }
}

template<class T>
HashMap<T>::~HashMap() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (map[i] != NULL) {
            delete map[i];
        }
    }
    delete[] map;
}

template <class T>
T HashMap<T>::get(T key) {
    int hash = (key % TABLE_SIZE);
    while (map[hash] != NULL && map[hash]->getKey() != key)
        hash = (hash + 1) % TABLE_SIZE;
    if (map[hash] == NULL)
        return -1;
    else
        return map[hash]->getValue();
}

template <class T>
void HashMap<T>::put(T key, T value) {
    int hash = (key % TABLE_SIZE);
    while (map[hash] != NULL && map[hash]->getKey() != key)
        hash = (hash + 1) % TABLE_SIZE;
    if (map[hash] != NULL)
        delete map[hash];
    map[hash] = new HashEntry(key, value);
}