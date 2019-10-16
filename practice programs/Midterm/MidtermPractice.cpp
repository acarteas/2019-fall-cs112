#include <iostream>
#include <fstream>
#include <sstream>
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

int main()
{
    fizzBuzz();
    cout << endl << endl;

}