#pragma once //C++ style cross file include prevention for
             //MOST (not all) compilers
#ifndef HELPER_FUNCTIONS_H //C style works with all compilers
#define HELPER_FUNCTIONS_H

#include <string>
using namespace std;

string readLine(string prompt);
int readInt(string prompt);
int toInt(string input);


#endif // !HELPER_FUNCTIONS_H
