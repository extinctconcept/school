#include <iostream>
#include <iomanip>

const int MINSCALEVALUE = 20;
const int MAXSCALEVALUE = 85;

using namespace std;

void printLine(int lineNumber, int currentTemp, int setTemp){

    // print current temperature and arrow thing
    if(lineNumber>=currentTemp && lineNumber < currentTemp+5){
        cout << left;
        cout << setw(9) << "currently ";
        cout << setw(3) << currentTemp << "> ";
    } else {
        // not the right line number; print spaces instead
        cout << setw(15) << " ";
    }

    // print scale
    cout << lineNumber;

    // print set temperature
    if(lineNumber>=setTemp && lineNumber < setTemp+5){
        cout << left<<setw(10) << " <set to ";
        cout << setTemp;
    } else {
        // not the right line number; print spaces instead
        cout << setw(14) << " ";
    }
    cout << endl;

}

void printScreen(int currentTemp, int setTemp){
    cout << "\n\n\n\n";
    for(int i=MINSCALEVALUE;i<=MAXSCALEVALUE;i+=5){
        printLine(i, currentTemp, setTemp);
    }
}

int main(){
    int current=47;
    int set=61;
    char c = 'x';
    while(c!='q'){
        printScreen(current,set);
        cout<<"[s]et desired temp, [w]ait, or [q]uit: ";
        cin>>c;
        if(c=='q'){
            cout<<"quitting..."<<endl;
        }
        if(c=='w'){
            if(current<set)current++;
            if(current>set)current--;
        }
        if(c=='s'){
            cout<<"desired temp: ";
            cin>>set;
        }
    }

    return 0;
}
