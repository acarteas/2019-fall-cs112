#include "midterm.hpp"
using namespace std;


/**
CS 112 Midterm.  Make all edits inside midterm.hpp.
*/

int main(void)
{
	cout << boolalpha;

	cout << "Question #1: Fizzbuzz: " << endl;
	fizzbuzz();
	cout << endl << endl;

	cout << "Question #2: Compute averages: " << endl;
	computeAverage("numbers.txt", "output.txt");
	cout << endl << endl;


	cout << "Question #3: pretty formatting: " << endl;
	vector<double> data{1.242342312, 0, 123.456, 78.911, 2.34, 5678.91011, 10, 98.7, 6.54321};
	displayNumbers(data);
	cout << endl << endl;


	cout << "Question #4: Sentence counter " << endl;
	string sentence = "Write a function that counts the number of sentences in a word. For this function, a sentence is always terminated by a period.";
	cout << numberOfSentences(sentence) << " (expected: 2)" << endl;
	sentence = "a. b. c. d. e. f. g";
	cout << numberOfSentences(sentence) << " (expected: 6)" << endl;

	cout << "Question #5: Longest sentence " << endl;
	sentence = "Write a function that counts the longest sentences in a string. For this function, a sentence is always terminated by a period.";
	cout << numberOfSentences(sentence) << " (expected: 11)" << endl;
	sentence = "a. b. c. d. e. f g";
	cout << longestSentence(sentence) << " (expected: 2)" << endl;

}