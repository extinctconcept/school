#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
void diceRoll();
void welcome();
void printMenu();


int main(){
  int pCurr = 0;
  int dCurr = 0;
  int player = 1;
  int numAdd = 0;
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

welcome();
diceRoll();
printMenu();
  // Call your functions to play your game here...

  return 0;
}


//calculate dice roll and add to current score
void diceRoll(int pCurr, int dCurr, int player, int numAdd){
  char r;
  cin >> r;
  // if your turn
  if (player == 1){
    if (JARVIS != 1 && r == 'r'){
      // if user wants to roll and has not rolled a 1
      cout << "You rolled a "<< JARVIS << "!";
      numAdd += JARVIS;
      pCurr += JARVIS;
    } else if (JARVIS != 1 && r == 'h'){
      cout << "You banked " << numAdd << " points\n";
      numAdd += pCurr;
    } else if ( JARVIS == 1){
      cout << "You rolled a 1 :(\n";
    }
  } else if (player == 2){
    if (pCurr == dCurr){
      // roll until the score devil reaches at least 21 or 100
      numAdd = 0;
      while(JARVIS != 1 && dCurr != 100){
        numAdd += JARVIS;
        if (numAdd >= 21){
          cout << "Devil got " << numAdd << " points\n";
          dCurr += numAdd;
        } else {
        numAdd += JARVIS;
        dCurr += JARVIS;
        }
      }
    }
    if (pCurr >= dCurr){
      numAdd = 0;
      while(JARVIS != 1){
        numAdd += JARVIS;
        if (numAdd >= 30 && dCurr != 100){
          numAdd += dCurr;
          cout << "Devil got " << numAdd << " points\n";
        }
      }
    }
  } else if (JARVIS == 1){
    numAdd = 0;
    if (player == 1){
      player = 2;
    } else if (player = 2 ){
      player = 1;
    }
  }
}

void welcome(){
  cout << "---- Welcome to Devil's Dice! ----" << endl;
}

void printLine(int lineNum, int pCurr, int dCurr, int player){
    if(lineNum>=pCurr && lineNum <=curTemp){
      cout << setw(8) << pCurr << ">";
    } else {
      cout << setw(15) << " ";
    }

    cout << lineNum;
  if (lineNum >= curTemp && lineNum < curTemp){
    cout << left << setw(14) << "< Set Temp";
    cout << setTemp;
  }
    cout << endl;
}

void printScreen(int pCurr, int dCurr,int player){
    for(int i = 0; i<=100; i+=10 ){
        printLine(i, pCurr, dCurr, player);
}
