//
// Created by Garrison Creek on 3/23/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_HASHENTRY_H
#define ASSIGNMENT4GARRISONCREEK_HASHENTRY_H

#include <optional>
#include "../Sequence/Sequence.h"

template<class K, class V>
class HashEntry {
private:
    K key;
    V value;
    HashEntry<K, V> *next;

public:
    /**
     * Description: Constructor that initializes all attributes of this class.
     * replaces self
     * ensures: self = (<>,<>)
     * @param key
     * @param value
     */
    HashEntry(K key, V value, HashEntry<K, V> *next);

    /**
     * Description: Returns the key
     * @return key
     */
    K getKey();

    /**
     * Description: Returns the value
     * @return value
     */
    V getValue();

    /**
     * Description: Returns the next HashEntry
     * @return next
     */
    HashEntry<K, V> *&getNext();

};

#endif //ASSIGNMENT4GARRISONCREEK_HASHENTRY_H