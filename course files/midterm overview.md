# CS 112 Midterm
Use the following guide to help you study for the midterm next lab:

## Midterm Rules
* Closed book, closed note, closed friend, closed internet

## Tips
* If you get stuck on one problem, skip it and move on to the next

### Question #1: Fizzbuzz
Complete a function called fizzbuzz that does the following ([example here](https://www.hackerrank.com/challenges/fizzbuzz/problem)):
1. Output 50 lines to the screen with cout **using a FOR loop** (e.g. for(int i = 1; i < 50; i++)
2. If the line number is a multiple of 3, print "Fizz"
3. If the line number is a multiple of 5, print "Buzz"
4. If the line number is a mulitple of both 3 and 5, print "FizzBuzz"
5. If none of the above is true, print the line number (starting at 1).

Example output:
```
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
...
```

### Question 2: Basic File Reading
Complete a function that reads a file's contents and outputs those contents to the screen using cout.  Example function prototype:
```
void readFile(string file_name) {}
```

### Question 3: File I/O
Complete a function that reads all numbers in a file and writes the average of these numbers to an output file.  Example function prototype:
```
void computeAverage(string input_file, string output_file) {}
```

### Question 4: Pretty formatting
Complete a function that accepts a vector of floating point numbers (i.e. ```doubles```) and outputs them with a precision of two decimal places in nice columns.  
Example function prototype:
```
void displayNumbers(vector<double>& data) {}
```
Example output:
```
123.45   4.56   78.90
 98.76  54.32    1.01  
```

### Question 5: Exception Handling
Place try/catch blocks around dangerous code to prevent runtime exceptions from occurring.  Remember, you want as little code as possible in your try{} blocks.

### Question 6: Complete a class
Given a description of a real-world object, create a class with private member variables and basic getters and setters

### Question 7: Sentence counter
Write a function that counts the number of sentences in a word.  For this function, a sentence is always terminated by a period.  
Examples:

(one sentence) "This string has one sentence."

(four sentences) "This. Second. Example. Has four sentences."

Function prototype:
```
int numberOfSentences(string text) {}
```

### Question 8: Longest sentence
Write a function that calculates the length of the longest sentence in a string.  

Examples:

(5) "This string has one sentence."

(3) "This. Second Example has. three sentences."

Function prototype:
```
int longestSentence(string text) {}
```
