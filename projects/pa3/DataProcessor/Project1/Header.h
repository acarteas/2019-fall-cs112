#pragma once
#ifndef FILE_HELPERS_H
#define FILE_HELPERS_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Used From Lecture 8:

vector<string> readFile(ifstream& some_file);
vector<string> readFile(const string& file_name);

#endif
