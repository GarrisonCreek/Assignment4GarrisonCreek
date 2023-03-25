#include "HashMap/HashMap.cpp"
#include "HashEntry/HashEntry.cpp"
#include "Sequence/Sequence.h"
#include "DataReader/DataReader.h"

using namespace std; // TODO: remove this line

int main() {
    HashMap<string, Sequence<int>> hm = HashMap<string, Sequence<int>>();

//    auto s1 = Sequence<int>();
//    int x = 1;
//    s1.add(x, s1.length());
//    x = 2;
//    s1.add(x, s1.length());
//    x = 3;
//    s1.add(x, s1.length());
//
//    auto s2 = Sequence<int>();
//    x = 4;
//    s2.add(x, s2.length());
//    x = 5;
//    s2.add(x, s2.length());
//    x = 6;
//    s2.add(x, s2.length());
//    hm.put("test", s1);
//    hm.put("key", s2);
//    hm.put("hello", s2);
//    hm.put("201", s2);
//    s1.add(x, s1.length());
//    hm.put("new Key", s1);
//
//    hm.display();

    DataReader dr = DataReader();
    dr.inputFile("/Users/garrison/CLionProjects/Assignment4GarrisonCreek/Data/air16.txt");
    return 0;
}