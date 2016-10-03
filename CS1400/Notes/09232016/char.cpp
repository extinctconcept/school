#include <iostream>
using namespace std;

int main(){
    char c;
    char capC;
    int n;

    c='a';
    while(c <= 'z'){
        n=c;
        capC = c + ('A' - 'a');
        cout << c << " : " << capC << " : " << n << endl;
        c++;
    }

    return 0;
}