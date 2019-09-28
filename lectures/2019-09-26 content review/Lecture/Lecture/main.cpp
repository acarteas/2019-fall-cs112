#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include <iomanip> //for making fancy couts and output to file
#include "HelperFunctions.h"
#include "FileHelpers.h"
#include "PpmDocument.hpp"

/*
Things to talk about
	• Writing to files
	• Interacting with user (cin / getline)
	• Istringstream / string manipulation

TODO: interactive programming challenges
*/

void questionsAboutPointers()
{
	//this is asking the OS for memory
	ostream* some_string = new ostringstream{};
	ostream* some_file = new ofstream{ "test.txt" };

	//depending on whether or not the request was successful
	//some_string will either be an instance of istringstream
	//OR null
	if (some_string == nullptr)
	{
		//program fail, out of memory
	}

	//what is in the some_string box is either nullptr (000000)
	//or some memory address

	//how do we go from memory address to istringstream
	//option 1: dereference the pointer
	(*some_string) << "hello";

	//option 2: use the arrow
	some_string->operator<<("world");

	//whenever you use NEW, you need to use DELETE
	//this gives the memory back to the OS
	delete some_string;
	delete some_file;
}
void ofstreamTemplate()
{
	//                    whatever file name you want
	ofstream output_file{ "test.txt" };

	//from here to the end of the program, you can now use
	//our output file JUST like you would use cout.
	//In other words, replace COUT with the name of your ofstream
	//variable (e.g. output_file)
	output_file << "Hello" << endl;
	output_file << "World!  This is a test 1234" << 234 << endl;

	//before your program ends, be sure to close your file!
	output_file.close();

}
void ppmPractice()
{
	srand(time(NULL));

	//create a bunch of random pixel data
	vector<int> image{};

	int height = 100;
	int width = 200;
	for (int i = 0; i < height * width; i++)
	{
		image.push_back(rand() % 256);
	}

	ofstream output_image{ "test.ppm" };

	//output header stuff
	output_image << "P3" << endl << width << " " << height << endl
		<< "255" << endl;

	//output data
	for (int i = 0; i < image.size(); i++)
	{
		output_image << setw(3) << right << setfill('0');
		output_image << image[i] << setw(3) << setfill(' ') << " ";
	}

	output_image.close();


	//Adam's only regular use with iomanip
	cout << "Result: " << false << endl;
	cout << boolalpha;
	cout << "Result: " << false;

}

string stringReplace(string content, string search, string replace)
{
	int position = content.find(search);

	//if found?
	while (position != string::npos)
	{
		content.replace(position, replace.length(), replace);
		position = content.find(search, position);
	}
	return content;
}

int main(int argc, char* argv[])
{
	string text = "this is a test.  this is another sentence";
	text = stringReplace(text, " ", "_");
	cout << text << endl;
	return 0;
}