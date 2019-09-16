/*

	Author - Ryan Beck
	Version - 1.0
	Date - 9/16/2019

	PA2 now reads input from a file and prints it to the prompt with a certain format.


*/
#include <iostream>
#include <string>
#include <fstream>  // this is what allows us to look into and read. It also has properties to writeing out to files.
using namespace std;

int main()
{
	int i = 1;							//arbitrary int used to increment through our switch cases
	string s;							//arbitrary string used to store the current line when using getline
	ifstream read{"tinypix.ppm"};		//the opening of the reesource file using the reading operator - ifstream
	while (getline(read, s))
	{
		
		switch (i) {

		case 1:							
			cout << "Image Format: " << s << endl;			//printing of first line using our string
			break;

		case 2: {
			size_t o;										//an unsigned int that we will store our second half of the string in after seperation
			int w = stoi(s, &o);							//turning the first half of our string into a integer and storing the rest
			cout << "Width: " << w << endl;					//printing of second line using our newly aquired integer
			int l = stoi(s.substr(o));						//turing the second half of the string into an integer
			cout << "Length: " << l << endl;				//printing of third line using our newly aquired integer

			break;
		}
		case 3: {
			int v = stoi(s);								//turing our string into an integer
			cout << "Max Pixel Value: " << v << endl;		//printing of our fourth line using our newly aquired integer
			break;
		}
		case 4:
			cout << "Data:\n" << s << endl;					//printing of our fifth and sixth lines outputted as strings
			break;

		default:											//printing the rest of the lines as strings for however long the file is
			cout << s << endl;
			break;
		}
		
		i++;												// incrementing of our beginning arbitrary int to make this loop increment through the cases
	
	}
	return 0;
}
