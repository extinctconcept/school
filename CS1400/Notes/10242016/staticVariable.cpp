#include <iostream>

using namespace std;

unsigned int myRand(){
    static int seed = 42;
    seed = seed * 87893728937/749274839 % 4324;
    return seed;
}

void whatzit(){
    static int foobar = 42;
    foobar++;
    cout << foobar << endl;
    return;
}

int main (){
    whatzit();
    whatzit();
    cout << myRand() << endl;
    cout << myRand() << endl;
    cout << myRand()%6+1 << endl;
    cout << myRand()%6+1 << endl;
    return 0;
}