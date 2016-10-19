#include <iostream>
#include <string>
using namespace std;

void foo(int n){
  cout << n+1 << endl;
}

void foo(string s){
  cout << s << endl;
}

int main (){
  int i = 42;
  string s = "jfkdlsj";

  foo(i);
  foo(s);

  return 0;
}
