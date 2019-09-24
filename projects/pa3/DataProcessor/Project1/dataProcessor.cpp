#include "dataProcessor.h"
#include "fileHelpers.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

void dataProcessor(string input_file, string output_file)
{
	ofstream dataoutput;
	dataoutput.open(output_file);

	vector<string> data = readFile(input_file);
	string line_to_read;

	dataoutput << data[0] << endl;
	dataoutput << data[1] << endl;

	//image format
	dataoutput << data[2] << endl;

	//data rows
	int place_count = 0;
	for (int row_count = 3; row_count < data.size(); row_count++)
	{
		istringstream next_row{ data[row_count] };
		while (next_row.good() == true)
		{
			if (place_count == 0 || place_count % 3 == 0)
			{
				if ((place_count + 1) % 12 == 0)
				{
					dataoutput << endl;
				}
				getline(next_row, line_to_read, ' ');
				dataoutput << 0 << " ";
				place_count++;
			}
			else
			{
				if (place_count % 12 == 0)
				{
					dataoutput << endl;
				}
				getline(next_row, line_to_read, ' ');
				dataoutput << line_to_read << " ";
				place_count++;
			}
		}
		
	}
}

