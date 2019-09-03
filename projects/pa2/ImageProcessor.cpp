// Image Processor - PA2
// Peter Boster
// CS 112
// 09-01-2019

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// imageProcessor()

void imageProcessor()
{
	string line;

	ifstream picdata;
	picdata.open("tinypix.ppm");

	int count = 0;

	for (int count; (count < 7); count++)
	{
		if ((picdata.eof() == true))
		{
			// Tests If File Ends (If End of File, End the Loop):
			count = 7;
		}
		else if (count == 0)
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
	imageProcessor();
}
