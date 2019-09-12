#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;






int main(void)
{
	ifstream myfile;
	string line1; 
	string line2;
	string line3;
	string line4;
	string line5;
	string line6;

	myfile.open("tinypix.ppm");
	
	//use getline outside the while loop for the first three line
	//Then while loop for the rest

	getline(myfile, line1);
	cout << "Image Format: " << line1 << endl;

	getline(myfile, line2, ' ');
	cout << "Width: " << line2 << endl;

	getline(myfile, line3);
	cout << "Height: " << line3 << endl;

	getline(myfile, line4, ' ');
	cout << "Max Pixel Value: " << line4 << endl;

	getline(myfile, line5, ' ');
	cout << "Data: " << line5 << endl;

	while (getline(myfile, line6))
	{
		cout << line6 << endl;
	}

	myfile.close();
	
	



	return 0;

}