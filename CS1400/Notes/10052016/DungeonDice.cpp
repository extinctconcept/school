#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void printWelcome(){
  cout << "Hi!"<< endl;
}
void printScreen(int dd20, int pd20, int dd12, int pd12, int dd10, int pd10){
  cout << "             you           dm"<< endl;

  cout << "d20:            ";
  printDie(pd20);
  cout << "           "
  printDie(dd20);
  cout << "d12:            ";
  printDie(pd12);
  cout << "           "
  printDie(dd12);
  cout << "d10:            ";
  printDie(pd10);
  cout << "           "
  printDie(dd10);
}

char getResponse(){
  char response;
  cout <<"[r]oll or  [p]ass: ";
  cin >> response;
  return 'p';

}
void printWinner(bool dmWins){
  if(dmWins==1){
    cout << "You LOSE!" << endl;
  } else {
    cout << "You win... LOSER!";
  }
}
void printDie(){
  cout << setw(2)<< right;
}
int rollDie(int sides){
  return (rand()%sides);
}

void dungeonDice(){
  bool dmWins = true;
  bool done=false;
  char r;
  int pd20;
  int pd12;
  int pd10;
  int dd20;
  int dd12;
  int dd10;
  int sides;
  printWelcome();
  while(!done){
    printScreen();
    r=getResponse();
    if(r=='r'){

    }
    if(r=='p'){
      done=true;
    }
    printWinner(dmWins);
  }
}

int main()
{
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif
dungeonDice();
  // Call your functions to play your game here...

  return 0;
}
