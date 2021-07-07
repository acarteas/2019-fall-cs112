#pragma once
#include <iostream>
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
	cout << "Testing toInt(\"1234\"):";
	cout << intTest("", 1234) <<endl;


}