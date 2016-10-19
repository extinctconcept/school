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

  // Read config file contents into MandelbrotConfig struct instance
  if (input.is_open())
    {
      while ( getline (input,line) )
      {
        cout << line << '\n';
      }
      input.close();
    }
  // Compute and write specified mandelbrot image to PPM file

  return 0;
}
