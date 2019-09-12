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

	// First Line (Image Format):
	getline(picdata, line);
	cout << "Image Format: " << line << endl;
	
	// Second Line (Delimits the Two Integers by a space (\' \'):
	getline(picdata, line, ' ');
	cout << "Height: " << line << endl;
	getline(picdata, line);
	cout << "Width: " + line << endl;
	
	
	
	// Third Line (Max Pixel Value):
	getline(picdata, line);
	cout << "Max Pixel Value: " << line << endl;
	cout << "Data: " << endl;
	
	while (picdata.eof() == false)
	{
		// Rest of the Lines (Outputs Data):
		getline(picdata, line);
		cout << line << endl;
	}

	picdata.close();
}

int main(void)
{
	imageProcessor("tinypix.ppm");
}