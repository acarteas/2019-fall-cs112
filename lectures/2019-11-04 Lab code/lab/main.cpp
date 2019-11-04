#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	vector<vector<int>> data{};

	//should come from PPM file
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



	return 0;
}