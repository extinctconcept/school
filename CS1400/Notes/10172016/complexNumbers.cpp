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

int main (){
  Complex c1;
  Complex c2;
  Complex c3;

  c1.real = 3;
  c1.imag = 4;

  c2 = c1*c1;
  cout << c2.real << " " << "+" << " " << c2.imag << "i" << endl;
  cout << c2.real << " " << "+" <<" " << c2.imag << "i" << endl;

  return 0;
}
