/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 4
***********************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void menu();
void status(string r);

int main(){
  menu();
  string r;
  cin >> r;
  status(r);
  return 0;
}
void menu(){
  cout << "s - report the machine status\n";
  cout << "d - drop in a quarter\n";
  cout << "1 - pull the 1st knob\n";
  cout << "2 - pull the 2nd knob\n";
  cout << "3 - pull the 3rd knob\n";
  cout << "4 - pull the 4th knob\n";
  cout << "r - restock the machine\n";
  cout << "q - quit\n";
}
void status(string r){
  int numLuckies = 5;
  int numCamels = 7;
  int numGauloises = 1;
  int numMalls = 6;
  int numQuarters = 0;
  float numMachineMoney = 24.50;

while ( r != "q" ){
    if ( r == "s" ) {
      cout << "1: "<< numLuckies <<" packs of Lucky Strikes\n";
      cout << "2: "<< numCamels <<" packs of Camels\n";
      cout << "3: "<< numGauloises <<" packs of Gauloises\n";
      cout << "4: "<< numMalls <<" packs of Pall Malls\n";
      cout << "You have " << numQuarters <<" quarters to spend\n";
      cout << "There is $" << fixed << setprecision(2) << numMachineMoney << " in the machine\n";
      cin >> r;
    } else if ( r == "d" ){
      numQuarters++;
      cout << "ching\n";
      cin >> r;
    } else if ( r == "1" ){
      if ( numLuckies == 0 ){
        // print You hear mechanical clanking, but no cigarettes appear.
        cout << "You hear mechanical clanking, but no cigarettes appear.\n";
        cin >> r;
      } else if ( numQuarters >= 3 ){
      // dispense pack of lucky strikes pack
        cout << "A pack of Lucky Strikes slides into view. It's your lucky day!\n";
        numMachineMoney += .75;
        numLuckies--;
        numQuarters -= 3;
        cin >> r;
      } else if ( numQuarters < 3 ){
        cout << "(nothing happens)\n";
        numMachineMoney += numQuarters * .25;
        numQuarters = 0;
        cin >> r;
      }
    } else if ( r == "2" ){
      if ( numCamels == 0 ){
        // print You hear mechanical clanking, but no cigarettes appear.
        cout << "You hear mechanical clanking, but no cigarettes appear.\n";
        cin >> r;
      } else if ( numQuarters >= 3 ){
      // dispense pack of Camels -- pack
        cout << "A pack of Camels slides into view. Watch out, they spit!\n";
        numMachineMoney += .75;
        numCamels--;
        numQuarters -= 3;
        cin >> r;
      } else if ( numQuarters < 3 ){
        cout << "(nothing happens)\n";
        numMachineMoney += numQuarters * .25;
        numQuarters = 0;
        cin >> r;
      }
    } else if ( r == "3" ){
      if ( numGauloises == 0 ){
        // print You hear mechanical clanking, but no cigarettes appear.
        cout << "You hear mechanical clanking, but no cigarettes appear.\n";
        cin >> r;
      } else if ( numQuarters >= 3 ){
      // dispense pack of Gauloises -- pack
        cout << "A pack of Gauloises slides into view. Gauloises? Really?\n";
        numMachineMoney += .75;
        numGauloises--;
        numQuarters -= 3;
        cin >> r;
      } else if ( numQuarters < 3 ){
        cout << "(nothing happens)\n";
        numMachineMoney += numQuarters * .25;
        numQuarters = 0;
        cin >> r;
      }
    } else if ( r == "4" ){
      if ( numMalls == 0 ){
        // print You hear mechanical clanking, but no cigarettes appear.
        cout << "You hear mechanical clanking, but no cigarettes appear.\n";
        cin >> r;
      } else if ( numQuarters >= 3 ){
      // dispense pack of    Malls -- pack
        cout << "A pack of Pall Malls slides into view. They rhyme!\n";
        numMachineMoney += .75;
        numMalls--;
        numQuarters -= 3;
        cin >> r;
      } else if ( numQuarters < 3 ){
        cout << "(nothing happens)\n";
        numMachineMoney += numQuarters * .25;
        numQuarters = 0;
        cin >> r;
      }
    } else if ( r == "r" ){
      // set all cigarette variable equal to 10 and machine money and variable to 0
      numLuckies = 10;
      numCamels = 10;
      numGauloises = 10;
      numMalls = 10;
      numQuarters = 0;
      numMachineMoney = 0.00;
      // request machine restock print A grouchy-looking attendant shows up and restocks the machine.
      cout << "A grouchy-looking attendant shows up and restocks the machine.\n";
      cin >> r;
    } else {
    cout << "I do not understand.\n";
    cin >> r;
  }
}
if ( r == "q" ){
  cout << "So long!\n";
}
}
