/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 8
***********************/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Color
{
  int red;
  int green;
  int blue;
};

struct MandelbrotConfig
{
  int width;
  int height;
  double xComplexMin;
  double xComplexMax;
  double yComplexMin;
  double yComplexMax;
  int maxIterations;
  Color colorOne;
  Color colorTwo;
  string outputFileName;
};

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

MandelbrotConfig readConfig(string configFileLocation);
void drawMandelbrot(MandelbrotConfig config);
Color getPixelColor(Color color1, Color color2, int iterations, int maxIterations);

int main()
{
  // Read in config file location from user
  string filename;
  ifstream input;
  ofstream output;
  string line;
  cout << "Mandelbrot Config File: ";
  cin >> filename;
  input.open(filename.c_str());
  MandelbrotConfig m;

  // Read config file contents into MandelbrotConfig struct instance
  if (input.is_open()) {
      Color color1;
      Color color2;
      color1.red;
      color1.green;
      color1.blue;
      color2.red;
      color2.green;
      color2.blue;

      Color c;

      input
      >> m.width
      >> m.height
      >> m.xComplexMin
      >> m.xComplexMax
      >> m.yComplexMin
      >> m.yComplexMax
      >> m.maxIterations
      >> color1.red >> color1.green >> color1.blue
      >> color2.red >> color2.green >> color2.blue
      >> m.outputFileName;
      m.colorOne = color1;
      m.colorTwo = color2;

    input.close();
    }

// Compute and write specified mandelbrot image to PPM file
  output.open(m.outputFileName.c_str());
  output << "P3\n";
  output << m.width <<" "<< m.height << "\n255\n";
  for (int i = 0; i < m.height; ++i){
    for (int j = 0; j < m.width; ++j){
      //find xy location for pixel
      double x;
      double y;
      double xincrement;
      double yincrement;
      xincrement = (m.xComplexMax-m.xComplexMin) / m.width;
      yincrement = (m.yComplexMax-m.yComplexMin) / m.height;
      x = m.xComplexMin + j * xincrement;
      y = m.yComplexMax + i * yincrement;
      cout << y << " ";
      //
      // cout << y << endl;
    }
  }
      Complex c;
      Complex z;
      int maxIterations = m.maxIterations;
      int iteration = 0;
      // c.real = pX;
      // c.imag = pX;
      // z.real = pY;
      // z.imag = pY;

      while(iteration < maxIterations && magnitudeSquared(z) < 4){
      z=z*z+c;
      iteration++;
    }
      // cout << iteration << " ";




    return 0;
}








// float getx(int j, point p1, point p2){
//     float x;
//     float increment;
//     increment=(p2.x-p1.x)/COLS;
//     x=p1.x+j*increment;
//     return x;
// }

// float gety(int i, point p1, point p2){
//     float y;
//     float increment;
//     increment=(p2.y-p1.y)/ROWS;
//     y=p1.y+i*increment;
//     return y;
// }

// point getPoint(int i, int j, point p1, point p2){
//     point p;
//     p.x=getx(j,p1,p2);
//     p.y=gety(i,p1,p2);
//     return p;
// }


