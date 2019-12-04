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
#include "LinkedList.hpp"

int main(int argc, char* argv[])
{
	LinkedList<int> numbers{};
	for (int i = 0; i < 10; i++)
	{
		numbers.addValue(i);
	}
	numbers.removeValue(0);
	numbers.removeValue(4);
	numbers.removeValue(9);
	numbers.removeValue(234);
	return 0;
}