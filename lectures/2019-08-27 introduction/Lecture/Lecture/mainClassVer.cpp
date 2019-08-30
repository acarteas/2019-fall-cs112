#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string removeAdjacentDuplicatesV2(string original)
{
    istringstream input{original};
    ostringstream result{};
    string previous;
    while (input.good() == true)
    {
        string word;
        getline(input, word, ' ');
        if(word != previous)
        {
            result << word << " ";
        }
    }

    string formatted = result.str();
    formatted = formatted.substr(0, formatted.length() - 1);
    return formatted;
}

/**
//1. (p. 73) Prompt user for a string. Remove adjacent duplicate words.
//I I went to the the store this morning -> I went to the store this morning
string removeAdjacentDuplicates(string original)
{
	string previous;
	string current;
	string result;
    int index = 0;

    while (index < original.length())
    {
        int space_index = original.find(' ', i);

        //substring - a sequence of adjacent characters within an existing string
        string current = original.substr(index, space_index - index);
        
        if (current != previous)
        {
            result += current + " ";
        }

        if (space_index == -1)
        {
            index = original.length();
        }
        else
        {
            index = space_index + 1;
        }

        previous = current;
    }
	return result.substring(0, result.length() - 1);
}
**/
int main(void)
{
	cout << removeAdjacentDuplicatesV2("I I went to the the store this morning");
}