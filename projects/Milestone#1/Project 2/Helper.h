#pragma once
#ifndef Helper_h
#define Helper_h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>



using namespace std;
void RemoveRed(vector<int>& data) 
{
	for(int i = 4; i <data.size(); i++)
	{
		if (i % 3 == 1)
		{
			//for no red and negative red
			data[i] = 0;
		}
	}
}
void NegateRed(vector<int>& data)
{
	for (int i = 4; i < data.size(); i++)
	{
		if (i % 3 == 1)
		{
			//for no red and negative red
			data[i] = 255 - data[i];
		}
	}
}
void RemoveBlue(vector<int>& data)
{
	for (int i = 4; i < data.size(); i++)
	{
		if (i % 3 == 2)
		{
			//for no red and negative blue
			data[i] = 0;
		}
	}
}
void NegateBlue(vector<int>& data)
{
	for (int i = 4; i < data.size(); i++)
	{
		if (i % 3 == 2)
		{
			//for no red and negative blue
			data[i] = 255 - data[i];
		}
	}
}
void RemoveGreen(vector<int>& data)
{
	for (int i = 4; i < data.size(); i++)
	{
		if (i % 3 == 1)
		{
			//for no red and negative green
			data[i] = 0;
		}
	}
}
void NegateGreen(vector<int>& data)
{
	for (int i = 4; i < data.size(); i++)
	{
		if (i % 3 == 1)
		{
			//for no red and negative green
			data[i] = 255 - data[i];
		}
	}
}
void Grayscale(vector<int>& data)
{
	for (int i = 4; i < data.size(); i++)
	{
		
			//for greyscale
			data[i] = data[i] + data[i-1]+ data[i-2]/3.0;
			
	}
}

//data[y][x]
#endif Helper_h