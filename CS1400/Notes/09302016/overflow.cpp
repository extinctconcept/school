#include <iostream>
#include <iomanip>
using namespace std;

// #define is a text replacement not storing any data
//#define MAXVAL 100
const int MAXVAL='b';

double factorial(int  n){
    double answer = 1;
    for (int i = 1; i<=n; i++){
        answer *= i;
    }
    return answer;
}


int main (){
    for(int i = 1; i<=MAXVAL; i++){
    cout << i <<": " <<factorial(i)<< endl;
    }
    return 0;
}