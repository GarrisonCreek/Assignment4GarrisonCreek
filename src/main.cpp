#include <iostream>
#include "HashMap/HashMap.h"
using namespace std; // TODO: remove this line

int main(){
    HashMap<int> hm;
    int x = 3, y = 23;  // TESTING PURPOSES 
    hm.put(x, y);
    x = 5, y = 2377;  // TESTING PURPOSES
    hm.put(x, y);
    x = 9, y = 263;  // TESTING PURPOSES
    hm.put(x, y);
    x = 3;  // TESTING PURPOSES
    cout<<"Value of key = 3, is "<<hm.get(x)<<endl;
    x = 12, y = 230;  // TESTING PURPOSES
    hm.put(x, y);
    cout<<"override an existing entry of (3, 23) with (3,123)" <<endl;
    x = 3, y = 123;  // TESTING PURPOSES
    hm.put(x, y);
    x = 3;  // TESTING PURPOSES
    cout<<"New value of key = 3, is "<<hm.get(x)<<endl;
}
