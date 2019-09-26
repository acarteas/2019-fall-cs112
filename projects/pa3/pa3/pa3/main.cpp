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

	/*cout << "Enter the name of the output file: ";
	cin >> new_file;
	cout << "You entered: " << new_file << endl;

	cout << "Enter an absolute path where you want the new file to be stored: ";
	cin >> path;
	cout << "You entered: " << path << endl;*/


	// opens the file that the user provided -->
	ifstream file(file_name);
	vector<string> ender{}; // vector for file content

	if (file.is_open() == true) // if the file is open..
	{
		string myline;
		// push contents of file to a vector
		while (file.good() == true)
		{
			getline(file, myline);
			ender.push_back(myline);
		}
		// grab width and height
		istringstream row2{ ender[1] };
		string temp;

		// output all header elements before modification
		cout << "Image Format: " << ender[0] << endl;
		getline(row2, temp, ' ');
		int width = stoi(temp);
		getline(row2, temp, ' ');
		int height = stoi(temp);
		cout << "Width: " << width << endl
			<< "Height: " << height << endl
			<< "Max Color Value: " << ender[2] << endl;
	}
	file.close(); // close the file now that its contents are stored to a vector
	return ender;
}

int zeroEveryThird(vector<string> data)
{

	data.erase(data.begin(), data.begin()+3);
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			if (data[i][j] != ' ')
			{
				data.;
			}
			else
			{
				cout << data[i][j];
			}
		}
    }
	return 0;
}



int main()
{
	zeroEveryThird(getFile());
	
}