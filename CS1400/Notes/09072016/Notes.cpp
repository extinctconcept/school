#include <iostream>
using namespace std;

int main(){
	// statement is a statement '{' followed by 
	// one or more statemented followed by '}'
	// boolean 0 false non-zero is true
	// comparison operators include ==, <, >, <=, >=, !=
	// logical operators && || !
	
	//example of some if satement below

	// if(<logical condition>){
	// 	statement;
	// 	statement;
	// 	statement;
	// }
	int a = 1;
	bool b = false;
	int c = 3;

	if((a > c) || b ){
		cout << "foo\n";
	} else {
		cout << "bar\n";
	}

		return 0;
	
	}