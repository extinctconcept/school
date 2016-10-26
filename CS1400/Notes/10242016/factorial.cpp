#include <iostream>
using namespace std;

int fact(int n){
    if (n==1)return 1;
    return n*fact(n-1);
}

int main (){
    for (int i = 1; i < 10; i++){
        cout << i << " " << fact(i) << endl;
    }
    return 0;
}