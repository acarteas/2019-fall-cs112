#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

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
	ofstream file_to_write;

	file_to_read.open(file_name);

	cout << "Enter the name of the file you wish to open: " << endl;
		getline(cin, file_name);
	cout << "Enter the name of the file you wish to write to: " << endl;
		getline(cin, file_name);
		
	while (!file_to_read.eof())
	{
		int a[24];
		getline(file_to_read, line_to_read); //prompts user for file name
		vector<int> file_vector;
	for (int i=0; i < 24; i++)
		{
			if (		i % 3 == 0)
			{
				a[i] = 0;
				cout << line_to_read << endl;
			}

		}
	
	}

	file_to_read.close();
}


int main(void)
{
	image_file("tinypix.ppm");

	return 0;
}



