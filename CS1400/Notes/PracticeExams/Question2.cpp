/*
Write a void fuction stars(int n) that accepts
an int n as an input parameter and then prints
an nxn parallelogram of stars with n lines using
cout, where each line consists of <line number>
spaces followed by n stars.

Remember that line numbers start counting at
0.

Your output should look like this for n=7:

*******
 *******
  *******
   *******
    *******
     *******
      *******

and should look like this for n=3:

***
 ***
  ***

*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// toDo:  write your code below this line
void stars(int n){
    int i;
    i = 0;
    while(i<n){
        int ns = 0;
        cout << string(i, ' ');
        while(ns < n){
            cout <<"*";
            ns++;
        }
            cout << endl;
        i++;

    }
}

// make no changes below this line

int main(){
    stars(20);
    stars(3);
    return 0;
}

