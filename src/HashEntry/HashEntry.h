//
// Created by Garrison Creek on 3/23/23.
//

#ifndef ASSIGNMENT4GARRISONCREEK_HASHENTRY_H
#define ASSIGNMENT4GARRISONCREEK_HASHENTRY_H

#include <optional>

template<class T>
class HashEntry {
private:
    T key;
    T value;
public:

    /**
     * Description: Constructor that initializes all attributes of this class.
     * replaces self
     * ensures: self = (<>,<>)
     * @param key
     * @param value
     */
    HashEntry(T key, T value);

    /**
     * Description: Returns the key
     * @return key
     */
    T getKey();

    /**
     * Description: Returns the value
     * @return value
     */
    T getValue();

};

#endif //ASSIGNMENT4GARRISONCREEK_HASHENTRY_H