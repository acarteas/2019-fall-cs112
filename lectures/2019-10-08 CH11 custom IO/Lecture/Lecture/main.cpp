#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include <iomanip> //for making fancy couts and output to file
#include "HelperFunctions.h"
#include "FileHelpers.h"

vector<string> splitCsv(string text)
{
	//string-based stream - after setup works just like a file
	//or CIN
	istringstream buffer{ text };
	vector<string> result{};

	//grab text from buffer
	//Stroustrup does does
	//   initialize string; read next cell;      reset temp (not needed)
	//for (string temp; getline(buffer, temp, ','); temp = "")
	while (buffer.good() == true)
	{
		string temp;
		getline(buffer, temp, ',');
		result.push_back(temp);
	}
	return result;
}

string centerText(int fixed_width, string& word_to_center)
{
	ostringstream formatter{};
	int padding = (fixed_width - word_to_center.length()) / 2;
	formatter << setw(padding) << " "
		<< word_to_center
		<< setw(padding) << " ";

	//if odd string length, add extra space padding
	if (word_to_center.length() % 2 == 1)
	{
		formatter << " ";
	}
	return formatter.str();
}

//P. 388 Try this: Format data (Adam's spin: format CSV data!)
void formatData()
{
	vector<string> raw_data = readFile("death_rates.csv");
	vector<vector<string>> table{};

	//grab header data
	vector<string> header = splitCsv(raw_data[0]);

	//build table with correct number of rows
	table.resize(raw_data.size());

	//go through each row to build out the width of the table
	for (int i = 0; i < table.size(); i++)
	{
		vector<string> cells = splitCsv(raw_data[i]);
		for (int j = 0; j < cells.size(); j++)
		{
			table[i].push_back(cells[j]);
		}
	}

	//figure out max width of each column
	vector<int> column_widths{};

	//assume each column is really big
	column_widths.resize(table[0].size());
	for (int i = 0; i < column_widths.size(); i++)
	{
		column_widths[i] = 0;
	}

	//search for actual max width
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			//if current cell is bigger than what we believe to
			//be largest width for cell, enlarge
			if (table[i][j].length() + 2 > column_widths[j])
			{
				column_widths[j] = table[i][j].length() + 2;
			}
		}
	}

	//with our data parsed and our column widths known, finally
	//output to the screen
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			cout << centerText(column_widths[j], table[i][j])
				<< (char)186;
		}
		cout << endl;
	}

}

//P. 398 Removing punctuation from words
vector<string> removePunctuation(string& raw_text)
{
	istringstream buffer{ raw_text };
	vector<string> result{};
	string current;
	while (buffer.good() == true)
	{
		//at this point, current may contain punctuation
		buffer >> current;

		//questions: are we going to handle punctuation at
		//beginning, in between, and end of word?
		//(class consensus: YES)
		ostringstream sanitized{};
		for (int i = 0; i < current.length(); i++)
		{
			if (current[i] >= 'A' && current[i] <= 'Z'
				|| current[i] >= 'a' && current[i] <= 'z')
			{
				sanitized << current[i];
			}
		}
		result.push_back(sanitized.str());
	}

	return result;
}

int main(int argc, char* argv[])
{
	//formatData();
	string sentence = "Hello, world!  This is a test.  It doesn't work perfectly, but not bad for 10 minutes of thought :)";
	vector<string> words = removePunctuation(sentence);
	return 0;
}