#include <iostream>
using namespace std;

int main() {
	int i = 0;
	while(i < 100){
	cout << "The number is " << i << ". ";
	if (i%3==0){
		cout << "fizz" << endl;
	}
	if(i%5==0){
		cout << "buzz" << endl;
	} else if(i % 3 != 0 && i%5 !=0){
		cout << i << endl;
	}

	i++;
	}
	return 0;
}

------------------------------------------------------------------------

//functions
