#include <iostream>
#include <string>
#include <sstream>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include "HelperFunctions.h"
using namespace std;

int main_sandbox(void)
{
	int result = readInt("Enter a number: ");

	int some_number; //is a C "object"
	string word; //this is a C++ object

	int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//error.  It may crash or it may do something unexpected. 
	//we don't know.
	cout << numbers[11] << endl;

	//C++ vector (magic array)
	//     <data type inside LT & GT>
	//vectors always start out as size 0
	vector<int> numbers_vect{};

	//resize to 10 to match C array
	numbers_vect.resize(10);

	//basic format for exception handling in C++
	try
	{
		//put as few commands in here as possible
		//those commands should be risky and related
		cout << numbers_vect.at(11) << endl;
	}
	//one or more catch blocks below with code how to handle
	catch (out_of_range ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	//equivalent to IF's ELSE (catches ALL exceptions)
	catch (...)
	{
		cout << "Something broke, don't know why!" << endl;
	}
	return 0;
}

int vector_practice(void)
{
	//                 C++ 11+ (modern) uses curly braces
	//                 for object instantiation
	vector<int> numbers{};

	//read numbers from keyboard until -1 is entered
	int user_input = 0;
	while (user_input != -1)
	{
		user_input = readInt("Enter a number (-1 to exit): ");

		//easiest and most convenient way to put things in vector
		numbers.push_back(user_input);
	}

	//print numbers to screen
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers.at(i) << endl;
	}

	//generic modern C++ for getting things out of a 
	//data container (e.g. vector, linked list, hashtable, etc.)
	for (auto item : numbers)
	{
		cout << item << endl;
	}

	return 0;
}

int main(void)
{
	//4. Word replacement(p. 125)
	vector<string> bad_words{ "foo", "bar", "baz" };
	bad_words.push_back("foobar");

	string sentence = "The words foo and bar are frequenlty used in learning to program.";
	
	//split sentence into words
	istringstream pieces{ sentence };
	while (pieces.good() == true)
	{
		string word;
		getline(pieces, word, ' ');

		//search bad word list
		for (auto bad_word : bad_words)
		{
			if (word == bad_word)
			{
				cout << word << " was found in sentence." << endl;
			}
		}
	}

	return 0;
}