#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    char c;
    fin.open("RomeoJuliet.txt");

    for(int i; i<10;i++){
        c=fin.get();
        cout << c;
    }

    fin.close();

    return 0;
}