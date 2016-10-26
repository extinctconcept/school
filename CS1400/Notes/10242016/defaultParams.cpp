#include <iostream>

using namespace std;

void whatzit(int foo = 42){
    // default value for foo is 42. It is what gets returned when nothing is handed to the function.
    cout << foo << endl;
    return;
}

int main (){
    whatzit(34);
    whatzit();
    return 0;
}