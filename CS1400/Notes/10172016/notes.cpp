#include <iostream>

using namespace std;

int main (){

  for (int i=0; i<10; ++i){
    if (i == 3) continue;
    if (i == 6) break;
    cout << i << endl;
  }
  return 0;
}
