#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
#ifdef JARVIS
  srand(0);
#else
  srand(time(NULL));
#endif

  // Call your functions to play your game here...

  return 0;
}
