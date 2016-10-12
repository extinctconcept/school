/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 6
***********************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MINSCALEVALUE = 0;
const int MAXSCALEVALUE = 100;

int playerTurn(char r, int pCurr, int dCurr, int turnScore, int dTurnScore, int player, int numAdd);

void score(int pCurr, int dCurr){
  ifstream score;
  int win;
  int lose;
  score.open("games.txt");
    score >> win >> lose;
    if (pCurr >= 100){
      win += 1;
    } else if (dCurr >= 100){
      lose += 1;
    }
    score.close();
    ofstream results;
    results.open("games.txt");
    cout << "Total Wins: " << win << endl;
    cout << "Total Losses: " << lose;
    results << win <<"  "<< lose;
  }

void printPlayerLine(int lineNumber, int pCurr, int dCurr, int turnScore, int dTurnScore){
      if (lineNumber >= pCurr && lineNumber < pCurr+10){
          cout << right << setw(5);
          cout << setw(3) << pCurr << " >";
      } else {
          cout << setw(5) << " ";
      }

      // print
      cout << "--" << lineNumber;

      // print turn value
      if (lineNumber >= turnScore && lineNumber < turnScore+10){
        if (lineNumber >= turnScore && lineNumber == 0){
          cout << right <<setw(1) << " < ";
          cout << turnScore << setw(11) << " ";
        } else if (lineNumber >= turnScore && lineNumber == 100){
          cout << right <<setw(1) << "< ";
          cout << turnScore << setw(9) << " ";
        } else if (lineNumber > 1 && turnScore < 10){
          cout << right <<setw(1) << "< ";
          cout << turnScore << setw(11) << " ";
        } else {
          cout << right <<setw(1) << "< ";
          cout << turnScore << setw(10) << " ";
        }
      } else if (lineNumber == 0){
          // not the right line number; print spaces instead
          cout<< setw(15) << " ";
      } else if (lineNumber == 100){
          cout<< setw(13) << " ";
      } else {
        cout<< setw(14) << " ";
      }

      cout << right << setw(6) << lineNumber << left << "--";

      if (lineNumber >= dTurnScore && lineNumber < dTurnScore+10){
          cout << left << setw(2);
          cout << "<" << dCurr;
      } else {
          cout << setw(5) << " ";
      }

      cout << endl;
}

void printScreen(int pCurr, int dCurr, int turnScore, int dTurnScore){
    cout << "Hold[h], roll[r], or forfeit[f]: ";
    cout << "\n";
    cout << setw(5) <<" "<< "Player" << setw(15) << " " << setw(5) << "Devil     \n";
    cout << setw(5) <<" "<< "------" << setw(15) << " " << setw(5) << "-----     \n";
    for (int i = MAXSCALEVALUE; i >= MINSCALEVALUE; i-=10){
        printPlayerLine(i, pCurr, dCurr, turnScore, dTurnScore);
    }
}

int die(){
  return (rand()%6)+1;
}

int devilsTurn(char r, int pCurr, int dCurr, int turnScore, int dTurnScore, int player, int numAdd){
  while (player == 2){
        if (pCurr == dCurr){
          while (numAdd != 1){
            dTurnScore += numAdd;
            numAdd = die();
            }
            if (turnScore >= 21){
              dCurr += dTurnScore;
              cout << "Devil got " << dTurnScore << " points\n";
              dTurnScore = 0;
              player = 1;
              playerTurn(r, pCurr, dCurr, turnScore, dTurnScore, player, numAdd);
            }
          } else if (pCurr >= dCurr){
              while (numAdd != 1){
              dTurnScore += numAdd;
              numAdd = die();
              if (dTurnScore >= 30){
                dCurr += dTurnScore;
                printScreen(pCurr, dCurr, turnScore, dTurnScore);
                cout << "Devil got " << dTurnScore << " points\n";
                player = 1;
                playerTurn(r, pCurr, dCurr, turnScore, dTurnScore, player, numAdd);
              } else if (numAdd == 1){
                dTurnScore = 0;
                player = 1;
              } else if (numAdd == 1){
                player = 1;
              } else if (dCurr >= 100){
                cout  << "Devil Wins!" << endl;
                score(pCurr, dCurr);
            }
        }
      }
    }
}

int playerTurn(char r, int pCurr, int dCurr, int turnScore, int dTurnScore, int player, int numAdd){
  while (player == 1){
    printScreen(pCurr, dCurr, turnScore, dTurnScore);
    cin >> r;
    if (r == 'r'){
      numAdd = die();
        if (numAdd != 1){
            turnScore += numAdd;
            cout << "You rolled a " << numAdd << endl;
          } else if (numAdd == 1){
            turnScore = 0;
            cout << "Your rolled a 1 :(" << endl;
            printScreen(pCurr, dCurr, turnScore, dTurnScore);
            player = 2;
            devilsTurn(r, pCurr, dCurr, turnScore, dTurnScore, player, numAdd);
          }
        }
      if (r == 'h'){
        pCurr += turnScore;
        cout << "You banked " << turnScore << " points."<< endl;
        printScreen(pCurr, dCurr, turnScore, dTurnScore);
        turnScore = 0;
        player = 2;
        devilsTurn(r, pCurr, dCurr, turnScore, dTurnScore, player, numAdd);
      }
      if (pCurr >= 100){
        cout << "You Win!" << endl;
        score(pCurr, dCurr);
    }
    if (r == 'f'){
      cout << "You Lose!\n";
      dCurr = 100;
      score(pCurr, dCurr);
      break;
    }
  }
    return player;
}

int main(){
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

char r = 'z';
int pCurr = 0;
int dCurr = 0;
int turnScore;
int dTurnScore;
int player = 1;
int numAdd;

  cout << "---- Welcome to Devil's Dice! ----\n";
  if (player == 1){
    playerTurn(r, pCurr, dCurr, turnScore, dTurnScore, player, numAdd);
    } else if (player == 2){
      devilsTurn(r, pCurr, dCurr, turnScore, dTurnScore, player, numAdd);
  }
  return 0;
}
