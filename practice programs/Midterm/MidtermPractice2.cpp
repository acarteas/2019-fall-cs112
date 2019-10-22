#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <exception>
using namespace std;

// Problem 1:

void fizzBuzz()
{
    for (int i = 0; i <= 50; i++)
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
    ifstream stream{ file_name };
    while (stream.good() == true)
    {
        string line;
        getline(stream, line);
        cout << line << endl;
    }
    stream.close();
}

// Problem 3:

void computeAverage(string input_file, string output_file)
{
    double sum_ints = 0;
    double average = 0;
    double num_ints = 0;
    ifstream stream{ input_file };
    while (stream.good() == true)
    {
        string line;
        getline(stream, line);
        sum_ints += stod(line);
        num_ints++;
    }
    stream.close();
    average = sum_ints / num_ints;
    ofstream output{ output_file };
    output << average;
    output.close();
}

// Problem 4:

void displayNumbers(vector<double>& data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << fixed << setprecision(2) << setw(9) << data[i] << " " << endl;
        (if (i + 1) % 3 == 0)
        {
            cout << endl;
        }
    }
}

// Problem 7:

int numberOfSentences(string text)
{
    istringstream stream{ text };
    vector<string> sentences{};
    while (stream.good() == true)
    {
        string line;
        getline(stream, line, '.');
        sentences.push_back(line);
    }
    stream.close();
    return (sentences.size() - 1);
}

// Problem 8:

int longestSentence(string text)
{
    vector<string> temp{};
    vector<string> words{};
    vector<vector<string>> sentences{};
    istringstream stream{ text };
    while (stream.good() == true)
    {
        string line;
        getline(stream, line, '.');
        temp.push_back(line);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        istringstream temp2{ temp[i] };
        while (temp2.good() == true)
        {
            string word;
            getline(temp2, word, ' ');
            if (word == " " || word == '')
            {
                word = word;
            }
            else
            {
                words.push_back(word);
            }
            
        }
        sentences.push_back(words);
        words.clear();
    }
    int largest = 0;
    for (int i = 0; i < sentences.size(); i++)
    {
        if (sentences[i].size() > largest)
        {
            largest = sentences[i].size();
        }
    }

    return largest;
}

int main()
{

}