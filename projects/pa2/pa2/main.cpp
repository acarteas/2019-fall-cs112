#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(void)
{
	ifstream inPix;
	inPix.open("tinypix.ppm");
	string line;
	int counter = 0;
	string img_spec;
	int width, height = 0;
	int max_color = 0;

	// This checks to see if tinypix.ppm was opened
	if (!inPix.is_open())
	{
		cerr << "Unable to open file tinypix.ppm";
		exit(1); //call system to stop
	}

	while (getline(inPix, line))
	{
		counter++;
		if (counter == 1)
		{
			img_spec = line;
			cout << "Image Format: " << img_spec << endl;
		}
		if (counter == 2)
		{
			width = stoi(line.substr(0, line.find(" ")));
			height = stoi(line.substr(line.find(" ")+1,line.length()));
			cout << "Width: " << width << endl;
			cout << "Height: " << height << endl;
		}
		if (counter == 3)
		{
			max_color = stoi(line);
			cout << "Max Pixel Value: " << max_color << endl;
			cout << "Data: " << endl;
		}
		if (counter > 3)
		{
			cout << line << endl;
		}
	}


	return 0;
}