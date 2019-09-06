#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include "HelperFunctions.h"
using namespace std;

int toInt(string input)
{
	/*
	Considerations:
		1. Is it possible to convert input into an INT
			(does the string contain only numbers?)
			a. How do we tell this?
			   Solution: use ASCII table values to filter out
			             bad input
		2. How do we convert a CHAR into an INT?
			Solution: subtract '0' from each character
		3. How do we assign a proper weight to each individual INT?
			Solution: track the "10s place" of each digit using
			          string length as a starting position
	*/
	for (auto ch : input)
	{
		if (ch < '0' || ch > '9')
		{
			throw exception{"bad input"};
		}
	}

	//If we're here, we know for absolute certainty that the string
	//we have is an INT.  In Math/CS, this is called an invariant
	//Invariant: what we know must be true
	int result = 0;
	int multiplier = pow(10, input.length() - 1);
	for (auto ch : input)
	{
		int digit = (ch - '0') * multiplier;
		result += digit;
		multiplier /= 10;
	}

	return result;
}

int main(void)
{
	double d_num = 123.456;

	//this is a cast.  Put the type you want to convert into
	//in parenthesis.  Place that next to the variable that you
	//want to convert.
	int i_num = (int)d_num;
	char c = (char)i_num;
	double a_num = (double)c;

	//Fun aside: look into bit shifting
	int test = 10 >> 1;

	//asside: store 2 numbers in a single INT
	int two_num = 123;
	two_num = (two_num << 8) | 57;

	//bitwise AND (not the best)
	int first_num = ((255 << 8) & two_num) >> 8;

	//w/o bitwise AND (better);
	first_num = two_num >> 8;
	int second_num = 255 & two_num;

	//task: parse integers
	//e.g. "56" => 56
	cout << toInt("546") + 5 << endl; //pass
	//toInt("4234safdsdf234"); //fail
	//toInt("234.3"); //fail; should we support this?
	return 0;
}