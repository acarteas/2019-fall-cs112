#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "PrimeFinder.h"
#include "TestFunctions.h"
using namespace std;

int main()
{
	bool test_individual = true;
	bool test_range = true; 
	char continue_ind, continue_range;
	int individual_input, min_range, max_range;

	while (test_individual == true)
	{
		cout << "Enter An Integer To Test: " << endl;
		cin >> individual_input;
		cout << endl;
		isPrimeTest(individual_input);
		cout << endl;
		cout << "Do you want to continue testing? (Y/n) " << endl;
		cin >> continue_ind;
		cout << endl;
		if (continue_ind == 'Y' || continue_ind == 'y')
		{
			test_individual = true;
		}
		else if (continue_ind == 'N' || continue_ind == 'n')
		{
			test_individual = false;
		}
		else
		{
			throw invalid_argument{ "Error! Bad input. Not y or n." };
		}
	}

	while (test_range == true)
	{
		cout << "Enter a minimum number to test: " << endl;
		cin >> min_range;
		cout << endl;
		cout << "Enter a maximum number to test: " << endl;
		cin >> max_range;
		cout << endl;
		findPrimeInRange(min_range, max_range);
		cout << endl;
		cout << "Do you want to find prime numbers in another range? (Y/n)" << endl;
		cin >> continue_range;
		cout << endl;
		if (continue_range == 'Y' || continue_range == 'y')
		{
			test_range = true;
		}
		else if (continue_range == 'N' || continue_range == 'n')
		{
			test_range = false;
		}
		else
		{
			throw invalid_argument{ "Error! Bad input. Not y or n." };
		}
	}

	cout << "Ending Program....." << endl;
}