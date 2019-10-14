# CS 112 Image Manipulator Milestone #2
Milestone #2 extends Milestone #1 by adding two additional image effects as well as allowing the user to apply multiple image effects at one time.  

## 1. Add random noise
This effect will add random noise to the image by randomly selecting a value ranging from -10 to 10 and adding that value to the pixel's current value.  If the addition causes the pixel value to be less than 0, then set to 0.  Likewise, if the addition causes the pixel's value to be greater than 255, just set the pixel's value to 255.  For example, we randomly generate the number -7.  Next, we add -7 to each of the current pixel's red, green, and blue values.
![noise](bunny_noise.png) 

## 2. High contrast
For each RGB value in a given pixel, if the color is greater than half of 255, then max the color out (i.e. set to 255).  Otherwise, set the value to 0.  For example, performing a high contrast operation on a pixel whose RGB values are 170, 50, 100 would result in an RGB value of 255, 0, 0.
![high contrast](bunny_hc.png) 

## 3. Effect chaining
Instead of applying a single image effect and then exiting the program, you must now allow the user to apply multiple effects before the program quits.  Example:

```
Enter source file: bunny.ppm
Enter destination file: output.ppm

*** Image Effects ***
1. Remove Red
2. Remove Blue
3. Remove Green
4. Negate Red
5. Negate Blue
6. Negate Green
7. Grayscale
8. Add noise
9. High contrast
Q. Quit

Selection: 4
Applying Negate Red Effect...

Selection: 5
Applying Negate Blue Effect...

Selection: 6
Applying Negate Green Effect...

Selection: Q
Program exiting...
```

In the above example, I negated red, green, and blue, which would yield the following image:
![high contrast](bunny_negate.png) 

# Due date
This assignment is due Monday, October 28, 2019. 

# Submission
To submit your assignment, check your code into your new CS112-ImageManipulation repository.  Inside the deliverables\m2 subdirectory, place your output files for each image effect using the provided bunny2.ppm.  Include your milestone #2 reflection in this folder as well.  Note, there is no need to make a demo GIF for this deliverable.

# Grading
This assignment is worth 100 points:
* 60 points for reglarly working on the project (demonstrate good progress, regular github checkins, good github comments, maintaining your project board)
* 20 points for correct program output (i.e. all of your image effects work properly)
* 10 points for demonstrating progress during checkins 
* 10 points for your reflection.  For inspiration, see [my prompts](../../docs/sample_reflection.md) 
