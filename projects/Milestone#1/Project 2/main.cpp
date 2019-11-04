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
	

	//after reading the file and storing it in a string s for example, here how we can
//extract the data from it in each array
	
	int len = s.length();
	string r1, r2, g1, g2, b1, b2, g;
	

	vector<int> data;
	vector<vector<int>> data1{};
	//ppm should tell
	int num_rows = 300;
	int num_col = 188;

	//intailizing number of rows
	data1.resize(num_rows);

	//resize each row
	for (int i = 0; i < num_rows; i++)
	{
		data1[i].resize(num_col);
	}
	int row_counter = 0;
	int col_counter = 0;
	while (myFile.good() == true)
	{
		int line;
		myFile >> line;
		data1[row_counter][col_counter] = line;
		//data1.push_back(line);
		col_counter++;
		//cout << line << endl;
		
		

	

	}

	vector<int> output_data = data;


	int x;
	cout << "Enter source File:" << endl;
	cin >> x;
	cout << "Choose what you would like to do with your image:" << endl;
		cout << "1 = remove red" << endl;
		cout << "2 = Negate red" << endl;
		cout << "3 = remove blue" << endl;
		cout << "4 = Negate blue" << endl;
		cout << "5 = remove green" << endl;
		cout << "6 = Negate green" << endl;
		cout << "7 = Grayscale" << endl;
	if(x == 1)
	{
		RemoveRed(output_data);
	}
	else if (x == 2)
	{
		NegateRed(output_data);
	}
	else if (x == 3)
	{
		RemoveGreen(output_data);
	}
	else if (x == 4)
	{
		NegateGreen(output_data);
	}
	else if (x == 5)
	{
		RemoveBlue(output_data);
	}
	else if (x == 6)
	{
		NegateBlue(output_data);
	}
	else if (x == 7)
	{
		Grayscale(output_data);
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
	for (int i = 0; i < output_data.size(); i++)
	{
		outputFile << output_data.at(i);
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







	


	
	



	//string y;
	//cout << "Enter destination file:" << endl;
	//cin >> y;
	//cout << "Enter source File " << x << endl;

	//cout << "Program Complete." << endl;

	/*
	myFile -> string  (I want to make a copy of the orginal file )
	

	(DONE)Ask the the user to type in the file of their choice -> "tinypix.ppm"
	print out Enter the source file and the persons input 
			if the user inputs a file that is not in the directory 
			print out a message saying file not included please try again.
			else 
			print out file was found


	(DONE)Ask the user where they would like to put the input into a file -> "output.ppm" 
			if the user inputs a file that is not in the directory 
			print out a message saying file not included please try again.
			else 
			print out file was found 

	I want to sort through the file's content 
		

	

	*/


