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


using namespace std;

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
	int num_rows = 0;
	int num_col=0;

	int row_counter = 3;
	int col_counter = 0;

	string title = "P3";
	string current_num;
	myFile >> current_num;

	title = current_num;
	myFile >> current_num;
	num_rows = stoi(current_num); //debugging: current_num is 0, why?

	data1.resize(num_rows); 
	myFile >> current_num; 
	num_col = stoi(current_num);

	string max_val = "255";
	string current_num;
	myFile >> current_num;

	max_val = current_num;
	//resize each row
	for (int i = 0; i < num_rows; i++)
	{
		data1[i].resize(num_col);
	}

	data1[1][0] = num_rows;
	data1[1][1] = num_col;
	
	int data_counter = 0; //for 1d vector

	while (myFile.good() == true)
	{
		myFile >> current_num;
		data1[row_counter][col_counter] = stoi(current_num);

		data[data_counter] = stoi(current_num); // add to 1d vector
		if (col_counter == num_col -1)
		{
			col_counter = 0;
			row_counter++;
		}
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
		cout << "Removing Red..." << endl;
		RemoveRed(data);
		cout << "Complete" << endl;
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
	// TODO: add string title as first line 
	// add row and col num as second line with space between
	// add maxval as third line
	// TODO: look at row and col numbers to see where to put endl;
	//when grabbing the title you have put it in the 1d vector 
	
	for (int i = 4; i <data.size(); i++)//rest loop
	{
		outputFile <<data.at(i) <<" ";
		// when (i - 4 )% col_num = 0, add endl; 
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

