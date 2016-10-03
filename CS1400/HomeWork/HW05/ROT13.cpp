/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 5
***********************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    ifstream input;
    ofstream output;
    char c;
    input.open("secretMessage.txt");
    output.open("decodedMessage.txt");

    while ( !input.eof() ){
        c = input.get();

        if ( c >= 'a' && c <= 'm' ){
            c -= 'a' - 'n';
             } else if ( c > 'm' && c <= 'z' ){
                char e;
                char m;
                char s = 'a';
                e = 'z' - c;
                m = 'm' - 'a';
                m -= e;
                s += m;
                c = s;

            } else if ( c >= 'A' && c <= 'M' ){
            c -= 'A' - 'N';
        } else if ( c > 'M' && c <= 'Z' ){
                char E;
                char M;
                char S = 'A';
                E = 'Z' - c;
                M = 'M' - 'A';
                M -= E;
                S += M;
                c = S;
        }
        if (!input.eof()) output << c;
    }

    input.close();
    output.close();

    return 0;
}