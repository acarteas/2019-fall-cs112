#include <iostream>
#include <fstream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <exception>
#include <vector> 
#include <iomanip> 
using namespace std;

string line1;
string line2;
string line3;



vector<string> readFile(ifstream& fileName)
{
	vector<string> result{};

	//make sure file is open
	if (fileName.is_open() == true)
	{
		string line;

		//loop while file is good (not EOF, not error, etc.)
		while (fileName.good() == true)
		{
			getline(fileName, line);

			//add to end of vector
			result.push_back(line);
		}
	}
	return result;
}

vector<string> readFile(const string& file_name)
{
	ifstream input{ file_name };
	vector<string> result = readFile(input);
	input.close();
	return result;
}




int main()
{
	string fileName;
	string newOutputFileName;

	cout << "Enter a name of a .ppm file.(include extension)" << endl;
	cin >> fileName;
	cout << "Enter a name of a output .ppm file" << endl;
	cin >> newOutputFileName;

	ifstream fin;
	fin.open(fileName);

	if (fin.good() == true)
	{		
		string line1;
		getline(fin, line1);
		string line2;
		getline(fin, line2);
		string line3;
		getline(fin, line3);

		cout << line1 << endl
			<< line2 << endl
			<< line3 << endl;
	}
	else
	{
		cout << "Could not open file" << endl;
		return 1;
	}



	vector<string> fileBeingChanged = readFile(fileName);
	vector<int> stringBeingChanged;

	
	//creating a function to change string to integers
	int count = 0;

	for (int i = 3; i < fileBeingChanged.size(); i++)
	{
		istringstream line{ fileBeingChanged[i] };
		while (line.good() == true)
		{
			string value;

			getline(line, value, ' ');
			if (value.length() > 0 && value != "/n")
			{
				stringBeingChanged.push_back(stoi(value));
			}
		}
	}

	for (int i = 0; i < fileBeingChanged.size(); i += 3)
	{
		stringBeingChanged[i] = 0;
	}
		

	
	fin.close();

	//location of where the file will go. 

		
	ofstream output_file{ newOutputFileName };

	output_file
		<< line1 << endl
		<< line2 << endl
		<< line3 << endl;

	

	for (int i = 0; i < stringBeingChanged.size(); i++)
	{
		output_file << stringBeingChanged[i] << ' ';
	}
				
	
	output_file.close();

	return EXIT_SUCCESS;

	

}