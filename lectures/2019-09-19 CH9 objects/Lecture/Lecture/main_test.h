#pragma once
#ifndef MAIN_TEST_H
#define MAIN_TEST_H
#include "HelperFunctions.h"
#include <string>
#include <iostream>
using namespace std;

bool intTest(string input, int expected)
{
	try
	{
		int result = toInt(input);
		return result == expected;
	}
	catch (...)
	{
		return false;
	}
}

void runTest()
{
	cout << boolalpha;

	cout << "Testing toInt(\"\"): ";
	cout << !intTest("", 1234) << endl;

	cout << "Testing toInt(\"-\"): ";
	cout << !intTest("-", 0) << endl;

	cout << "Testing toInt(\".\"): ";
	cout << !intTest(".", 0) << endl;

	cout << "Testing toInt(\".1234\"): ";
	cout << intTest(".1234", 0) << endl;

	cout << "Testing toInt(\".abc\"): ";
	cout << !intTest(".abc", 0) << endl;

	cout << "Testing toInt(\"1234\"): ";
	cout << intTest("1234", 1234) << endl;

	cout << "Testing toInt(\"-1234\"): ";
	cout << intTest("-1234", -1234) << endl;

	cout << "Testing toInt(\"12-34\"): ";
	cout << !intTest("12-34", -1234) << endl;

	cout << "Testing toInt(\"-1234werwsdfswef\"): ";
	cout << !intTest("-1234werwsdfswef", -1234) << endl;

	cout << "Testing toInt(\"55.99\"): ";
	cout << intTest("55.99", 55) << endl;

	cout << "Testing toInt(\"55.99.22\"): ";
	cout << !intTest("55.99.22", 55) << endl;

	cout << "Testing toInt(\"-55.99\"): ";
	cout << intTest("-55.99", -55) << endl;
}


#endif