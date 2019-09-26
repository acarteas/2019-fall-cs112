#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "PrimeFinder.h"
using namespace std;

bool isPrime(int test_int)
{
	bool is_int_prime = false;

	if (test_int < 0)
	{
		throw invalid_argument{ "Error! Bad input. Negative input." };
	}
	else if (test_int == 0)
	{
		throw invalid_argument{ "Error! Bad input. 0 is neither prime nor composite." };
	}
	else if (test_int == 1)
	{
		throw invalid_argument{ "Error! Bad input. 1 is neither prime nor composite." };
	}
	else if (test_int == 2)
	{
		is_int_prime = true;
	}
	else
	{
		for (int i = 2; i < test_int; i++)
		{
			if (test_int % i == 0)
			{
				is_int_prime = false;
				break;
			}
			else
			{
				is_int_prime = true;
			}
		}

		if (is_int_prime == true)
		{
			return true;
		}
		else if (is_int_prime == false)
		{
			return false;
		}
		else
		{
			throw invalid_argument{ "Error! Bad input. Neither prime nor not prime." };
		}
	}
}

void findPrimeInRange(int min_input, int max_input)
{
	vector<int> prime_munbers_in_range{};
	vector<int> non_prime_numbers_in_range{};
	for (int i = min_input; i < max_input; i++)
	{
		if (isPrime(i) == true)
		{
			prime_munbers_in_range.push_back(i);
		}
		else if (isPrime(i) == false)
		{
			non_prime_numbers_in_range.push_back(i);
		}
		else
		{
			throw invalid_argument{ "Error! Bad input. Bad integer in range" };
		}
	}

	cout << "Prime Numbers From " << min_input << " To " << max_input << ": " << endl;

	for (int j = 0; j < prime_munbers_in_range.size(); j++)
	{
		cout << prime_munbers_in_range[j] << endl;
	}
}