#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int main()
{


	//Get input & Output files
	string input_name;
	string output_file_name;
	cout << "Enter a PPM file to parse: ";
	getline(cin, input_name);
	cout << "Enter destination file: ";
	getline(cin, output_file_name);

	//Open the input file
	ifstream input{ input_name };

	//Open the output file
	ofstream output_file{ output_file_name };

	vector<string> lines{};
	if (input.is_open() == true)
	{
		while (input.good() == true)
		{
			string line;
			getline(input, line);
			lines.push_back(line);
		}
	}


	vector<string> vals{};
	for (int i = 3; i != lines.size(); i++)
	{
		string sentence = lines[i];
		istringstream iss(sentence);

		do
		{
			string sub;
			iss >> sub;
			vals.push_back(sub);
		} while (iss);
	}

	output_file << lines[0] << endl << lines[1] << endl << lines[2] << endl;

	for (int i = 0; i < vals.size(); i++)
	{
		if (vals[i] == "")
		{
			i++;

		}
		else
		{
			if ((i + 1) % 3 == 0)
			{
				output_file << 0 << endl;
			}
			else
			{
				output_file << vals[i] << endl;
			}
		}
	}
}