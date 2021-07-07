#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

/* Question #1:

Complete a function called fizzbuzz that does the following:

Output 50 lines to the screen using cout
If the line number is a multiple of 3, print "Fizz"
If the line number is a multiple of 5, print "Buzz"
If the line number is a mulitple of both 3 and 5, print "FizzBuzz"
If none of the above is true, print the line number (starting at 1).

Example output for values 1-15:

1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
*/
void fizzbuzz()
{
	for (int i = 0; i < 50; i++)
	{
		if (i % 3 == 0 && i % 5)
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

/*
Question 2: File I/O
Complete a function that reads all numbers in a file and writes the average of these numbers to an output file. Example function prototype:
*/
void computeAverage(string input_file, string output_file) 
{
	ifstream myFile;

	cout << "Enter an input file: " << endl;
	cin >> input_file;

	myFile.open(input_file);
	if (!myFile)
	{
		cout << "not a file" << endl;
	}
	else
	{
		cout << input_file << endl;
	}





}

/*
Question 3: Pretty formatting
Complete a function that accepts a vector of floating point numbers(i.e.doubles) and outputs them with a precision of two decimal places in nice columns
having 3 numbers per row.
Example function prototype :
Example output :

123.45   4.56   78.90
 98.76  54.32    1.01
*/
void displayNumbers(vector<double>& data) 
{

	ifstream NumberFile;

	double number;
//	getline(NumberFile, number);
	data.push_back(number);

}

/*
Question 4: Sentence counter
Write a function that counts the number of sentences in a word. For this function, a sentence is always terminated by a period.
Examples:

(one sentence) "This string has one sentence."

(four sentences) "This. Second. Example. Has four sentences."
*/
int numberOfSentences(string text) 
{
	
		
	for (int i = 0; i < text.size() - 126; i++)
	{
		if (text.find("."))
		{
			for (int j = 0; j < text.length() - 126; j++)
			{
				cout << text << endl;
			}
		}

	}
	
	
	
	return -1;
}


/*
Question 5: Longest sentence
Write a function that calculates the length of the longest sentence in a string.

Examples:

(5) "This string has one sentence."

(3) "This. Second Example has. three sentences."

Function prototype:
*/
int longestSentence(string text)
{

	for (int i = 0; i < text.size() - 1; i++)
	{
		if (text.find("."))
		{
			for (int j = 0; j < text.length(); j++)
			{
				cout << text << endl;
			}
		}

	}

	return -1;
}
