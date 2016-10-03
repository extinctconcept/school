#include <iostream>
using namespace std;

// if (<boolean condition>) expression;

// if (<boolean condition>) {
// 	expression;
// 	expression;
// 	expression;
// 	expression;
// } else {
// 	expression;
// 	expression;
// }

int main(){
	int score;
	cout << "What is your score? ";
	cin >> score;
	if (score > 100){
		cout << "invalid score.. Cheater!\n";
		return 0;
	}
	if (score >= 90 && score <= 100 ){
		cout << ":D\n";
		}else if (score > 80 ){
			cout << ":)";
		} else if (score>=60){
			cout << ":|";
		} else {
			cout << "You need to go see the tutors.";
		}
	return 0;
}