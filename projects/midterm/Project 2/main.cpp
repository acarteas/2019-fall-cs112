#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>


  
using namespace std;



void readFile(string file_name)
{
	ifstream myFile;
	cout << "enter filename:  " << endl;
	cin >> file_name;

	myFile.open(file_name);

	if (!myFile)
	{
		cout << "Not a file name!" << endl;
	}

	
	vector<string> fileContents;

	while (myFile.good() == true)
	{

		string line;
		fileContents.push_back(line);
	}

	for (int i= 1; i < fileContents.size(); i++)
	{

		cout << "Contents " << fileContents[i] << endl;

	}




	myFile.close();





}
int main()
{

	/*ifstream  myFile;


	string x;
	cout << "Enter source File:" << endl;
	cin >> x;
	cout << "Enter source File: " << x << endl;

	myFile.open(x);

	if (!myFile)
	{
		cout << "Not open" << endl;
		return 0;
	}*/

















	/*vector<string> data;
		while (myFile.good() == true)
		{
			string line;
			getline(myFile, line);
			data.push_back(line);
		}
		for (int i = 3; i < data.size(); i++)
		{
			cout << "Orginal File Contents"<< data[i] << endl;

			for (int j = 0; j < 3; j++)
			{
				string New_data = data[i];
				//cout << (New_data % 3) << endl; Will not accept the mod function

			}
		}
		myFile.close();
}



*/

	return 0;

}
	



	//string y;
	//cout << "Enter destination file:" << endl;
	//cin >> y;
	//cout << "Enter source File " << x << endl;

	//cout << "Program Complete." << endl;

	/*
	myFile -> string  (I want to make a copy of the orginal file )
	

	(DONE)Ask the the user to type in the file of their choice -> "tinypix.ppm"
	print out Enter the source file and the persons input 
			if the user inputs a file that is not in the directory 
			print out a message saying file not included please try again.
			else 
			print out file was found


	(DONE)Ask the user where they would like to put the input into a file -> "output.ppm" 
			if the user inputs a file that is not in the directory 
			print out a message saying file not included please try again.
			else 
			print out file was found 

	I want to sort through the file's content 
		

	

	*/

