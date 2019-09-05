# CS 112 PA #2
This assignment begins our multi-week assignment related to image processing.  We will begin very simply but will end up with a complete program capable of applying several effects to multiple image types.  

For this assignment, your task is straightforward: You must read the file "tinypix.ppm" and output its contents to the screen.  However, to make things a bit more complex, you must perform special processing on the first three lines.

The first line represents a particular image specification.  We'll usually see P3.

The two numbers on the 2nd line will later be used to represent a width and height of an image.  Thus they will need to be pulled apart and represented in separate integers.  

The number on the 3rd line represents the maximum color value for each pixel in the image.  It is usually, but not always, a value of 255.  

For the rest of the lines in the file, simply output them unmodified.  In total, your program should output something that looks like the following

```
Image Format: P3
Width: 4 
Height: 4
Max Pixel Value: 255
Data:
0  0  0   100 0  0       0  0  0    255   0 255
0  0  0    0 255 175     0  0  0     0    0  0
0  0  0    0  0  0       0 15 175    0    0  0
255 0 255  0  0  0       0  0  0    255  255 255
```

## Resources
In completing this assignment, the following resources may be of use:
* Chapter 10.4-10.5, 10.10-10.11 in the course textbook
* [Using getline](http://www.cplusplus.com/reference/string/string/getline/)
* [Reading files using ifstream](http://www.cplusplus.com/doc/tutorial/files/)
* [Using getline on an ifstream](https://stackoverflow.com/questions/6663131/reading-a-line-from-ifstream-into-a-string-variable)

## Due date
This assignment is due Monday, September 16, 2019.  

## Submission
To submit your assignment, check your PA #2 code into *the same folder as this readme.*  Then, create a [PA #2 release on github](https://help.github.com/en/articles/creating-releases).

## Grading
This assignment is worth 50 points:
* 45 points for completing the task (demonstrate good progress, regular github checkins, good github comments, maintaining your project board)
* 5 points for your reflection.  For inspiration, see [my prompts](../../docs/sample_reflection.md) 
