// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <sstream>
/*
string removeAdjacentDuplicatesV2(string original) {
	istringstream input{ original };
	ostringstream result{}
	string previous;
	while (input.good() == true) {
		string word;
		getline(input, word, " ");
		cout << word << endl;
		if (word != previous)
		{
			result << word << " ";
		}
		previous = word;
	}

	//put text into stream
	string formatted = result.str()
		return result.str()
}
*/
using namespace std;

string removeAdjacentDuplicates(string original)
{
	string previous;
	string current;
	string result;
	int index = 0;
	while (index < original.length())
	{
		int space_index = original.find(' ', index);
		current = original.substr(index, space_index - index);

		if (current != previous)
		{
			// add word
			result += current + " ";
		}
		if (space_index == -1) {
			index = original.length();
		}
		else
		{
			index = space_index + 1;
		}
		previous = current;
	}
	return result.substr(0, result.length() - 1);
}

int main(void)
{
	removeAdjacentDuplicates("I I went to the the store this morning");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
