//
// Created by Garrison Creek on 3/23/23.
//

#include "HashEntry.h"

template <class T>
HashEntry<T>::HashEntry(T key, T value) {
    this->key = key;
    this->value = value;
}

template <class T>
T HashEntry<T>::getKey() {
    return key;
}

template <class T>
T HashEntry<T>::getValue() {
    return value;
}
