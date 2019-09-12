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


	myfile.open("tinypix.ppm");
	
	while (getline(myfile, line1))
	{
		cout << line1 << endl;
	}

	myfile.close();
	



	return 0;

}