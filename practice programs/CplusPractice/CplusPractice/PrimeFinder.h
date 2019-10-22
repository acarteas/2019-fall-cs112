#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "TestFunctions.h"
using namespace std;

bool isPrime(int test_int);
void findPrimeInRange(int min_input, int max_input);

#endif // !HEADER_H