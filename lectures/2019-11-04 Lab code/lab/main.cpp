#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	vector<vector<int>> data{};

	//should come from PPM file
	//if you're using INTs to store RGB values, you
	//would need to multiply #rows #cols by 3 because
	//each pixel has a red, green, and blue component
	int num_rows = 10;
	int num_cols = 7;

	//initialize 2D vector based on parameters
	//begin by setting number of rows
	data.resize(num_rows);

	//resize each row to be of correct width
	for (int i = 0; i < num_rows; i++)
	{
		data[i].resize(num_cols);
	}

	//set an individual pixel
	data[0][1] = 255;

	ifstream input_ppm{};
	int row_counter = 0;
	int col_counter = 0;
	while (input_ppm.good() == true)
	{
		int next_num = 0;
		input_ppm >> next_num;
		//ppm.push_back()
		data[row_counter][col_counter] = next_num;

		//Challenge: how to properly increment our
		//row and column counters
	}
	


	return 0;
}