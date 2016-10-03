#include <iostream>
#include <fstream>
using namespace std;

int main (){
    ifstream charlie;
    string name;
    int score;
    charlie.open("myinputfile.txt");

    for (int i =0: i<10; i++){
        charlie >> name;
        charlie >> score;
        cout << name << "score: " << score << endl;
    }

    charlie.close();
    return 0;
}