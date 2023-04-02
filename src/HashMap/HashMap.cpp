//
// Created by Garrison Creek on 3/23/23.
//

#include <iostream>
#include "HashMap.h"
#include "../Sequence/Sequence.hpp"

template<class K, class V>
HashMap<K, V>::HashMap() {
    map = new HashEntry<K, V> *[MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        map[i] = nullptr;
    }
    size;
}

template<class K, class V>
HashMap<K, V>::~HashMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (map[i] != nullptr) {
            HashEntry<K, V> *prevEntry = nullptr;
            HashEntry<K, V> *entry = map[i];
            while (entry != nullptr) {
                prevEntry = entry;
                entry = entry->getNext();
                delete prevEntry;
            }
        }
    }
    size;
    delete[] map;
}

template<class K, class V>
V HashMap<K, V>::get(K key) {
    int hash = hashCode(key);
    if (map[hash] == nullptr) {
        return nullptr;
    } else {
        HashEntry<K, V> *temp = map[hash];
        while (temp != nullptr) {
            if (temp->getKey() == key) {
                return temp->getValue();
            }
            temp = temp->getNext();
        }
        return nullptr;
    }
}

template<class K, class V>
bool HashMap<K, V>::containsKey(K key) {
    int hash = hashCode(key);
    if (map[hash] == nullptr) {
        return false;
    } else {
        HashEntry<K, V> *temp = map[hash];
        while (temp != nullptr) {
            if (temp->getKey() == key) {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }
}

template<class K, class V>
void HashMap<K, V>::put(K key, V value) {
    int hash = hashCode(key);
    auto *newEntry = new HashEntry<K, V>(key, value, nullptr);
    if (map[hash] == nullptr) {
        map[hash] = newEntry;
        size++;
    } else {
        HashEntry<K, V> *previous = nullptr;
        HashEntry<K, V> *current = map[hash];
        while (current != nullptr) {
            if (current->getKey() == key) {
                if (previous == nullptr) {
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
        size++;
    }
}


template<class K, class V>
bool HashMap<K, V>::remove(K key) {
    int hash = hashCode(key);
    if (map[hash] == nullptr) {
        return false;
    } else {
        HashEntry<K, V> *previous = nullptr;
        HashEntry<K, V> *current = map[hash];
        while (current != nullptr) {
            if (current->getKey() == key) {
                if (previous == nullptr) {
                    map[hash] = map[hash]->getNext();
                    size--;
                    return true;
                } else {
                    previous->getNext() = current->getNext();
                    size--;
                    return true;
                }
            }
            previous = current;
            current = current->getNext();
        }
        return false;
    }
}

template<class K, class V>
int HashMap<K, V>::getSize() {
    return size;
}

template<class K, class V>
std::string HashMap<K, V>::display() {
    std::stringstream ss;
    for (int i = 0; i < MAP_SIZE; i++) {
        if (map[i] != nullptr) {
            HashEntry<K, V> *entry = map[i];
            ss << "Bucket " << i << ": ";
            while (entry != nullptr) {
                // in format - Bucket 0: (key, value) -> (key, value) -> (key, value)
                ss << "(key = " << entry->getKey() << ", value = " << entry->getValue().output() << ")";
                entry = entry->getNext();
                if (entry != nullptr) {
                    ss << " -> ";
                }
            }
            ss << std::endl;
        }
    }
    return ss.str();
}

template<class K, class V>
int HashMap<K, V>::hashCode(K key) {
    if constexpr (std::is_same_v<K, std::string>) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (31 * hash + key[i]) % MAP_SIZE;
        }
        return hash;
    } else if constexpr (std::is_same_v<K, int>) {
        return key % MAP_SIZE;
    }
}
