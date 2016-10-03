//f(x) = x +3
// functions are basically the same as in math
#include <iostream>
using namespace std;

/*
	<type> <name>(){
		<do something>
		<return value>
	}
	int f(int input){
		int result =input+3;
		return result;
	}
*/
int f(int x){
	int result = x + 3;
	return result;
}

int main(){
	int x;
	cin >> x;
	cout << "The number "<<x <<" plus 3 equals "<<f(x) << endl;
	return 0;
}