#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MINSCALEVALUE = 0;
const int MAXSCALEVALUE = 100;

void printPlayerLine(int lineNumber,int pCurr, int dCurr, int turnScore){
      if(lineNumber>=pCurr && lineNumber < pCurr+10){
          cout << left << " "<< setw(3);
          cout << setw(3) << pCurr << ">";
      } else {
          cout << setw(5) << " ";
      }

      // print
      cout << "--" << lineNumber ;

      // print turn value
      if(lineNumber>=turnScore && lineNumber < turnScore+10){
          cout << right <<setw(2) << "<";
          cout << setw(3) << turnScore;
      } else {
          // not the right line number; print spaces instead
          cout<< setw(5) << " ";
      }

      cout << setw(15) << lineNumber << right<<"--";

      if(lineNumber>=dCurr && lineNumber < dCurr+10){
          cout << right <<setw(3) << "<";
          cout << setw(2)<<dCurr;
      } else {
          // not the right line number; print spaces instead
          cout<< setw(5) << " ";
      }

      cout << endl;
}

void printScreen(int pCurr, int dCurr, int turnScore){
    cout << "---- Welcome to Devil's Dice! ----";
    cout << "\n\n";
    cout << setw(5) <<" "<< "Player" << setw(15) << " " << "Devil\n";
    cout << setw(5) <<" "<< "------" << setw(15) << " " << "-----\n";
    for(int i=MAXSCALEVALUE;i>=MINSCALEVALUE;i-=10){
        printPlayerLine(i, pCurr, dCurr, turnScore);
    }
}

void playerTurn(){

}

int die(){
  return (rand()%6)+1;
}


int main()
{
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

char r = 'z';
int pCurr = 0;
int dCurr = 0;
int turnScore;
int player =1;
int numAdd;

while(r != 'f'){
    printScreen(pCurr, dCurr, turnScore);
    cout << "Hold[h], roll[r], or forfeit[f]: ";
    cin >> r;
    while(player == 1){
      if (r == 'r'){
        numAdd = die();
          if (numAdd != 1){
          turnScore += numAdd;
          printScreen(pCurr,dCurr,turnScore);
          cout << "Hold[h], roll[r], or forfeit[f]: ";
          cin >> r;
          cout << endl;
          cout << "You rolled a "<< numAdd << endl;
        } else if (numAdd == 1){
          turnScore = 0;
          printScreen(pCurr,dCurr,turnScore);
          cout << "Hold[h], roll[r], or forfeit[f]: ";
          cout << endl;
          cout << "Your rolled a 1 :(" << endl;
          player = 2;
        }
      } else if (r == 'h'){
        pCurr += turnScore;
        printScreen(pCurr,dCurr,turnScore);
        cout << "Hold[h], roll[r], or forfeit[f]: ";
        cout << endl;
        cout << "You banked " << turnScore << "points."<< endl;
        player = 2;
      } else if (player == 2){
      numAdd += die();
      while ( numAdd != 1){
        if (pCurr == dCurr){
          turnScore += numAdd;
          numAdd = die();
          if( turnScore >= 21){
            dCurr += turnScore;
            printScreen(pCurr,dCurr,turnScore);
            cout << "Hold[h], roll[r], or forfeit[f]: ";
            cout << "Devil got " << numAdd << " points\n";
            player = 1;
          }
        } else if ( pCurr >= dCurr ){
          turnScore += numAdd;
          numAdd = die();
          if (turnScore >= 30){
            turnScore += dCurr;
            printScreen(pCurr,dCurr,turnScore);
            cout << "Hold[h], roll[r], or forfeit[f]: ";
            cout << "Devil got " << numAdd << " points\n";
            player = 1;
          }
        }
      }
      if (numAdd == 1 ){
        player = 1;
      }
    }
  }
}
  // Call your functions to play your game here...

  return 0;
}
