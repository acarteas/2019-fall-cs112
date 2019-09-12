#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;






int main(void)
{
	ifstream myfile;
	string line1; 
	string line2;
	string line3;
	string line4;
	string line5;
	string line6;
	string line7;


	myfile.open("tinypix.ppm");
	
	while (getline(myfile, line1))
	{
		cout << line1 << endl;
	}

	myfile.close();
	



	return 0;

}