#include <iostream>
using namespace std;

void printMenu(){
    cout << "       menu        " << endl;
    cout << "       ----        " << endl;
    cout << "1 - provide an insult" << endl;
    cout << "2 - tell me the weather" << endl;
    cout << "3 - add two numbers" << endl;
    cout << "4 - tell me how many insults youve given me" << endl;
    cout << "q - quit" << endl;
}

char getResponse(){
    char r;
    while (r != 'q' && r=='1' && r=='2' && r=='3'&&r=='4'){
    cout << endl << "your response: ";
    cin >> r;
    }
    return r;
}

int main (){
    bool done = false;
    char r;
    int n1,n2;
    int insults=0;
    while(!done){
        printMenu();
        r = getResponse();
        if (r=='1'){
            cout << "Your mama goes to college.\n";
            insult++;
        } else if (r=='2'){
            cout << "Real cruddy or something like that\n";
        } else if (r=='3'){
            cout << "First number: ";
            cin >> n1;
            cout << "Second number: ";
            cin >> n2;
            cout << "The Sum of the numbers is " << n1+n2 << endl;
        } else if (r=='4'){
            cout << "The number of times I have insulted you is " << insults;
        } else if (r == 'q'){
            done = true;
        }
    }
    return 0;
}