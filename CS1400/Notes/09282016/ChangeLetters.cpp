#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    ofstream fout;
    char c;
    fin.open("RomeoJuliet.txt");
    fout.open("JesusNstuff.txt");

    while(!fin.eof()){
        c=fin.get();
        // this will capitalize all of the letters on the output.
        if (c =='a')c = '0';
        if (c == 'T' || c == 't') c='w';
        if(!fin.eof()) fout << c;
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}