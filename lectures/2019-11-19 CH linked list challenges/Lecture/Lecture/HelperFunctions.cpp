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
