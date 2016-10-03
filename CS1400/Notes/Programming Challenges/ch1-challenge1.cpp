//Chapter 1 Challenge 1
#include <iostream>
using namespace std;

int main(){
	double numBars, barCost, total;

	//get the amount of candy bars sold
	cout << "How many candy bars were sold?" << endl;
	cin >> numBars;

	cout << "You entered " <<numBars<< " candy bars sold" <<endl;
	cout << "How much did each candy bar cost?" << endl;
	cin >> barCost;

	total = barCost*numBars;
	cout << "Where you sold " << numBars << ", and each candy bar cost $" << barCost << endl;
	cout << "The total earned is $" << total;
}