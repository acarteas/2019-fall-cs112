#include <iostream>
#include <fstream>
  
using namespace std;


int main(void)
{
	int sum = 0;
	int x;
	ifstream  myFile;

	myFile.open("tinypix.ppm");

	if (!myFile)
	{
		cout << "Not open" << endl;
		return 0;
	}
	 
	while (myFile >> x)
	{
		sum = sum + x;

	}
	cout << "The file was open";
	myFile.close();
}