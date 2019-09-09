#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void image_file(string file_name)
{
    string line_to_read
    
    ifstream file_to_read;
    
	file_to_read.open(file_name);

	while (!file_to_read.eof())
	{
		getline(file_to_read, line_to_read)

		cout <<  << endl;
	}
	file_to_read.close();
}

int main()
