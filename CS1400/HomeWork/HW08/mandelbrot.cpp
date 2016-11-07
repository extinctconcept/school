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
      int redSmoosh = m.colorOne.red;
      int greenSmoosh = m.colorOne.green;
      int blueSmoosh = m.colorOne.blue;
      double redDiff;
      double greenDiff;
      double blueDiff;
    for (int j = 0; j < m.width; ++j){
      //  find xy location for pixel
      double x;
      double y;
      double xincrement;
      double yincrement;
      xincrement = (m.xComplexMax - m.xComplexMin) / m.width;
      yincrement = (m.yComplexMax - m.yComplexMin) / m.height;
      x = m.xComplexMin + j * xincrement;
      y = m.yComplexMin + i * yincrement;

      Complex c;
      Complex z;
      double maxIterations = m.maxIterations;
      double iteration;

      c.real = x;
      c.imag = y;
      z.real = 0;
      z.imag = 0;

      iteration = 0;

      while (iteration < maxIterations && magnitudeSquared(z) < 4){
        z = z * z + c;
        iteration++;
        // cout << iteration << " ";
      }
      // find color based off iteration
      // for example if value iteration = max iteration then color pixel right color.

      if (m.colorOne.red > m.colorTwo.red){
        redDiff = m.colorOne.red - m.colorTwo.red;
        redDiff = redDiff/static_cast<double>(m.maxIterations);
        redDiff *= iteration;
        redSmoosh = m.colorOne.red - redDiff;
      } else if (m.colorOne.red < m.colorTwo.red){
        redDiff = m.colorTwo.red - m.colorOne.red;
        redDiff = redDiff/static_cast<double>(m.maxIterations);
        redDiff *= iteration;
        redSmoosh = redDiff+1 + m.colorOne.red;
      } else if (m.colorOne.red == m.colorTwo.red){
        redSmoosh = m.colorOne.red;
      }
      if (m.colorOne.green > m.colorTwo.green){
        greenDiff = m.colorOne.green - m.colorTwo.green;
        greenDiff = greenDiff/static_cast<double>(m.maxIterations);
        greenDiff *= iteration;
        greenSmoosh = m.colorOne.green - greenDiff;
      } else if (m.colorOne.green < m.colorTwo.green){
        greenDiff = m.colorTwo.green - m.colorOne.green;
        greenDiff = greenDiff/static_cast<double>(m.maxIterations);
        greenDiff *= iteration;
        greenSmoosh = greenDiff + m.colorOne.green;
      } else if (m.colorOne.green == m.colorTwo.green){
        greenSmoosh = m.colorOne.green;
      }
      if (m.colorOne.blue > m.colorTwo .blue){
        blueDiff = m.colorOne.blue - m.colorTwo.blue;
        blueDiff = blueDiff/static_cast<double>(m.maxIterations);
        blueDiff *= iteration;
        blueSmoosh = m.colorOne.blue - blueDiff;
      } else if (m.colorOne.blue < m.colorTwo.blue){
        blueDiff = m.colorTwo.blue - m.colorOne.blue;
        blueDiff = blueDiff/static_cast<double>(m.maxIterations);
        blueDiff *= iteration;
        blueSmoosh = blueDiff + m.colorOne.blue;
      } else if (m.colorOne.blue == m.colorTwo.blue){
        blueSmoosh = m.colorOne.blue;
      }
      // cout << redSmoosh << " ";
      // cout << greenSmoosh << " ";
      // cout << blueSmoosh << " " << iteration << " ";

      output << static_cast<int>(redSmoosh) << " ";
      output << static_cast<int>(greenSmoosh) << " ";
      output << static_cast<int>(blueSmoosh) << " ";
    }
  }
    return 0;
}