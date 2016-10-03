#include <iostream>
using namespace std;

int main(){
    int i;
    float discountRate;
    cin >> i;
    if(i>500){
        discountRate = 0.2;
        cout << "Your discount is " << discountRate * 100 << '%' << endl;
    }
    return 0;
}