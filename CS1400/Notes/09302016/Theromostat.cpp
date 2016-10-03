#include <iostream>
#include <iomanip>

using namespace std;

void printLine(int lineNum, int curTemp, int setTemp){
    cout << setw(14) <<"Current Temp > ";
    cout << lineNum;
    cout << left << setw(14) << "< Set Temp";
    cout << endl;
}

void printScreen(int curTemp, int setTemp){
    for(int i = 30; i<=85; i+=5 ){
        printLine(i, curTemp, setTemp);
}
}
int main (){
    printScreen(45,60);
    return 0;
}