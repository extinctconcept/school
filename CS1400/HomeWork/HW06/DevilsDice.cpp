#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MINSCALEVALUE = 0;
const int MAXSCALEVALUE = 100;

int diceRoll();
void welcome();
void logic();
void printScreen();


int main(){
  int pCurr = 0;
  int dCurr = 0;
  int player = 1;
  int numAdd = 0;
  int turnScore =0;
  char r = 'x';
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

welcome();
while(r!='f'){
    printScreen();
    cout<<"[s]et desired temp, [w]ait, or [q]uit: ";
  }
//printLine();
//logic();
  // Call your functions to play your game here...
  return 0;
}

int diceRoll(){
  int die;
  die = (rand()%6)+1;
  return die;
}

//calculate dice roll and add to current score
void logic(int pCurr, int dCurr, int player, int numAdd,int turnScore, int die){
  char r;
  cin >> r;
  if (r == 'r'){
    diceRoll();
  }
  // if your turn
  while (player == 1){
    numAdd = 0;
    while (die != 1 && r == 'r'){
      // player rolls
      cout << "You rolled a "<< die << "!";
      numAdd += die;
      turnScore = numAdd + pCurr;
      cin >> r;
      }
    if (die != 1 && r == 'h'){
      // if hold bank the points and switch to devils turn
      cout << "You banked " << numAdd << " points\n";
      numAdd += pCurr;
      player = 2;
    } else if ( die == 1 ){
      // if 1 rolled switch to other devil
      cout << "You rolled a 1 :(\n";
      player = 2;
    }
  }
  // player 2 equals the devil
  while (player == 2){
    if (pCurr == dCurr){
      // roll until the score devil reaches at least 21 or 100
      numAdd = 0;
      while(die != 1 && dCurr != 100){
        numAdd += die;
        if (numAdd >= 21){
          cout << "Devil got " << numAdd << " points\n";
          dCurr += numAdd;
        } else {
          numAdd += die;
          dCurr += die;
        }
      }
    }
    if (pCurr >= dCurr){
      numAdd = 0;
      while(die != 1){
        numAdd += die;
        if (numAdd >= 30 && dCurr != 100){
          numAdd += dCurr;
          cout << "Devil got " << numAdd << " points\n";
        }
      }
    }
  }
  if (die == 1){
    numAdd = 0;
    if (player == 1){
      player = 2;
    } else if (player == 2 ){
      player = 1;
    }
  }
}

void welcome(){
  cout << "---- Welcome to Devil's Dice! ----" << endl;
  for(int i=MINSCALEVALUE;i<=MAXSCALEVALUE;i+=10){
    //printLine();
}
}

void printScreen(int lineNum, int pCurr, int dCurr, int turnScore, int player){
    while (player == 1){
      if( lineNum >= pCurr && lineNum <= turnScore ){
        cout << setw(5) << pCurr << ">";
      } else {
        cout << setw(5) << " ";
      }
      cout << lineNum;
    }
    if (lineNum >= pCurr && lineNum < turnScore){
      cout << left << setw(5) << "< ";
      cout << turnScore;
    }
      cout << endl;

    while (player == 2){
      if( lineNum >= dCurr && lineNum <= turnScore ){
        cout << setw(8) << pCurr << ">";
      } else {
        cout << setw(15) << " ";
      }

      cout << lineNum;
    if (lineNum >= dCurr && lineNum < turnScore){
      cout << right << setw(15) << "< ";
      cout << turnScore;
    }
      cout << endl;
    }
  }
