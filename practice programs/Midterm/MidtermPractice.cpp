#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>
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
    ifstream input;
    input.open(file_name);
    while (input.good() == true)
    {
        string line;
        getline(input, line);
        cout << line << endl;
    }
    input.close();
}

// Problem 3:
void computeAverage(string input_file, string output_file)
{
    ifstream stream;
    vector<double> numbers{};
    double sum_ints = 0;
    double average = 0;
    stream.open(input_file);
    while (stream.good() == true)
    {
        string digits;
        getline(stream, digits, ' ');
        numbers.push_back(stoi(digits));
    }
    stream.close();

    ofstream output;
    output.open(output_file);

    for (int i = 0; i < numbers.size(); i++)
    {
        sum_ints += numbers[i];
    }
    average = sum_ints / numbers.size();
    output << average;
    output.close();
}

// Problem 4:

void displayNumbers(vector<double>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << fixed << setprecision(2) << setw(8) << data[i] << " ";
		if ((i + 1) % 3 == 0)
		{
			cout << endl;
		}
	}
}

// Problem 5:

void dangerousCode()
{
    throw invalid_argument{ "invalid argument"};
}

// Problem 6:

// Problem 7:

int numberOfSentences(string text)
{
    istringstream stream{ text };
    vector<string> sentence{};
    while (stream.good() == true)
    {
        string line;
        getline(stream, line, '.');
        sentence.push_back(line);
    }
    return (sentence.size() - 1);
}

// Problem 8:

int longestSentence(string text) 
{
    vector<string> temp{};
    istringstream stream{ text };
    while (stream.good() == true)
    {
        string word;
        getline(stream, word, '.');
        temp.push_back(word);
    }
    vector<string> sentence{};
    vector<vector<string>> lines{};
    for (int i = 0; i < temp.size(); i++)
    {
        istringstream sent_stream{ temp[i] };
        while (sent_stream.good() == true)
        {
            string word;
            getline(sent_stream, word, ' ');
            if (word == "" || word == " ")
            {
                word = word;
            }
            else
            {
                sentence.push_back(word);
            }
        }
        lines.push_back(sentence);
        sentence.clear();
    }
    int largest = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].size() > largest)
        {
            largest = lines[i].size();
        }
    }
    return largest;
}

int main()
{
    cout << longestSentence("This is a string. Where. The longest sentence. is four.") << endl;
    cout << endl << endl;
    cout << numberOfSentences("This is a string. Where. The longest sentence. is four.") << endl;
    cout << endl << endl;
    vector<double> data_values{ 123.4, 30.24, 9.1, 13.8, 18.96, 2000.2345, 80.6666 };
    displayNumbers(data_values);
    cout << endl << endl;
    try
    {
        dangerousCode();
    }
    catch (...)
    {
        cout << "Invalid Argument" << endl;
    }
}