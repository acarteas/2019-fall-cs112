#include "dataProcessor.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

void dataProcessor(string input_file, string output_file)
{
	string line_to_read;

	ifstream datainput;
	ofstream dataoutput;
	datainput.open(input_file.c_str());
	dataoutput.open(output_file);

	getline(datainput, line_to_read);
	dataoutput << line_to_read << endl;

	getline(datainput, line_to_read);
	dataoutput << line_to_read << endl;

	getline(datainput, line_to_read);
	dataoutput << line_to_read << endl;

	int count = 0;
	int linebreaker = 12;
	while (datainput.good() == true)
	{
		getline(datainput, line_to_read, ' ');
		
		if (line_to_read == " ")
		{
			dataoutput << "";
		}
		else if (count == 0 || count % 3 == 0)
		{
			dataoutput << 0 << " ";
			count++;
		}
		else
		{
			dataoutput << line_to_read << " ";
			count++;
		}

	}

	datainput.close();
	dataoutput.close();
}