/************************
* A#: A01224769
* Course: CS1400
* Section: 7
* HW#: 7
***********************/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAXINTESITY = 256;

struct Color
{
  int red;
  int green;
  int blue;
};

void smoosh(int rows, int cols, Color lColor, Color rColor, string filename);

int main()
{
  int rows;
  int cols;
  string filename;
  Color lColor;
  Color rColor;
  lColor.red;
  lColor.green;
  lColor.blue;
  rColor.red;
  rColor.green;
  rColor.blue;

  cout << "Left color: ";
  cin >> lColor.red >> lColor.green >> lColor.blue;

  cout << "Right Color: ";
  cin >> rColor.red >> rColor.green >> rColor.blue;


  cout << "Height: ";
  cin >> cols;
  cout << "Width: ";
  cin >> rows;
  cout << "File Name: ";
  cin >> filename;
  smoosh(rows, cols, lColor, rColor, filename);

  return 0;
}

void smoosh(int rows, int cols, Color lColor, Color rColor, string filename)
{
  // cout << lColor.red << " " << rColor.red;
  ofstream output;
  output.open(filename.c_str());
  output << "P3\n";
  output << rows <<" "<< cols << "\n255\n";
  for (int i = 0; i < cols; ++i){
    float redSmoosh = lColor.red;
    float greenSmoosh = lColor.green;
    float blueSmoosh = lColor.blue;
    float redDiff;
    float greenDiff;
    float blueDiff;
    for (int j = 0; j < rows; ++j){
      if (lColor.red > rColor.red){
        redDiff = lColor.red - rColor.red;
        redDiff = redDiff/static_cast<float>(rows);
        redSmoosh -= redDiff;
      } else if (lColor.red < rColor.red){
        redDiff = rColor.red - lColor.red;
        redDiff = redDiff/static_cast<float>(rows);
        redSmoosh += redDiff;
      } else if (lColor.red == rColor.red){
        redSmoosh = lColor.red;
      }
      if (lColor.green > rColor.green){
        greenDiff = lColor.green - rColor.green;
        greenDiff = greenDiff/static_cast<float>(rows);
        greenSmoosh -= greenDiff;
      } else if (lColor.green < rColor.green){
        greenDiff = rColor.green - lColor.green;
        greenDiff = greenDiff/static_cast<float>(rows);
        greenSmoosh += greenDiff;
      } else if (lColor.green == rColor.green){
        greenSmoosh = lColor.green;
      }
      if (lColor.blue > rColor.blue){
        blueDiff = lColor.blue - rColor.blue;
        blueDiff = blueDiff/static_cast<float>(rows);
        blueSmoosh -= blueDiff;
      } else if (lColor.blue < rColor.blue){
        blueDiff = rColor.blue - lColor.blue;
        blueDiff = blueDiff/static_cast<float>(rows);
        blueSmoosh += blueDiff;
      } else if (lColor.blue == rColor.blue){
        blueSmoosh = lColor.blue;
      }

      output << static_cast<int>(redSmoosh) << " ";
      output << static_cast<int>(greenSmoosh) << " ";
      output << static_cast<int>(blueSmoosh) << " ";
    }
  }
}
