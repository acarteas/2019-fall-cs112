# PA2 Reflection - Peter Boster - 09/14/2019

For this project, the assignment was to create a program that could read the lines of a .ppm image file and to preform special proccesing on each line of the file such that it was outputted in an organized way like so:

    Image Format: P3
    Width: 4 
    Height: 4
    Max Pixel Value: 255
    Data:
    0  0  0   100 0  0       0  0  0    255   0 255
    0  0  0    0 255 175     0  0  0     0    0  0
    0  0  0    0  0  0       0 15 175    0    0  0
    255 0 255  0  0  0       0  0  0    255  255 255

To start this project, I created a void function called imageProcessor(), with a string parameter input_file so that I could process any .ppm image file. I knew from my past CS class that I should be using the ifstream to read from the file, and getline() to extract the lines of the file into a variable, line. The first line was easy for me as it just required a call of getline(), and for the variable line to be printed out. The second line was significantly harder. I had heard in class that getline()had three parameters, an input stream, a variable to store the line, and a delimiter. I didn't know how the delimiter worked, as most of the time I used getline() I had used it with only two parameters. Because of this, I looked up getline() and found a [getline() manual](http://www.cplusplus.com/reference/istream/istream/getline/) that confirmed that getline() had a character delimiter that was a newline character by default. I then tried the following code:

    getline(picdata, line, ' ');
    cout << "Height: " << line << endl;
    getline(picdata, line)
    cout << "Width: " << line << endl;

This code worked, so I continued to the third line which was pretty much the same as the first. The last lines of data processing were also relatively easy for me as I remebered the .eof() method and knew that I could use it in a while loop with getline() to read each line and stop at the end of the file.

Since all this code worked, and I had it finished early, I decided I would try to add some filters for comments. This really messed me up for some reason, because when I ran the code, the output would be jumbled. After trying to fix it, I decided it wasnt worth messing up my working code to filter the comments, so I decided to ship the program as it was. From this project I learned that overcomplicating code can lead to a huge headache when it comes to debugging. I also learned that it's way faster to buld and test things line by line so that it's a lot easier to tell where your code is going wrong. Last year I think that was my biggest problem, and from trying everything line by line I realized I was able to finish the code far faster. My final lesson was to pay attention in class. I spaced out while the teacher went over setting the relative path for input files, and that cost me about an hour of time trying to figure out why the file wouldn't open when I ran the code on the school computer.

To see the finished product, you can view the [full code](https://github.com/pab15/2019-fall-cs112/blob/master/projects/pa2/ImageProcessor/ImageProcessor/main.cpp) and a [gif](https://github.com/pab15/2019-fall-cs112/blob/master/projects/pa2/ImageProcessor.gif) of the code running at the given links.