//
//  main.cpp
//  Duplicate words
//
//  Created by Ryan Guyton on 8/27/19.
//  Copyright © 2019 Ryan Guyton. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//1. (p. 73) Prompt user for a string. Remove adjacent duplicate words.
// I I went to the the store this morning ---> I went to the store this morning
string removeAdjacentDuplicatesV2(string original)
{
    string previous;
    string current;
    string result;
    
    
    int index = 0;
    while (index < original.length())
    {
        int space_index = original.find(' ', index);
        //        substing - a sequence of adjacent characters within an existing string
        //        string temp = original.substr(0, 1);
        
        current = original.substr(index, space_index - index);
        
        if (current != previous)
        {
//            add word
            result += current + " ";
        }
        
        
        if (space_index == -1)
        {
            index = original.length();
        }
        else
        {
            index = space_index + 1;
        }
        previous = current;
        
    }
    return result.substr(0, result.length() - 1);
}
int main(void)
{
    cout << removeAdjacentDuplicatesV2("I I went to the the store this morning") << endl;
}
