#include <iostream>
#include "HashMap/HashMap.h"
#include "HashMap/HashMap.cpp"
#include "HashEntry/HashEntry.cpp"
#include "Sequence/Sequence.hpp"      // TODO: fix these two include lines

using namespace std; // TODO: remove this line

void inputFile(){ // creates map from a file

}
void outputFile(){ // outputs the map to a file

}

int main() {
    HashMap<int, int> hm;
    hm.put(3, 23);
    hm.put(5, 100);
    hm.put(2, 200);
    hm.put(10, 300);
    cout << "Value of key = 5, is " << hm.get(5) << endl;
//    hm.put(x, y);
//    cout << "override an existing entry of (3, 23) with (3,123)" << endl;
//    hm.put(x, y);
//    cout << "New value of key = 3, is " << hm.get(x) << endl;

    HashMap<string, string> hm2;
    hm2.put("a", "Hello");
    hm2.put("two", "World");
    hm2.put("three", "!");
    hm2.put("pie", "Haha I overrode you");
    hm2.put("zzz", "Im sharing this bucket with 3");
//    hm2.remove(5);
    cout << "Value of key = 5, is " << hm2.get("zzz") << endl;
    hm2.display();

    return 0;
}