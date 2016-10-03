/*
The size in bytes of various data types
varies from computer to computer.
Write a bool function floatBiggerThanInt() that
returns true if a float on your computer
require more bytes of memory than an int.

You should not use cin or cout in your function.
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ToDo:  write your code below this line
bool floatBiggerThanInt(){
    int a;
    float b;
    if (sizeof(a) < sizeof(b)) {
        return true;
    } else if (sizeof(a) >= sizeof(b)) {
        return false;
    }
}
// make no changes below this line

int main(){
        cout << floatBiggerThanInt() << endl;
        cout << "On this computer, a float is ";
        if (!floatBiggerThanInt())cout<< "not ";
        cout << "bigger than an int.\n";
        return 0;
}

