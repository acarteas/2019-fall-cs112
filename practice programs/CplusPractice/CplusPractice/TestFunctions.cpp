#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "PrimeFinder.h"
#include "TestFunctions.h"
using namespace std;

void isPrimeTest(int test_int)
{
	if (isPrime(test_int) == true)
	{
		cout << "Testing: " << test_int << endl;
		cout << endl;
		cout << test_int << " is a prime number.";
	}
	else if (isPrime(test_int) == false)
	{
		cout << "Testing: " << test_int << endl;
		cout << endl;
		cout << test_int << " is not a prime number." << endl;
	}
	else
	{
		throw invalid_argument{ "Error! Bad input. Neither prime nor not prime." };
	}
}