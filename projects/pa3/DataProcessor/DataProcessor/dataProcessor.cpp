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
	ofstream dataoutput{output_file};

	vector<string> data = readFile(input_file);
	string data_to_read;

	dataoutput << data[0] << endl;
	dataoutput << data[1] << endl;
	dataoutput << data[2] << endl;

	//data rows
	int place_count = 0;
	for (int row_count = 3; row_count < data.size(); row_count++)
	{
		istringstream next_row{ data[row_count] };
		
		getline(next_row, data_to_read);

		istringstream row{ data_to_read };

		while (row.good() == true)
		{
			getline(row, data_to_read, ' ');
			
			if (data_to_read == "" || data_to_read == " ")
			{
				place_count = place_count;
			}
			else
			{
				if (place_count == 0 || place_count % 3 == 0)
				{
					dataoutput << 0 << " ";
					place_count++;
				}
				else
				{
					dataoutput << stoi(data_to_read) << " ";
					place_count++;
				}
			}
		}
		dataoutput << endl;
	}

	dataoutput.close();	
}


