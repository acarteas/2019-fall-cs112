//Your program should prompt the user for an input and output file 
//as well as the operation that the user would like to perform. 
//Here's an example:

//Enter source file: tinypix.ppm
//Enter destination file: output.ppm

//*** Image Effects ***
//1. Remove Red
//2. Remove Blue
//3. Remove Green
//4. Negate Red
//5. Negate Blue
//6. Negate Green
//7. Grayscale

//Selection: 5

// Applying Negate Blue effect...
// Done.  Program complete.


#include "Helper.h"




int main(void)
{

	ifstream  myFile;



	string s;
	cout << "Enter source File:" << endl;
	cin >> s;
	cout << "Your selected source File:  " << s << endl;
		

	myFile.open(s);

	if (!myFile)
	{
		cout << "Not open" << endl;
		return 0;
	}
	


	

	vector<int> data;
	vector<vector<int>> data1{};
	int num_rows;

	data1.resize(num_rows);
	//intailizing number of rows

	int num_col;
	//resize each row
	for (int i = 0; i < num_rows; i++)
	{
		data1[i].resize(num_col);
	}
	int row_counter = 0;
	int col_counter = 0;
	while (myFile.good() == true)
	{
		//intailizing number of rows
		
		int line;
		myFile >> line;
		data1[1][0] = line;
		//data1.push_back(line);
		for (int i; i < data[1]; i++) 
		{
			col_counter++;
				
		}
		
		//cout << line << endl;
		
		for (int j; j < data[0]; j++)
		{
			row_counter++;

		}
		//ppm should tell
		int num_rows = data[1];
		int num_col = data[2];
	}




	int x;
	cout << "Choose what you would like to do with your image:" << endl;
		cout << "1 = remove red" << endl;
		cout << "2 = Negate red" << endl;
		cout << "3 = remove blue" << endl;
		cout << "4 = Negate blue" << endl;
		cout << "5 = remove green" << endl;
		cout << "6 = Negate green" << endl;
		cout << "7 = Grayscale" << endl;
		cin >> x;

	if(x == 1)
	{
		RemoveRed(data);
	}
	else if (x == 2)
	{
		NegateRed(data);
	}
	else if (x == 3)
	{
		RemoveGreen(data);
	}
	else if (x == 4)
	{
		NegateGreen(data);
	}
	else if (x == 5)
	{
		RemoveBlue(data);
	}
	else if (x == 6)
	{
		NegateBlue(data);
	}
	else if (x == 7)
	{
		Grayscale(data);
	}



	//vector<vector<int>> data1{};
	
	////ppm should tell
	//int num_rows = 300;
	//int num_col = 188;

	////intailizing number of rows
	//data1.resize(num_rows);

	////resize each row
	//for (int i = 0; i < num_rows; i++)
	//{
	//	data1[i].resize(num_col);
	//}

	//setting one pixel 
	//using INTs to store RGB values, you need to multiply rows and cols by 3
	//data1[0][1] = 255;

	//ifstream input_ppm{};
	//int row_counter = 0;
	//int col_counter = 0;
	//while (input_ppm.good() == true)
	//{
	//	int next_num = 0;
	//	input_ppm >> next_num;
	//	data1[row_counter][col_counter] = next_num;
	//	challenge incrementing the row counter and column counter
	//	

		
	
	ofstream outputFile;
	for (int i = 0; i <data.size(); i++)
	{
		outputFile <<data.at(i);
	}
	
	
		
		
		
		//for (int i = 3; i < data.size()-1; i++)
		//{
		//	//change the string into a int
		//	istringstream line{data[i]};
		//	int counter = 1;

		//	while (line.good() == true)
		//	{
		//		int number = 0;
		//		line >> number;
		//		//cout << number << endl;
		//		if (counter % 5 == 0)
		//		{
		//			output_data.push_back(0);
		//			
		//		}
		//		else
		//		{
		//			output_data.push_back(number);
		//		}
		//		counter++;
		//	}
		//	

		//	
			
			
	myFile.close();
}

