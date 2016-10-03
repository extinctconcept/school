#include <iostream>
using namespace std;

static int numCandy =500;

void whatsInTheCandyMachine();
void scopeMachine();
void stringSpitter(string s);

int main(void){
    string s = "Do a barrel roll!!";
    whatsInTheCandyMachine();
    //num candy equals 8000000
    scopeMachine();
    stringSpitter(s);
    cout << s << endl;
    return 0;
}

void whatsInTheCandyMachine(){
    cout << "you make a quick glance at the machine and find that there are " << numCandy << " in the candy machine" << endl;
}

void scopeMachine(){
    cout << numCandy << " is definitely a number." << endl;
    static int numCandy = 12;
    cout << "you make a quick glance at the machine and find that there are " << numCandy << " in the candy machine" << endl;

}

void stringSpitter(string s){
    cout << "You passed in the string \"" << s << "\""<<endl;
    s = "whoops";
}