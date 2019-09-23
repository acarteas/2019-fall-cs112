#include "dataProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string file_to_read, file_to_write;
	cout << "Enter a File Name to Read From: ";
	cin >> file_to_read;
	cout << endl;
	cout << "Enter a File Name to Write To: ";
	cin >> file_to_write;
	cout << endl;
	dataProcessor(file_to_read, file_to_write);
	cout << endl;
	cout << "Program Complete" << endl;
}