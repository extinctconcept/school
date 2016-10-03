/**/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){

	bool rollAgain;
	int die;
	char answer;

	srand(time(NULL));

	rollAgain = true;

	cout << "Shall we roll the die? [Y/N]: ";
	cin>>answer;

	while(answer=='y'){
	die = (rand()%6)+1;
	cout << "you rolled a "<<die<<endl;
	cout << "Shall we roll the die? [Y/N]: ";
	cin>>answer;
	}
	return 0;
}