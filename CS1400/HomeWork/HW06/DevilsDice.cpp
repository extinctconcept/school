#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
  int pCurr = 0;
  int dCurr = 0;
  int player = 1;
  int numAdd = 0;
  int turnScore = 0;
  int lineNum = 0;
  char r = 'x';
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

if (player == 1){
  printScreen(pCurr, dCurr, turnScore);
  cout << "Hold[h], roll[r], or forfeit[f]: ";
  cin >> r;
  while( numAdd != 1 ){
    if ( r == 'r' ){
      numAdd = die();
        if (numAdd != 1){
        turnScore += numAdd;
        printScreen(pCurr,dCurr,turnScore);
        cout << "Hold[h], roll[r], or forfeit[f]: ";
        cin >> r;
        cout << endl;
        cout << "You rolled a "<< numAdd << endl;
      } else if (numAdd == 1){
        player = 2;
        numAdd = 0;
        printScreen(pCurr,dCurr,turnScore);
        cout << "Hold[h], roll[r], or forfeit[f]: ";
        cout << endl;
        cout << "Your rolled a 1 :(" << endl;
      }
    } else if (r == 'h'){
      pCurr += turnScore;
      printScreen(pCurr,dCurr,turnScore);
      cout << "Hold[h], roll[r], or forfeit[f]: ";
      cout << endl;
      cout << "You banked " << turnScore << "points."<< endl;
      player = 2;
    }
  }
  if( numAdd == 1){
    player = 2;
  }
} else if (player == 2){
  while ( numAdd != 1){
    if (pCurr == dCurr){
      turnScore += numAdd;
      numAdd = die();
      if( turnScore >= 21){
        dCurr += turnScore;
        player = 1;
        printScreen(pCurr,dCurr,turnScore);
        cout << "Hold[h], roll[r], or forfeit[f]: ";
        cout << "Devil got " << numAdd << " points\n";
      }
    } else if ( pCurr >= dCurr ){
      turnScore += numAdd;
      numAdd = die();
      if (turnScore >= 30){
        turnScore += dCurr;
        player = 1;
        printScreen(pCurr,dCurr,turnScore);
        cout << "Hold[h], roll[r], or forfeit[f]: ";
        cout << "Devil got " << numAdd << " points\n";
    }
  }
  if (numAdd == 1 ){
    player = 1;
  }
}
  // Call your functions to play your game here...
  return 0;
}

  //test
