#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//1. (p. 73) Prompt user for a string. Remove adjacent duplicate words.
//I I went to the the store this morning -> I went to the store this morning

//v2 - attempting to optimize and fix issues with sentences under four words as well as sentences without duplicates

string removeAdjacentDuplicates(string original)
{
	string current;
	string next;
	string last;
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
	
	iss >> current;
    iss >> next;

    do {   
        wordCount--;
        
        if (current == next) {
            if (current != last) {
                result = result + current + " ";
                iss >> current;
            }
            iss >> next;
            wordCount--;
        }
        else {
            result = result + current + " " + next + " ";
        }
        last = current;
        current = next;
        iss >> next;
    } 
    while (wordCount > 0);
    
	return result;
}

int main(void)
{
	cout << removeAdjacentDuplicates("I I I I like like like cats cats cats cats cats very much much much much"); //edited string to test more duplicate scenarios
}