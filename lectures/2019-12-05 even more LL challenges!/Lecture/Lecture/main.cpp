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
	vector<int> numbers_vect{ 1, 2, 3, 4, 5, 6, 7 };
	vector<int> numbers_copy = numbers_vect; //C++ STL is smart, does deep copy
	numbers_copy[0] = 8;

	LinkedList<int> numbers{};
	
	for (int i = 0; i < 5; i++)
	{
		numbers.addValue(i);
	}
	//numbers.removeValue(0);
	//numbers.removeValue(4);
	//numbers.removeValue(9);
	//numbers.removeValue(234);

	////This is a shallow copy (for now)
	////It looks just the deep copy of vector.  We must always
	////be cautious when making copies of complex objects.

	////after adding copy constructor, this works as expected
	//LinkedList<int> numbers_ll_copy = numbers;
	//numbers_ll_copy.removeValue(1);

	////doesn't call copy constructor, instead calls "copy operator"
	//numbers = numbers_ll_copy;
	//numbers.removeValue(2);

	numbers.reverse();

	return 0;
}