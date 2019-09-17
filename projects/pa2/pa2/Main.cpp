#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{

	ifstream myOutStream; 
	myOutStream.open("tinypix.ppm");

	string line1;
	string line2;
	string line3;
	string line4;
	string line5;
	string line6;
	string line7; 
	string line8;
	

	getline(myOutStream, line1); 
	cout << "Image Format: " << line1 << endl; 

	getline(myOutStream, line2);
	cout << "Width: " << line2.at(0) << endl;
	cout << "Height: " << line2.at(0) << endl;

	getline(myOutStream, line3);
	cout << "Max Pixel Value: " << line3 << endl; 

	cout << "Data:" << endl;
	getline(myOutStream, line4);
	cout << line4 << endl;
	getline(myOutStream, line5);
	cout << line5 << endl;
	getline(myOutStream, line6);
	cout << line6 << endl;
	getline(myOutStream, line7);
	cout << line7 << endl;
	


}