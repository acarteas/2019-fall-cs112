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

    do {   
        iss >> current;
        iss >> next;
        
        wordCount--;
        
        if (current == next) {
            if (current != currentOld && next != currentOld && next != nextOld) {
                result = result + current + " ";
            }
            wordCount--;
        }
        else if (current == nextOld) {
            result = result + next + " ";
            wordCount--;
        }
        else if (wordCount > 0) {
            result = result + current + " " + next + " ";
        }
        
        currentOld = current;
        nextOld = next;
    } 
    while (wordCount > 0);
    
	return result;
}

int main(void)
{
	cout << removeAdjacentDuplicates("I I went went went to to to to the the the the the store this morning morning morning"); //edited string to test more duplicate scenarios
}