#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
/*
signature: string -> void
purpose: expects a string which represent a file name and returns 
nothing,but has the side effect of printing to the screen with 
respective formatting. 
*/

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
