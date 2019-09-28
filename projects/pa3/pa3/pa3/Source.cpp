#include <iostream>
#include <fstream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include <iomanip> //for making fancy couts and output to file
using namespace std;

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
		
	system("pause");


	fout.close();
	
	//location of where the file will go. 
	void ofstreamTemplate();
	{
		string outPutFile;
		cout << "What is the name of your output file?" << endl;
		cin >> outPutFile;
		ofstream output_file{ outPutFile };

		string newFile = outPutFile;


		output_file << fileName << outPutFile  << endl;

		cout << outPutFile;
		

		output_file.close();

	}

}