#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <exception> //exposes Exception objects
#include <vector> //CH4 -- replaces basic C-style arrays
#include <iomanip> //for making fancy couts and output to file
#include "HelperFunctions.h"
#include "FileHelpers.h"
#include "ListNode.hpp"

//(From PDF notes)
	// • Basic pointers are useful when we need to indirectly 
	//		modify a valuethat is not in our direct scope.
	//this function will compute the square and cube of a number
void square_and_cube(int base, int* square, int* cube)
{
	//use * to "dereference" from memory address to actual value.
	//REQUIRED if we want to modify the value pointed to by the pointer
	//and not the pointer (i.e. memory address)
	*square = base * base;
	*cube = *square * base;
}

int main(int argc, char* argv[])
{
	//17.3 Abstract representation of memory
	//1. How we draw memory on the board

	//square & cube example
	int base = 2;
	int square = 0;
	int cube = 0;

	//use ampresand (&) to convert from basic variable into pointer
	square_and_cube(base, &square, &cube);

	//2. Creating basic pointers(w / o new) in C++
	//format: <data_type>* <variable_name>
	int* base_prt; //this points to ???
				   //it's better to initialize to either a variable
				   //or nullptr
	int* better_example_ptr = nullptr; //assign to nothing
	int* example_that_points_to_something = &square; //points to existing variable
	int& example_reference = square; //references are "safe" pointers
									 //becaues they cannot be null
	//int& empty_reference; //NOT ALLOWED

	//recall, to modify a pointer, one must dereference using *
	*example_that_points_to_something = 5;

	//references act and look like basic variables
	example_reference = 7;

	//	
	//17.3.1
	//1. Sizeof command in C++
	cout << "size of generic int: " << sizeof(int) << endl;
	cout << "size of variable square: " << sizeof(square) << endl;
	cout << "size of pointer: " << sizeof(example_that_points_to_something) << endl;
	cout << "size of reference: " << sizeof(example_reference) << endl;

	//17.4.1
	//1. Free store allocation / deallocation using new / delete
	int* heap_int = new int{ 5 };

	//print all variable addresses
	cout << &base << endl;
	cout << &square << endl;
	cout << &cube << endl;
	cout << &base_prt << endl;
	cout << &better_example_ptr << endl;
	cout << &example_that_points_to_something << endl;
	cout << &example_reference << endl;

	//our dynamically allocated variable should be very far away
	//from our local variable addresses
	cout << heap_int << endl;

	//for every "new", there needs to be a corresponding "delete"
	delete heap_int;

	//after delete, be sure to set back to nullptr
	heap_int = nullptr;

	//17.4.4
	//Allocating / deallocating pointer arrays

	//we're using a single variable to give us access to 
	//10 variables in the free memory store.
	int* int_ptr_array = new int[10];

	//accessing a dyanmically allocated array looks like normal
	//array access
	for (int i = 0; i < 10; i++)
	{
		int_ptr_array[i] = i * i;
		cout << int_ptr_array[i] << endl;
	}

	//to delete array pointers, use delete[]
	delete[] int_ptr_array;

	return 0;
}