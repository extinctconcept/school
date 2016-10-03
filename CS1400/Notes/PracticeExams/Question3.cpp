/*
Write an int function round(float n) that
returns a rounded value of n. Any decimal
portion greater than or equal to 0.5 should
be rounded up to the next integer value.

Do not use cin or cout in your function.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// toDo:  write your code below this line
int round(float n){
    n=(int)(n+.5);
    return n;
}
// make no changes below this line

int main(){
    cout << round(3.14) << endl;  // should print 3
    cout << round(3.49) << endl;  // should print 3
    cout << round(3.5)  << endl;  // should print 4
    return 0;
}

