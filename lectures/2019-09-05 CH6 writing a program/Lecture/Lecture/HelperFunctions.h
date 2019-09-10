#pragma once //C++ style cross file include prevention for
             //MOST (not all) compilers
#ifndef HELPER_FUNCTIONS_H //C style works with all compilers
#define HELPER_FUNCTIONS_H
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
		4. How do we deal with negative number?
		    Solution: Check first (and only first) char for '-' ...
	*/
#include <string>
using namespace std;

string readLine(string prompt);
int readInt(string prompt);

int toInt(string input)
{
	if (input.length() == 0)
	{
		throw exception{ "Empty string" };
	}

	//check char 0 for negative sign
	if (input.length() == '-')
	{

	}
	for (auto ch : input)
	{
		if (ch < '0' || ch > '9')
		{
			throw exception{ "bad input" };
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
#endif // !HELPER_FUNCTIONS_H
