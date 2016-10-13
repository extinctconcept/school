#include <iostream>

using namespace std;

struct gridPoint {
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
  gridPoint start;
  gridPoint currentLocation;
  start.x = 200;
  start.y = 42.1;
  X.x = 500;
  X.y = 456.2;
  currentLocation = start;

  for (int i=0; i< 100; ++i){
    currentLocation.x = interpolate(start.x, X.x, 100, i);
    currentLocation.x = interpolate(start.y, X.y, 100, i);
    cout << currentLocation.x << " " << currentLocation.y << endl;
    }
  }
