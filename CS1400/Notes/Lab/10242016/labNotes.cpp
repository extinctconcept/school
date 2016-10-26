#include <iostream>

using namespace std;

struct gumMachine{
    int numGum;
    // int numQuartersRequired;
    // int numQuartersInSlot;
    // double moneyInMachine;
};

void byGum(gumMachine g){
    if (g.numQuartersInSlot == g.numQuartersRequired){
        cout << "You got a gumball." << endl;
        g.numGum--;
        //g.numQuartersInSlot = 0;

    }
}

int main(){
    char c;
    gumMachine ourMachine;
    //ourMachine.numQuartersRequired = 1;
    ourMachine.numGum = 250;
    int numWanted;
    int quartersInPocket;

    cout << "What would you like to do?" << endl;
    cin >> c;
    while (c != 'q'){
        switch (c)
        {
            case 'b':
                quartersInPocket -= ourMachine.numQuartersRequired;
                byGum(ourMachine);
                if (numWanted == 1){
                    buyGum(ourMachine);
                } else buyGum(ourMachine, numWanted)
                break;
        }
    }

    return 0;
}