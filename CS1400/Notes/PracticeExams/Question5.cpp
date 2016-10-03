/*

Write a string function fozzbazz(int n)
that returns:
"fozz" if n is evenly divisible by 3,
"bazz" if n is evenly divisible by 5,
and returns
"slartibartfast" otherwise.

if a number is evenly divisible by more
than one of the numbers above, choose the
first one to return.  Thus, for n=15, the
functions returns "fozz".

Do not use cin or cout in your function
*/

#include <iostream>
#include <iomanip>

using namespace std;

// toDo:  write your code below this line
string fozzbazz(int n){
    if(n%3==0){
        return "fozz";
    } else if (n%5==0){
        return "bazz";
    } else {
        return "slartibartfast";
    }
}
// make no changes below this line

int main(){
    cout << fozzbazz(3)  << endl;  // fozz
    cout << fozzbazz(5)  << endl;  // bazz
    cout << fozzbazz(15) << endl;  // fozz
    cout << fozzbazz(16) << endl;  // slartibartfast

    return 0;
}