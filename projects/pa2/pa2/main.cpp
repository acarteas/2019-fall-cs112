#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <fstream>
#include <istream>

using namespace std;
/*
string my_Test(string sentence)
{
	istringstream input{ sentence };
	ostringstream more{};
	while (input.good() == true)
	{
		string word;
		getline(input, word, ' ');
		//more << word + "g" << " ";
		//string output = more.str();
		//cout << output << endl;
		cout << word << endl;
	}
	return "done";
}
*/
string my_Test2(string original)
{
	int index = 0;
	string final;
	while (index < original.length()) 
	{
		int space_index = original.find(' ', index); // find the first space index number
		string word;
		word = original.substr(index, space_index - index); // take a substr of original from 0 or the next space and assignit to word
		cout << word << endl; //print that word
		
		if (space_index == -1)
		{
			index = original.length();
		}
		else
		{
			index = space_index + 1;
		}

		
		final = word;
	}
	return final;
}

int main()
{
	string new_string = my_Test2("this is a sentence blah blah blah");
}