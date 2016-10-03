/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 2
***********************/

#include <iostream>
using namespace std;

int main(){
    cout << "Is it an object?\n";
    char response;
    cin >> response;

    if (response == 'y'){
        // eat it?
        cout << "Can you eat it?\n";
        cin >> response;
        if (response == 'y'){
            // eat it! was it good?
            cout << "Eat it.\n";
            cout << "Was it good?\n";
            cin >> response;
            if (response =='y') {
                // wag tail
                cout << "Wag your tail.\n";
            } else {
                cout << "Puke it out.\nRe-eat it.";
            }
        } else {
            // is it a tennis ball
            cout << "Is it a tennis ball?\n";
            cin >> response;
            if (response == 'y'){
                // pick it up and return to owner
                cout << "Pick it up.\n";
                cout << "Return to owner.\n";
            } else {
                // bark at it
                cout << "Bark at it.";
            }
        }
    } else {
        // is it a sound?
        cout << "Is it a sound?\n";
        cin >> response;
        if (response == 'y'){
            // bark at it
            cout << "Bark at it.\n";
        } else {
            // ignore it
            cout << "Ignore it.";
        }
    }
return 0;
}