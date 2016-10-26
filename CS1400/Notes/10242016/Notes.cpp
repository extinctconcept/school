#include <iostream>

using namespace std;

int foobar;

void watzit(){
    cout << foobar << endl;
    return;
}

int main (){
    foobar = 42;
    watzit();
    return 0;
}