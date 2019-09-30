#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <fstream>
#include <istream>
#include <vector>

using namespace std;


/*
signature: void -> vector string
prompts the user for a file name, output file name, and path; puts file contents into a vector,
writes header info to console
*/
vector<string> getFile(void)
{
	// prompt user for a file name, an absolute path to where the file will be saved, and a new file name...
	string file_name;
	string new_file;
	string path;
	cout << "Enter the name of the file you wish to modify with its extension: ";
	cin >> file_name;
	cout << "You entered: " << file_name << endl;


	// opens the file that the user provided -->
	ifstream file(file_name);
	vector<string> data{}; // vector for file content

	if (file.is_open() == true) // if the file is open..
	{
		string myline;
		while (file >> myline)
		{
			data.push_back(myline); // push all elements to individual items in vector of strings
		}
		cout << "file stored to vector." << endl;
		// grab header info
		string width;
		string height;
		string format;
		string M_value;
		width = data[1];
		height = data[2];
		format = data[0];
		M_value = data[3];
		// print header info
		cout << "Format: " << format << endl
			 << "Width: " << width << endl
			 << "Height: " << height << endl
			 << "Max Color Value: " << M_value << endl;
	}
	file.close(); // close the file now that its contents are stored to a vector
	return data;
}

int zeroEveryThird(vector<string> data)
{
	string new_file;
	string path;
	cout << "Enter the name of the output file: ";
	cin >> new_file;
	cout << "You entered: " << new_file << endl;

	cout << "Enter an absolute path where you want the new file to be stored: ";
	cin >> path;
	cout << "You entered: " << path << endl;
	path = path + new_file;// concatenate path and file name for ofstream constructor
	cout << path << endl;

	ofstream output_img(path); // initialize output stream

	for (int i = 4; i < data.size(); i+=3)
	{
		data[i] = '0'; // change every third
    }

	for (int i = 0; i < data.size(); i += 1) 
	{
		output_img << data[i] << endl; // output entire vector to new file
	}
	output_img.close();
	return 0;
}

int main()
{
	zeroEveryThird(getFile());
}