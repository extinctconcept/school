#include <iostream>
#include <iomanip>

using namespace std;

void printLine(int lineNum, int curTemp, int setTemp){
    if(lineNum>=curTemp && lineNum <=curTemp){
      cout << setw(8) <<"Current Temp";
      cout << setw(3) << curTemp << ">";;
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

void printScreen(int curTemp, int setTemp){
    for(int i = 30; i<=85; i+=5 ){
        printLine(i, curTemp, setTemp);
}
}
int main (){
  char c = 'x';
  int set=61;
  int current=47;
    while (c!='q'){
      printScreen(45,60);
      cout << "[s]et desired temp, [w]ait, or [q]uit" << endl;
      cin >> c;
      if (c == 'q'){
        cout << "quitter";
      }
      if (c =='w'){
        if (current < set){
          current++;
        }
        if (current > set){
          current--;
        }

      }
      if (c =='s'){
        cout << "Set Temp >>";
        cin >> set;
      }
    }
    return 0;
}
