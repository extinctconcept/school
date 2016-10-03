#include <iostream>

using namespace std;

int main(){
	float degreesF;
	float degreesC;

	cout << "Put in the degrees in fahrenheit: ";
	cin >> degreesF;
	degreesC = ((degreesF-32)*5)/9;

	cout << "You entered: " <<degreesF << endl;
	cout << "The temp in Celcius: "<< degreesC << endl;

	return 0;
}