#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//1. (p. 73) Prompt user for a string. Remove adjacent duplicate words.
//I I went to the the store this morning -> I went to the store this morning
string removeAdjacentDuplicates(string original)
{
	string current;
	string currentOld;
	string next;
	string nextOld;
	string result;
    istringstream iss;
    int wordCount = 0;

    iss.str (original);

    for (int i = 0; i < original.length() - 1; i++)  //tbis compares a signed int to an unsigned int, maybe revise
	{
	    if (original[i] == ' ') {
	        wordCount = wordCount + 1;
	    }
	}

    for (int j = 0; j < wordCount; j++)
    {   
        iss >> current;
        iss >> next;
        
        if (current == next) {
            result = result + current + " ";
        }
        else if (current == nextOld) {
            result = result + next + " ";
        }
        else {
            result = result + current + " " + next + " ";
        }
        
        wordCount--;
        
        currentOld = current;
        nextOld = next;
    } 
	return result;
}

int main(void)
{
	cout << removeAdjacentDuplicates("I I went to to the the store this morning");
}