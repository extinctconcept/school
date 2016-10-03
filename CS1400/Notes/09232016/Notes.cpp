#include <iostream>
#include <string>

using namespace std;

int main(){
    string name1="Dan";
    string name2="harpo";
    string name3="slartibartfast";
    string name4= name1+name2;
    string name5=name1;


    cout << name4 << endl;
    cout << name4.length() << endl;
    cout << name2.length() << endl;
    cout << name3.length() << endl;
    if (name5=name1){
        cout << "same"<<endl;
        }else{ cout << "not the same" <<endl;
    }

    return 0;
}