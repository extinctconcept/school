#include <iostream>
#include <string>

using namespace std;

int main(){
	int degrees;
	string fDegrees;

	degrees = 72;

	cout<<endl<<"foo"<<endl<<"bar\n\n\forEVER\n";
	cout<<endl<<"\tThis should tab over"<<endl;
	cout<<" the current temperature is "<<degrees<<" degrees"<<endl;
	degrees += 72;
	cout<<" the current temperature is "<<degrees<<" degrees"<<endl;
	fDegrees = "Hot";
	cout << " It is currently " <<fDegrees<< " outside!"<<endl;
	return 0;

}
