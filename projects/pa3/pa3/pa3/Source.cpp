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
string line4;


//function to go through a file and change every 3rd thing into a 0

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

	cout << "Enter a name of a .ppm file.(include extension)" << endl;
	cin >> fileName;

	ifstream fout;
	fout.open(fileName);


	if (fout.good())
	{

		string line1;
		getline(fout, line1);
		string line2;
		getline(fout, line2);
		string line3;
		getline(fout, line3);

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
		

	//changing red to 0 
	

	fout.close();

	//location of where the file will go. 
	void ofstreamTemplate();
	{
		string outPutFile;
		cout << "What is the name of your output file?" << endl;
		cin >> outPutFile;
		ofstream output_file{ outPutFile };

		string newFile = outPutFile;

		output_file.open(outPutFile);


		output_file << line1 << endl
			<< line2 << endl
			<< line3 << endl;


		output_file.close();

	}

}