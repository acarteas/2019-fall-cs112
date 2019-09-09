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
	string line; 

	myfile.open("tinypix.ppm");
	
	while ( getline(myfile, line));
	{
		cout << line << "\n";
	}

	myfile.close();
	



	return 0;

}