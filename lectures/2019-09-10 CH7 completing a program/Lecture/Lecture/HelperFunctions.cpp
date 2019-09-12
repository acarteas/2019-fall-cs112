#include "HelperFunctions.h"
#include <iostream>
#include <exception>
using namespace std;
string readLine(string prompt)
{
	cout << prompt;
	string line;
	try
	{
		getline(cin, line);
	}
	catch (ios_base::failure ex)
	{
		cout << "Error reading from keyboard: " << ex.what() << endl;
	}

	return line;
}

int readInt(string prompt)
{
	string result = readLine(prompt);
	int number = -1; //define outside of try to maintain
					 //scope
	bool is_valid_number = false;
	while (is_valid_number == false)
	{
		try
		{
			number = stoi(result);

			//this line executes only when stoi succeeds
			is_valid_number = true;
		}
		catch (invalid_argument ex)
		{
			result = readLine("Please enter a valid integer.\n");
		}
		catch (out_of_range ex)
		{
			result = readLine("Number is too big.\n");
		}
		catch (...)
		{
			cout << "Something really bad happened." << endl;
		}
	}

	return number;
}

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
		4. How do we deal with negative numbers?
			Solution: check first (and only first) char for '-'.
					  If negative, remember with variable, multiply by
					  -1 at end of program.
	*/
	//good practice to place "state variables" at top of function
	bool is_negative = false;
	bool has_decimal = false;

	//empty string check
	if (input.length() == 0)
	{
		throw exception{ "Empty string." };
	}

	//check char 0 for negative sign
	if (input[0] == '-')
	{
		//remove negative sign from string
		input = input.substr(1);
		is_negative = true;
	}

	//if, after pulling substring is there more string left?
	if (input.length() == 0)
	{
		throw exception{ "Empty string." };
	}

	for (auto ch : input)
	{
		//one decimal is okay, 2 is invalid
		if (ch == '.' && has_decimal == false)
		{
			has_decimal = true;
		}
		else if (ch < '0' || ch > '9')
		{
			throw exception{ "bad input" };
		}
	}

	//grab only whole number component of number if we were given a
	//decimal (e.g. 1234.5678 -> 1234
	if (has_decimal)
	{
		int decimal_location = input.find('.');
		if (decimal_location == 0)
		{
			if (input.length() == 1)
			{
				throw exception{ "Invalid string." };
			}

			//a number consisting of just a decimal is INT 0
			return 0;
		}
		input = input.substr(0, decimal_location);
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

	//apply negative if needed
	if (is_negative == true)
	{
		result *= -1;
	}

	return result;
}