//
// Created by Garrison Creek on 3/23/23.
//

#include "HashEntry.h"

template<class K, class V>
HashEntry<K, V>::HashEntry(K key, V value, HashEntry<K, V> *next) {
    this->key = key;
    this->value = value;
    this->next = next;
}

template<class K, class V>
K HashEntry<K, V>::getKey() {
    return key;
}

template<class K, class V>
V HashEntry<K, V>::getValue() {
    return value;
}

template<class K, class V>
HashEntry<K, V> *&HashEntry<K, V>::getNext() {
    return next;
}