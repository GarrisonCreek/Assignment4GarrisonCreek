#include <iostream>
#include "HashMap/HashMap.cpp"
#include "HashEntry/HashEntry.cpp"
#include "Sequence/Sequence.h"

using namespace std; // TODO: remove this line

void inputFile(){ // creates map from a file

}
void outputFile(){ // outputs the map to a file

}

int main() {
    HashMap<int, Sequence<int>> hm = HashMap<int, Sequence<int>>();

    auto s1 = Sequence<int>();
    int x = 1;
    s1.add(x, s1.length());
    x = 2;
    s1.add(x, s1.length());
    x = 3;
    s1.add(x, s1.length());

    auto s2 = Sequence<int>();
    x = 4;
    s2.add(x, s2.length());
    x = 5;
    s2.add(x, s2.length());
    x = 6;
    s2.add(x, s2.length());

    hm.put(1, s1);
    hm.put(5, s2);
    hm.put(101, s2);
    hm.put(201, s2);
    s1.add(x, s1.length());
    hm.put(2, s1);

    hm.display();

    return 0;
}