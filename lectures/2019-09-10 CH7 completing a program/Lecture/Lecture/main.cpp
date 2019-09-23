#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include "HelperFunctions.h"


#if _DEBUG
#include "main_test.h"
//put debug includes here

#endif
using namespace std;


/*
Tasks:
1. Implement testing harness for our function
2. Allow toggle between "test" mode via CL
3. Pass all test cases
*/
int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		string arg{ argv[1] };
		if (arg == "-test")
		{
//only run if in debug
#if _DEBUG
			runTest();
#endif
		}
		else
		{
			cout << "unknown operation" << endl;
		}
	}
	else
	{
		cout << "Normal main();" << endl;
	}
	return 0;
}