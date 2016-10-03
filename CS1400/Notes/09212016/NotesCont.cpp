#include <iostream>
using namespace std;



void printSail(int n){
    int i;
    i=0;
    while(i<n){
        int j = 0;
        while(j<=i){
            cout<<"*";
            i++;
            j++;
        }
        cout << endl;
        i++;
    }
}

int main(){
    printSail(7);
    return 0;
}