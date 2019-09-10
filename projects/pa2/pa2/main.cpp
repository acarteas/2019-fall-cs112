#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


void image_file(string file_name)
{
	string line_to_read;
    
    ifstream file_to_read;
    
	file_to_read.open(file_name);
	getline(file_to_read, line_to_read);
	cout << "Image Format: " << line_to_read << endl;
	getline(file_to_read, line_to_read, ' ');
	cout << "Width: " << line_to_read << endl;
	getline(file_to_read, line_to_read);
	cout << "Height: " << line_to_read << endl;
	getline(file_to_read, line_to_read);
	cout << "Max Pixel Value: " << line_to_read << endl;
	cout << "Data: " << endl;
	while(!file_to_read.eof())
	{
		getline(file_to_read, line_to_read);
		cout << line_to_read << endl;
	}
		 
	file_to_read.close();
}

int main(void)
{
	image_file("tinypix.ppm");

	return 0;
}
