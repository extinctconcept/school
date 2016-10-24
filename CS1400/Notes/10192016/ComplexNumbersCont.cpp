#include <iostream>
using namespace std;

struct Complex{
  double real;
  double imag;
};

Complex operator*(Complex c1, Complex c2){
  Complex c3;
  c3.real = c1.real*c2.real - c1.imag*c2.imag;
  c3.imag = c1.real*c2.imag + c2.real*c1.imag;
  return c3;
}

Complex operator+(Complex c1, Complex c2){
  Complex c3;
  c3.real = c1.real+c2.real;
  c3.imag = c1.imag+c2.imag;
  return c3;
}

double magnitudeSquared(Complex c){
  return c.real*c.real+c.imag*c.imag;
}


int main (){
  Complex c;
  Complex z;
  int maxIterations = 512;
  int i;

  c.real = -1;
  c.imag = -0.2901;
  z.real = 0;
  z.imag = 0;

  i=0;

  while(i < maxIterations && magnitudeSquared(z) < 4){
    z=z*z+c;
    i++;
  }
  cout << i << endl;
  return 0;
}
