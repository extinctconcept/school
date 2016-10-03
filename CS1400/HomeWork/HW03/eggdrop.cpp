/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 3
***********************/

#include <math.h>
#include <iostream>

using namespace std;


float GetT(float v, float d){
    float t;
    t = d/v;
    return t;
}
float GetD(float v, float h){
    float d;
    d = v*sqrt(2.0*h/9.8);
    return d;
}


int main(){
    float d, v, h, t;

    v = 30; h = 100;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 40; h = 100;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 50; h = 100;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 50; h = 200;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 50; h = 300;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 50; h = 400;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 50; h = 500;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    v = 200; h = 10000;
    d = GetD(v, h);
    t = GetT(v, d);
    cout << "v = " << v << "     ";
    cout << "h = " << h << "     ";
    cout << "d = " << d << "     ";
    cout << "t = " << t << endl;

    return 0;
}

