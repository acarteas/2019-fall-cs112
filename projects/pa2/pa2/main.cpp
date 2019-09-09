/*This program needs to:
	1. Read input from a *.ppm file
	2. Sort the first three lines into variables
	3. Read four lines of data and keep them organized
	4. Print everything in order
	
	Next step: Build in functionality to find and print comments from the header of the file */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
	string format;
	int width;
	int height;
	int mpv;
	string inputData;
	string data;
	string comment;
	ifstream imgFile;

	imgFile.open("tinypix.ppm");

	imgFile >> format;
	imgFile >> width;
	imgFile >> height;
	imgFile >> mpv;

	while (imgFile.good())
	{
		getline(imgFile, inputData);
		data = data + inputData + "\n";
	}

	imgFile.close();

	cout << "Image Format: " << format << "\n"
		<< "Width: " << width << "\n"
		<< "Height: " << height << "\n"
		<< "Max Pixel Value: " << mpv << "\n"
		<< "Data: " << data;

	return 0;
}