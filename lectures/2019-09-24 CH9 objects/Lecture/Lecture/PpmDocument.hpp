#pragma once
#ifndef PPM_DOCUMENT_HPP
#define PPM_DOCUMENT_HPP
#include <string>
#include <vector>
#include <sstream>
#include "FileHelpers.h"
using namespace std;
/*
Properties of PPM Document:
	1. Image format (e.g. P3)
	2. Width
	3. Height
	4. Image data (collection of Pixels)
	5. File name

Operations that we perform on PPM documents
	1. Open file
	2. Write file
	3. Manipulate pixels
	4. Draw (kind of hard)
	5. Resize image
	6. Crop
*/
class PpmDocument
{
private:
	//underscore means that the variable belongs
	//to the object
	string _format;
	int _width = 0;
	int _height = 0;
	int _color_depth = 0;
	string _file_name;
	vector<int> _rgb_data;

public:

	//constructor method gets called automatically
	//whenever we create a new PpmDocument
	PpmDocument(string file_name)
	{
		_file_name = file_name;
		vector<string> raw_data = readFile(_file_name);
		
		//make sure file was read successfully
		if (raw_data.size() == 0)
		{
			//TODO: throw error
		}
		else
		{
			//set object properties
			_format = raw_data[0];

			//grab width and height using istringstream
			istringstream line{ raw_data[1] };
			line >> _width;
			line >> _height;

			//color depth
			_color_depth = stoi(raw_data[2]);

			//process data
			for (int i = 3; i < raw_data.size(); i++)
			{
				istringstream numbers_str{ raw_data[i] };

				//grab all numbers per line
				while (numbers_str.good() == true)
				{
					string temp;
					getline(numbers_str, temp, ' ');
					if (temp.length() > 0 && temp != " ")
					{
						_rgb_data.push_back(stoi(temp));
					}
				}
			}
		}
	}

	//do nothing constructor for when we don't
	//have a file name
	PpmDocument()
	{

	}

	int getColorDepth() const
	{
		return _color_depth;
	}

	string getFileName() const
	{
		return _file_name;
	}

	void setFileName(const string& file_name)
	{
		_file_name = file_name;
	}

	int getHeight() const
	{
		return _height;
	}

	int getWidth() const
	{
		return _width;
	}

	string getImageFormat() const
	{
		return _format;
	}

	void setImageFormat(string format)
	{
		//error checking
		if (format == "P3" || format == "P6")
		{
			_format = format;
		}
		else
		{
			//TODO: throw error 
		}
	}


};

#endif // !PPM_DOCUMENT_HPP
