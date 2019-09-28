
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

/*
signature: what_file: ifstream ofstream -> void
purpose: Expects an ifstream and an ofstream with a side effect 
of prompting the user for the file names.
*/
void what_file(ifstream& input_stream, ofstream& output_stream); //declaring function

const int NUM_HEADER_LINES = 3;
		
int main(void)
{
	ifstream input_stream;

	ofstream output_stream;
	string	 line_to_read;
	vector<string> header_info;
	vector<int> pixel_data;
	vector<int> converted_data;

	what_file(input_stream, output_stream);

	//Reading the first 3 lines of the File
	if (input_stream.good() == true)
	{
		for (int i = 0; i < NUM_HEADER_LINES; i++)
		{
			getline(input_stream, line_to_read);
			header_info.push_back(line_to_read);
		}
	}



	//Reading the body of the file
	while (input_stream.good() == true)
	{
		getline(input_stream, line_to_read, ' ');
		if (line_to_read != "")
		{
			pixel_data.push_back(stoi(line_to_read));
		}
	}

	//Converting String to Integers for Reading
	/*for (int i = 0; i < pixel_data.size(); i++)
	{
		istringstream data_row{
			string temp_line;

		}
	}
	*/
		

	//Remove Red - turn every 3rd number
	//(starting with element 0) in the data component 
	//to a zero. (Data Changed)
	for (int i = 3; i < pixel_data.size(); i +=3)
	{
		pixel_data[i] = 0;
	}
	
	//Write out to file (header).
	for (int i = 0; i < header_info.size(); i++)
	{
		output_stream << header_info[i] << endl;
	}

	//Write out to file (body).
	for (int i = 0; i < pixel_data.size(); i++)
	{
		//if (i % 3 == 2) 
		{
			output_stream << pixel_data[i]<< ' ';
		}

	}

	while (input_stream.good())
	{
		getline(input_stream, line_to_read);
	}
	//cleaning up:
	input_stream.close();
	output_stream.close();
	return 0;
}

void what_file(ifstream& input_stream, ofstream& output_stream)
{
	string file_name;

	// Error Checking to see if file is open
	if ((input_stream.is_open() == true) || (output_stream.is_open() == true))
	{
		cout << "Error: File Already Opened. Closing file to proceed. " << endl;
		input_stream.close();
		output_stream.close();
	}

	// Prompt user for file name they want to open.
	cout << "Enter the name of the file you wish to open: " << endl;
	getline(cin, file_name);
	input_stream.open(file_name);
	while (input_stream.good() == false)
	{
		cout << "This file does not exist! Please re-enter file name: " << endl;
		getline(cin, file_name);
		input_stream.open(file_name);
	}

	// Prompt user for the file name they want to write to.
	cout << "Enter the name of the file you wish to write to: " << endl;
	getline(cin, file_name);
	output_stream.open(file_name);
	// Error checking to make sure file ext can open.
	while (output_stream.good() == false)
	{
		cout << "This file name is not compatible! Please re-enter file name: " << endl;
		getline(cin, file_name);
		output_stream.open(file_name);
	}
}

