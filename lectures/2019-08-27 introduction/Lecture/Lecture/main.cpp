#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//1. (p. 73) Prompt user for a string. Remove adjacent duplicate words.
//I I went to the the store this morning -> I went to the store this morning
string removeAdjacentDuplicates(string original)
{
	string current;
	string next;
	string result;
    istringstream iss;
    int wordcount = 0;

    iss.str (original);

    for (int i = 0; i < original.length() - 1; i++)  //tbis compares a signed int to an unsigned int, maybe revise
	{
	    if (original.find(' ', i)) {
	        wordcount++;
	    }
	}

    for (int j = 0; j < wordcount; j++)
    {   
        iss >> current;
        iss >> next;
        
        if (current == next) {
            result = result + " " + current;
        }
        else {
            result = result + " " + current + " " + next;
        }
    } 
	return result;
}

int main(void)
{
	cout << removeAdjacentDuplicates("I I went to the the store this morning");
}