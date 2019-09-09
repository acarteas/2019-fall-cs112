#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(void)
{
	ifstream inPix;
	inPix.open("C:\Users\bbc4\Desktop\bin\2019-fall-cs112\projects\pa2\pa2\tinypix.ppm");

	// This checks to see if tinypix.ppm was opened
	if (!inPix)
	{
		cerr << "Unable to open file tinypix.ppm";
		exit(1); //call system to stop
	}


	return 0;
}