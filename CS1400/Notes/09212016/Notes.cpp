#include <iostream>
using namespace std;

void printMenu(){
    cout<<"\t\t\tIt's a Bug's life\n";
    cout<<"\t\t\t_________________\n";
    cout<< "\t\t\te - eat\n";
    cout<< "\t\t\tw - walk\n";
    cout<< "\t\t\tp - poop\n";
    cout<< "\t\t\ts - status\n";
    cout<< "\t\t\tq - quit\n";
    cout<< "\n\n\n\n";
}

char getResponse(){
    char r;
    char q;
    bool done = false;
    while(!done){
        cout<<"\t\tyour selection? ";
        cin >> r;
        if (r=='e' || r=='w' || r=='p' || r=='s' || r=='q')done=true;
        if(!done) cout<<"\t\tHuh?\n";
    }
return r;
}
int main(){
    int legs = 5;
    int mass = 10;
    int food = 0;
    int odo = 0;
    int walkDis =0;
    int poopAmount =0;
    char r = 'z';

    while (r!='q'){
    printMenu();
    r=getResponse();

    if(r=='q'){
        cout<<"Seeya suckers!";
    }
    if(r=='w'){
        if(legs>=1){
        cout<<"They can see tell by the way I use my walk. How far have you walked?\n";
        cin >> walkDis;
        odo+=walkDis;
        } else {
            cout << "you can't walk right now go eat!\n";
        }
    }
    if(r=='e'){
        cout<<"Damn you ate a lot of food. How much?\n";
        cin>>food;
        mass+=food;
        if(mass>30){
            mass=30;
            legs++;
        }
    }
    if(r=='p'){
        poopAmount=rand()%5;
        if(mass<;10){
            mass=10;
            legs--;
            if(legs<0){
                less=0;
            }
        }
    }
    if(r=='s'){
        cout << "legs " <<legs << endl;
        cout << "mass " <<mass << endl;
        cout << "distance: " <<odo << endl;
    }
    }

    return 0;
}