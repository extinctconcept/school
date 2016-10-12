#include <iostream>
#include <fstream>

const int XDIM=1024;
const int YDIM=1024;
const int MAXINTESITY=256;

using namespace std;

struct color{
  int r;
  int g;
  int b;
};

color add(color a, color b){
  color c;
  c.r=(a.r+b.r)%MAXINTESITY;
  c.r=(a.r+b.g)%MAXINTESITY;
  c.r=(a.r+b.b)%MAXINTESITY;

}

int main(){
  color myColor;
  ofstream fout;
  fout.open("red.ppm");

  myColor.r = 255;
  myColor.g = 0;
  myColor.b = 0;
  redincrement.r=1;
  redincrement.g=0;
  redincrement.b=0;
  blueincrement.r=0;
  blueincrement.g=0;
  blueincrement.b=1;

  fout << "P3\n";
  fout << XDIM <<" "<< YDIM << "\n255\n";
  for (int i = 0; i<YDIM; ++i){
    for(int j = 0; j<XDIM; ++j){
      fout << myColor.r << " ";
      fout << myColor.g << " ";
      fout << myColor.b << " ";
    }
  }
  return 0;
}
