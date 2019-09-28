#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main()
{
	string fileName;
	cout << "Enter the name of your .ppm file:" << endl;
	cin >> fileName;

	ofstream fout;
	fout.open(fileName);

	string line1;
	getline(cin, line1);

	cout << line1;





}