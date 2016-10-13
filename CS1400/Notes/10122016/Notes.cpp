#include <iostream>

using namespace std;

struct {
  float x;
  float y;
};

float interpolate(float start, float end, int steps, int stepNum){
  float value;
  float increment;
  increment = (end-start)/stepNum;
  value = start + increment * stepNum;
  return value;
}

int main(){
  float startVal = 0;
  float endVal = 100;
  int numSteps = 100;
  int stepNum = 1;
  float value;

for (int i = 0; i<100; ++i){
  value = interpolate(startVal,endVal,numSteps,stepNum);
  cout << startVal << " " << endVal << " " << numSteps << " " << stepNum << " " << value << endl;
  }
}
