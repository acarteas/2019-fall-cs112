#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <fstream>
#include <istream>

using namespace std;
/*
string my_Test(string sentence)
{
	istringstream input{ sentence };
	ostringstream more{};
	while (input.good() == true)
	{
		string word;
		getline(input, word, ' ');
		//more << word + "g" << " ";
		//string output = more.str();
		//cout << output << endl;
		cout << word << endl;
	}
	return "done";
}
*/
/*string my_Test2(string original)
{
	int index = 0;
	string final;
	while (index < original.length()) 
	{
		int space_index = original.find(' ', index); // find the first space index number
		string word;
		word = original.substr(index, space_index - index); // take a substr of original from 0 or the next space and assignit to word
		cout << word << endl; //print that word
		
		

		
		final = word;
	}
	return final;
}
*/


int main()
{
	string line;
	string line1;
	string line2;
	string part1;
	string part2;
	string line3;
	ifstream ppm1("tinypix.ppm");
	
	getline(ppm1, line1);
	getline(ppm1, line2);
	part1 = line2.substr(0, 1);
	part2 = line2.substr(1, 2);
	getline(ppm1, line3);
	cout << "Image Format: " << line1 << endl;
	cout << "Width: "<< part1 << endl;
	cout << "Height: " << part2 << endl;
	cout << "Max Pixel Value: " << line3 << endl;

	while (getline(ppm1, line)) {
		cout << line << endl;
	}
	ppm1.close();
	return 0;
}