#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
	
//I I went to the the string this morning -> I went to the store this morning

//signature: string -> string
//purpose: expects a string and a side-effect of asking for the string from 
//the user, and returns that string(s) omitting the adjacent characters

string RemoveAdjacentDuplicates(string original)
{
	string current;
	string next;
	string result;
	for (int i = 0; i < original.length() - 1; i++)
	{
		string temp = original.substr(0, i);
			cout<< i <<endl;
	} 
	return result;
}

int main(void)
{

}
