//
// Created by Garrison Creek on 3/23/23.
//

#include <iostream>
#include "HashMap.h"

template<class K, class V>
HashMap<K, V>::HashMap() {
    map = new HashEntry<K, V> *[MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        map[i] = nullptr;
    }
}

template<class K, class V>
HashMap<K, V>::~HashMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        HashEntry<K, V> *entry = map[i];
        while (entry != nullptr) {
            HashEntry<K, V> *prev = entry;
            entry = entry->getNext();
            delete prev;
        }
    }
    delete[] map;
}

template<class K, class V>
V HashMap<K, V>::get(K key) {
//    int hashCode = (key % MAP_SIZE);
    int hash = hashCode(key);
    if (map[hash] == nullptr) {
        return V();
    } else {
        HashEntry<K, V> *temp = map[hash];
        while (temp != nullptr) {
            if (temp->getKey() == key) {
                return temp->getValue();
            }
            temp = temp->getNext();
        }
        return V();
    }
}

template<class K, class V>
void HashMap<K, V>::put(K key, V value) {
//    int hashCode = (key % MAP_SIZE);
    int hash = hashCode(key);
    auto *newEntry = new HashEntry<K, V>(key, value, nullptr);
    if (map[hash] == nullptr) {
        map[hash] = newEntry;
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
    }
}

template<class K, class V>
bool HashMap<K, V>::remove(K key) {
//    int hashCode = (key % MAP_SIZE);
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
                    return true;
                } else {
                    previous->getNext() = current->getNext();
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
void HashMap<K, V>::display() {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (map[i] != nullptr) {
            HashEntry<K, V> *entry = map[i];
            std::cout << "Bucket " << i << ": ";
            while (entry != nullptr) {
                std::cout << "(" << entry->getKey() << " , " << entry->getValue() << ")";
                entry = entry->getNext();
                if (entry != nullptr) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
        }
    }
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
