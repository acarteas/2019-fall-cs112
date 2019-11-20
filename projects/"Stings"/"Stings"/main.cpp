//
//  main.cpp
//  "Stings"
//
//  Created by Ryan Guyton on 9/3/19.
//  Copyright © 2019 Ryan Guyton. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>
using namespace std;

string readLine(string prompt); //can put this in a header file "header.h" so you don't need to write it in every cpp file
int readInt(string prompt);

string readLine(string );

int readInt(string prompt)
{
    string result = readLine(prompt);
    int number = -1; //define number outside of try to maintain scope
    
    bool is_valid_number = false;
    while (is_valid_number == false)
    {
    
    try {
        number = stoi(result);
        catch (invalid_argument ex)
        {
            cout << "Please enter a valid integer. \n" << endl;
        
        }
        catch (out_of_range ex)
        {
            cout << "Number is too big" << endl;
        }
    } catch (...) {
        cout << "Something really bad happened." << endl;
    }
    }
}

string readLine(string prompt)
{
    cout << prompt;
    string line;
    try {
        getline(cin, line);
    } catch (ios_base::failure) {
        cout << "Error reading from keyboad: " << ex.what() << endl;
    }
    getline(cin, line);
    return line;
}

int main_sandbox(void)
{
    int some_numbers; //is a C "object"
    string word;  //this is a C++
    
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << numbers[11] << endl;
    
    vector<int> numbers_vect{};
    
    numbers_vect.resize(10);
    
    cout << numbers_vect[11] << endl;
    
    try
    {
        cout << numbers_vect.at(11) << endl;
        
    }
    catch (out_of_range ex)
    {
        cout << "Exception: " << ex.what() << endl;
    }
//    equivalent to IF's ELSE (catches ALL exceptions)
    catch (...)
    {
        cout << "Something broke, don't know why!" << endl;
    }
    
    
    return 0;
    }

int main(void)
{
    
    vector<int> numbers{};
    
    int user_input = 0;
    while (user_input != -1)
    {
        user_input = readInt("enter a number (-1 to exit): ");
    }
//    easiest and most convienient way to put things in vector
    numbers.push_back(user_input);
    //read numbers from keyboad until -1 is entered

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i) << endl;
    }
    
//    generic modern C++ for getting things out of a data container (e.g. vector, linked list, hashtable, etc.)
    for (auto item : numbers)
    {
        cout << item << endl;
        
    }
    
    return 0;
         }
