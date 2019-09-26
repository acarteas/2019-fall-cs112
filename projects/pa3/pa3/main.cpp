/*  Changelog
	
	Current
	
	This program needs to:
	1. Prompt user for file to manipulate
	2. Prompt user for output filename
	3. Change every third number of the data to zero, starting with the first data point

	v01
	1. Read input from a *.ppm file
	2. Sort the first three lines into variables
	3. Read four lines of data and keep them organized
	4. Print everything in order

	Next step: Build in functionality to find and print comments from the header of the file ??*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;



int main(void)
{
	string format;
	string fileName;
	string outputName;
	int width;
	int height;
	int mpv;
	string inputData;
	vector<string> data;
	ifstream imgFile;
	ofstream imgEdit;
	istringstream iss;
	//string dummy;
	//string dummy2;
	//string toZero;
	//string editLine;
	//istringstream dummy;
	//string currentLine;
	//string currentNum;

	cout << "Enter source file: ";
	cin >> fileName;
	cout << "Enter destination file: ";
	cin >> outputName;

	imgFile.open(fileName);

	imgFile >> format;
	imgFile >> width;
	imgFile >> height;
	imgFile >> mpv;

	while (imgFile.good())
	{
		getline(imgFile, inputData);
		data.push_back(inputData);
	}

	imgFile.close();

	for (int j = 0; j < data.size(); j++)
	{
		int ticker = 3;

		string editLine = data[j];

		for (int k = 0; k < editLine.length(); k++)
		{
			if (editLine[k] != ' ' && editLine[k + 1] != ' ' && ticker % 3 == 0)
			{
				editLine[k] = ' ';
			}
			else if (editLine[k] != ' ' && editLine[k + 1] == ' ')
			{
				if (ticker % 3 == 0)
				{
					editLine[k] = '0';
				}
				ticker++;
			}
		}
		data[j] = editLine;
	}

	imgEdit.open(outputName);
	imgEdit << format << "\n";
	imgEdit << width << " ";
	imgEdit << height << "\n";
	imgEdit << mpv;
	for (int i = 0; i < data.size(); i++)
	{
		imgEdit << data[i] << "\n";
	}
	
	imgEdit.close();

	cout << "Program complete";

	return 0;
}