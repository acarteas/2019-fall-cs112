#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <exception>

using namespace std;

// Problem 1:

void fizzBuzz()
{
	for (int i = 1; i <= 50; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			cout << "FizzBuzz" << endl;
		}
		else if (i % 3 == 0)
		{
			cout << "Fizz" << endl;
		}
		else if (i % 5 == 0)
		{
			cout << "Buzz" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
}

// Problem 2:

void readFile(string file_name)
{
	ifstream file{ file_name };
	while (file.good() == true)
	{
		string line;
		getline(file, line);
		cout << line << endl;
	}
	file.close();
}

// Problem 3:

void computeAverage(string input_file, string output_file)
{
	ifstream input{ input_file };
	double average = 0;
	double sum_ints = 0;
	double num_ints = 0;
	while (input.good() == true)
	{
		string line;
		getline(input, line);
		sum_ints += stod(line);
		num_ints++;
	}
	input.close();
	ofstream output{ output_file };
	average = sum_ints / num_ints;
	output << average;
	output.close();
}

// Problem 4:
void displayNumbers(vector<double>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << fixed << setprecision(2) << data[i] << " ";
		if ((i + 1) % 3 == 0)
		{
			cout << endl;
		}
	}
}

int main()
{
	fizzBuzz();
	cout << endl << endl;
	// readFile("Test.txt");
	// computeAverage("Test2.txt", "average.txt");
	// cout << endl << endl;
	vector<double> data_values{ 123.4, 30.24, 9.1, 13.8, 18.96, 2000.2345, 80.6666 };
	displayNumbers(data_values);
}