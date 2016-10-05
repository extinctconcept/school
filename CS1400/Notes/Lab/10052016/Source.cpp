#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>



using namespace std;

const int YOUR_ATK = 0;		//Your hero's default attack value
const int BG_ATK = 0;			//Bad guy's default attack value

const int CHANCE_TO_DEFEND = 5;	//Default "armor class" of your character, should you choose to not defend
////////////////////////////////////////////////////////
// global variable to control games functions
int yourHealth = 100;
string yourName = "";
//Bad guy's health
int bGHealth = 40;

//Set of spaces behind your character marker
int behindYou = 10;

//Set of spaces in front of your character marker, between you and your opponent
int inFront = 20;

char choice = NULL;

int yourDefense = CHANCE_TO_DEFEND;

int bGDefense = CHANCE_TO_DEFEND - 2;

int yourAtkVal = 0;
int bGAtkVal = 0;

int bGChoice = 0;
/////////////////////////////////

void setAttributesToDefault();

void attack();
void move();
void defend();



int main()
{
    srand(time(NULL));

    cout << "Welcome to the battle simulator!" << endl;

    cout << "Please enter your character's name: " << endl;
    cin >> yourName;

    tolower(choice);
    while (yourHealth > 0 && bGHealth > 0)
    {
      //Our Turn//
      switch(choice){
        case 'w':
        {
          cout << "You walk menacingly towards the bad, bad man." << endl;
          behindYou += 2; inFront -= 2;
          break;
        }
        case 'd':
        {
          cout << yourName << " chose to hide behind a shield. " << endl;
          yourDefense += 20;
          break;
        }
        case 'a':
        {
          cout << yourName <<" swings wildly at the opponent!" << endl;
          yourAtkVal = rand() % 20;
          break;
        }
        default:
        {
          cout << "not a valid command";
          break;
        }
      }

        yourAtkVal = 0;			//At the beginning of each loop, we set the atk values to 0.
        bGAtkVal = 0;			//This is so we don't "cheat" by adding to our atk value over and over

        yourDefense = CHANCE_TO_DEFEND; //Just in case you defended last time instead of attacked...

        cout << "Your opponent's health is " << bGHealth << endl;
        cout << yourName << "'s health is " << yourHealth << endl << endl;


        cout << setw(behindYou) << "("<< yourName <<")" << setw(inFront) << "(him)" << endl;


        cout << "What will  you do? A/a: attack, W/w: walk towards your opponent, D/d: defend" << endl;
        cin >> choice;

        ///////////////////////////////////////////////////////////////////////////////
        switch(bGChoice){
          case 0:
          {
            cout << "The opponent defends himself against" << yourName << "'s next attack! " << endl;
            bGDefense += 10;
          }
          case 1:
          {
            cout << "The opponent brandishes his weapon to smite "<< yourName <<"! " << endl;
            bGAtkVal = rand() % 20;

            if (bGAtkVal >= yourDefense)
            {
                cout << "The bad, bad man inflicts " << bGAtkVal << " points of damage! " << endl;
                yourHealth -= bGAtkVal;
            }
            else
            {
                cout << "The weapon misses! " << endl;
            }
          }
          case 2:
          {
            cout << "The bad, bad man walks menacingly toward " << yourName <<"! " << endl;
            inFront -= 2;
          }
          default:
          {
            cout << "Something unexpected happened!"
          }
        }

        bGChoice = rand() % 3;		//This is the "AI" that controls our opponent's choice.
        bGDefense = CHANCE_TO_DEFEND - 2;		//We set our opponent's DEF back to default here.
												//Can you see why?

        if (bGChoice == 0)          //If bad guy decides to defend
        {
            cout << "The opponent defends himself against" << yourName << "'s next attack! " << endl;
            bGDefense += 10;
        }
        else if (bGChoice == 1)
        {
            cout << "The opponent brandishes his weapon to smite "<< yourName <<"! " << endl;
            bGAtkVal = rand() % 20;

            if (bGAtkVal >= yourDefense)
            {
                cout << "The bad, bad man inflicts " << bGAtkVal << " points of damage! " << endl;
                yourHealth -= bGAtkVal;
            }
            else
            {
                cout << "The weapon misses! " << endl;
            }

        }
        else
        {
            cout << "The bad, bad man walks menacingly toward " << yourName <<"! " << endl;
            inFront -= 2;
        }

    }

    if (yourHealth <= 0)
        cout << "You dead." << endl;
    else if (bGHealth <= 0)
        cout << "He dead." << endl;

    /*else cout << "This should never output. " << endl;	This line is only for demonstration purposes.*/

    return 0;
}


void setAttributesToDefault();

void attack(bool whosTurn){
  if (whosTurn == 1 || whosTurn == true){
    
  }
};
void move(){

};
void defend(){

};



/*
char input;

switch(input){
  tolower(input);
  case 'w':
    {
      // Do walking function
    }
  case 'a':
    {
      // Do attack function
      break;
    }
  case 'b';
    {
    // Do defend function
    break;
    }
    // input to change choice to next iteration
}
*/
