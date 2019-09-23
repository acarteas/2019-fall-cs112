#include <iostream>
#include <fstream>
#include <string>
  
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
	 
	while (myFile.good() == true)
	{
		string line;
		getline(myFile, line);
		cout << line << endl;
	}
	
	myFile.close();
}