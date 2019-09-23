#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include "HelperFunctions.h"
#include "FileHelpers.h"

/*
Tasks:
1. Introduced PA3
2. Talked about book
3. Implement base PA2 using functions
*/
int main(int argc, char* argv[])
{
	vector<string> data = readFile("tinypix.ppm");

	cout << "Image format: " << data[0] << endl;
	istringstream second_row{ data[1] };
	string temp_data;

	//PA #3 HINT: consider how to repeat this process
	//to split up your data into individual integers
	getline(second_row, temp_data, ' ');
	int width = stoi(temp_data);
	getline(second_row, temp_data, ' ');
	int height = stoi(temp_data);
	cout << "Width: " << width << endl
		<< "Height: " << height << endl;

	//image format
	cout << "Image format: " << data[2] << endl;
	
	//data rows
	cout << "data: " << endl;
	for (int i = 3; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}

	//label each row
	for (int i = 0; i < data.size(); i++)
	{
		if (i % 2 == 0)
		{
			cout << "even: " << data[i] << endl;
		}
		else
		{
			cout << "odd: " << data[i] << endl;
		}

	}


	return 0;
}