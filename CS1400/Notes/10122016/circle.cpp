#include <iostream>
#include <fstream>
#include <cmath>

const int XDIM=1024;
const int YDIM=1024;
const int MAXINTESITY=256;

using namespace std;

float distance(int a_x, int a_y, int b_x, int b_y){
  int x = b_x - a_x;
  int y = b_y - a_y;
  return sqrt(x*x + y*y);
}

bool insert(int c_x, int c_y, float radius,){

}

int main(){
  ofstream fout;
  fout.open("circle.ppm");
  fout << "P3\n";
  fout << XDIM <<" "<< YDIM << "\n255\n";
  for (int i = 0; i<YDIM; ++i){
    for(int j = 0; j<XDIM; ++j){
      fout <<
    }
  }
  return 0;
}
