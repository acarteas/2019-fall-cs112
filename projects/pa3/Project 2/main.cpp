#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>

  
using namespace std;


int main(void)
{

	ifstream  myFile;


	string x;
	cout << "Enter source File:" << endl;
	cin >> x;
	cout << "Your selected source File:  " << x << endl;

	myFile.open(x);

	if (!myFile)
	{
		cout << "Not open" << endl;
		return 0;
	}
	
		vector<string> data;
		while (myFile.good() == true)
		{
			string line;
			getline(myFile, line);
			//cout << line << endl;
			data.push_back(line);

		}
		//change the string into a int
		cout << "The orginial Line: " << << endl;
		int i;
		int New_data;

		
		for (int i = 3; i < data.size()-1; i++)
		{
			
			for (int j = 0; j < 2; j++)
			{
				 New_data = stoi(data[3]);
				
				int old_value = New_data;
				int New_value = old_value - old_value;
				old_value = New_value;

				
				//cout << New_value;
				//cout<< New_data << endl;
			
		
			}
			
			
		}
		cout << "The orginial Line: " << data[3] << endl;
		cout << New_data << endl;
		

		


	myFile.close();
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

