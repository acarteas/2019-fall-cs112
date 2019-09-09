// Image Processor - PA2
// Peter Boster
// CS 112
// 09-01-2019

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// imageProcessor() --> Analyzes file "tinypix.ppm" and preforms special processing 
//                      based on the line of the file.

void imageProcessor(string input_file)
{
	string line;

	ifstream picdata;
	picdata.open(input_file.c_str());

	int count = 0;

	for (int count = 0; picdata.eof() == false; count++)
	{
		if (count == 0)
		{
			// First Line (Image Format):
			getline(picdata, line);
			cout << "Image Format: " + line << endl;
		}
		else if (count == 1)
		{
			// Second Line (Delimits the Two Integers):
			getline(picdata, line, ' ');
			cout << "Height: " + line << endl;
			getline(picdata, line);
			cout << "Width: " + line << endl;
		}
		else if (count == 2)
		{
			// Third Line (Max Pixel Value):
			getline(picdata, line);
			cout << "Max Pixel Value: " + line << endl;
			cout << "Data: " << endl;
		}
		else if (count >= 3)
		{
			// Rest of the Lines (Outputs Data):
			getline(picdata, line);
			cout << line << endl;
		}
	}
}

int main(void)
{
	string original_pic = "tinypix.ppm";
	string testpic_a = "testpic_a.ppm";
	string testpic_b = "testpic_b.ppm";

	cout << "Testing tinypix.ppm:" << endl;
	imageProcessor(original_pic);
	cout << "========================================" << endl;
	cout << endl;

	cout << "Testing testpic_a.ppm:" << endl;
	imageProcessor(testpic_a);
	cout << "========================================" << endl;
	cout << endl;

	cout << "Testing testpic_b.ppm:" << endl;
	imageProcessor(testpic_b);
	cout << "========================================" << endl;
	cout << endl;

}
