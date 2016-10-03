/*
Write a bool function

bool closeEnough(float a, float b, float tolerance)

that returns true if and only if a and b
are within the tolerance value of each other,
(i.e. a-b <= |tolerance|)

Unfortunately, there is no absolute value
operator, so you'll have to make do with
what you've learned so far.

Your function should not use cin or cout.
*/


#include <iostream>
#include <iomanip>

using namespace std;

// toDo:  write your code below this line
bool closeEnough(float a, float b, float tolerance){
    if(a-b < 0){
        float converted;
        converted = a-b;
        converted *= -1;
        if (converted <= tolerance){
            return true;
            } else {
                return false;
            }
         } else if (a-b > 0){
            if(a-b <= tolerance){
            return true;
    } else {
        return false;
    }
}
}
// make no changes below this line

int main(){
    cout << 13 << " is ";
    if (!closeEnough(13, 14, 1))cout << "not ";
    cout << "close enough to " << 14 << endl;

    cout << 3.12 << " is ";
    if (!closeEnough(3.12, 3.14, .01))cout << "not ";
    cout << "close enough to " << 3.14 << endl;

    cout << 27.1 << " is ";
    if (!closeEnough(27.1, 27, .11))cout << "not ";
    cout << "close enough to " << 27 << endl;

    return 0;
}