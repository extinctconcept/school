#include <iostream>
#include <cstring>

using namespace std;

bool  carPasses(int lPPM, int yPPM, string mk){
    bool passes = false;
    if(lPPM>=yPPM) passes = true;
    if(mk=="Volkswagen") passes = true;
    return passes;

}


int main(){
    int legalPPM;
    int yourPPM;
    string make;

    cout << "What is the legal emissions level in PPM? ";
    cin >> legalPPM;
    cout << "What is your emmisions level in PPM? ";
    cin >> yourPPM;
    cout << "What is your make of car? ";
    cin >> make;

    if (carPasses(legalPPM, yourPPM, make)) {
        cout << "you passed!\n";
    } else {
        cout << "You shall not pass!\n";
    };

    return 0;
}