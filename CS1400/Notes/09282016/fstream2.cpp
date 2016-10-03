#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    char c;
    fin.open("RomeoJuliet.txt");

    while(!fin.eof()){
        c=fin.get();
        // this will capitalize all of the letters on the output.
        if (c >='a' && c <= 'Z')c-='a'-'A';
        if(!fin.eof()) cout << c;
    }
    cout << endl;

    fin.close();

    return 0;
}