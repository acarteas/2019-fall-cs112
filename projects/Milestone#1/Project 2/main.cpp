#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>

  
using namespace std;
//void removeRed(vector<int>& data);

int main(void)
{

	ifstream  myFile;



	string s;
	cout << "Enter source File:" << endl;
	cin >> s;
	cout << "Your selected source File:  " << s << endl;

	myFile.open(s);

	if (!myFile)
	{
		cout << "Not open" << endl;
		return 0;
	}
	

	//after reading the file and storing it in a string s for example, here how we can
//extract the data from it in each array
	
	int len = s.length();
	string r1, r2, g1, g2, b1, b2, g;
	//taking a copy of the original picture
	r1 = s;
	r2 = s;
	g1 = s;
	g2 = s;
	b1 = s;
	b2 = s;
	;
	for (int i = 0; i < len; i++)
	{
		if (i % 3 == 0)
		{
			//for no red and negative red
			r1[i] = 0;
			r2[i] = 255 - r2[i];
		}
		if (i % 3 == 1)
		{
			//for no red and negative green
			g1[i] = 0;
			g2[i] = 255 - g2[i];
		}
		if (i % 3 == 2)
		{
			//for no red and negative blue
			b1[i] = 0;
			b2[i] = 255 - b2[i];
			//for the grey scale averaging
			g += (s[i] + s[i - 1] + s[i - 2]) / 3.0;
		}
	}
	

		vector<string> data;
		while (myFile.good() == true)
		{
			string line;
			getline(myFile, line);
			//cout << line << endl;
			data.push_back(line);

		}
		vector<int> output_data;
		
		
		
		
		for (int i = 3; i < data.size()-1; i++)
		{
			//change the string into a int
			istringstream line{data[i]};
			int counter = 1;

			while (line.good() == true)
			{
				int number = 0;
				line >> number;
				//cout << number << endl;
				if (counter % 5 == 0)
				{
					output_data.push_back(0);
					
				}
				else
				{
					output_data.push_back(number);
				}
				counter++;
			}
			

			
			
			
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


