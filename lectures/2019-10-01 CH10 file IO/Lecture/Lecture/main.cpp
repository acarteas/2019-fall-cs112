#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include <iomanip> //for making fancy couts and output to file
#include "HelperFunctions.h"
#include "FileHelpers.h"
#include "PpmDocument.hpp"

int main(int argc, char* argv[])
{
	string ppm_name = "tinypix.ppm";
	PpmDocument doc;
	try
	{
		doc = PpmDocument{ ppm_name };
	}
	catch (...)
	{
		cout << "Could not process file...";
	}
	
	ofstream output{ "output.ppm" };
	output << doc;
	output.close();

	cout << doc << endl;
	return 0;
}