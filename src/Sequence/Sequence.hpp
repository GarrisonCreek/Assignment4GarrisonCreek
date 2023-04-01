// authors: Dr. H and Brandon Young
// compiled with g++ -std=c++1z Sequence.hpp
// This is a Sequence declaration based on NodeRecord.
// Sequence is represented as (<>), it is a linkedlist of NodeRecords.

//DO NOT CHANGE THIS CODE!

#include <iostream>
#include <cstdio>
#include "Sequence.h"
#include <sstream>

using namespace std;

template<class T>
Sequence<T>::Sequence() {
    head = NULL;
    size = 0;
}// Sequence

template<class T>
Sequence<T>::~Sequence() {
//    reclaimAllNodes(head);
    clear();
}// ~Sequence


template<class T>
void Sequence<T>::clear(void) {
//    reclaimAllNodes(head);
    head = NULL;
    size = 0;
}// clear

//template<class T>
//void Sequence<T>::reclaimAllNodes(NodeRecord *&initialP)
//// requires: Null(initialP)  or  Alive(initialP)
////  ensures: all nodes in linked list
////           beginning with initialP are reclaimed
//{
//    if (initialP != NULL) {
//        reclaimAllNodes(initialP->next);
//        delete (initialP);
//    }// end if
//}// reclaimAllNodes


template<class T>
void Sequence<T>::add(const T &x, int pos) {
    auto *NewRec = new NodeRecord;
    auto *temp = new NodeRecord;
    NewRec->value = x;
    NewRec->next = NULL;

    if (pos == 0) {
        NewRec->next = head;
        head = NewRec;
        size++;
    } else if (pos <= size) {
        temp = head;
        for (int i = 0; i < size - 1; i++) {
            temp = temp->next;
        }
        temp->next = NewRec;
        size++;
    }
}


template<class T>
void Sequence<T>::remove(const T &x, int pos) {

    NodeRecord *temp;
    temp = head;
    if (pos == 0) {
        head = temp->next;
        x = temp->value;
        size--;
    } else if (pos <= size) {
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        x = temp->next->value;
        temp->next = temp->next->next;
        size--;
    }
}

template<class T>
void Sequence<T>::entry(const T &x, int pos) {

    auto *temp = new NodeRecord;
    temp = head;

    if (pos == 0) {
        x = temp->value;
    }
    if (pos < size && pos > 0) {
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        x = temp->value;
    }
}

template<class T>
int Sequence<T>::length() {
    return size;
}

template<class T>
std::string Sequence<T>::output() {
    std::stringstream ss;
    NodeRecord *p = head;
    ss << "[";
    while (p != nullptr) {
        ss << p->value;
        if (p->next != nullptr) {
            ss << ", ";
        }
        p = p->next;
    }
    ss << "]";
    return ss.str();
}


template<class T>
void Sequence<T>::transferFrom(Sequence<T> &source) {
    head = source.head;
    size = source.size;
    source.head = NULL;
    source.size = 0;
}

template<class T>
Sequence<T> &Sequence<T>::operator=(Sequence &rhs) {
    clear();
    NodeRecord *temp;
    temp = rhs.head;
    T x;
    for (int i = 0; i < rhs.size; i++) {
        x = temp->value;
        add(x, i);
        temp = temp->next;
    }
    return *this;
}