# CS 112 Image Manipulator Milestone #4
In this final milestone of the semester, you will transfer the image effects that you've been working on all semester into a proper graphical user interface (GUI).  We will be using the FLTK, which is discussed extensively in our textbook.  Begin by forking my [ppm-viewer](https://github.com/acarteas/ppm-viewer) code on github.

_*Note*_: My starter code will need to be tweaked when working on Mac or Linux machines.  I will be helping students with these issues during lab or office hours.  

# Tasks
In order to receive full credit on your milestone, you will need to implement the following functionality.

## Add additional effects to effects menu
On line 21 of PpmWindow.hpp, I begin declaring the menu options for the various image effects that you have developed in class.  You will need to extend this list with all of the effects that you have created over the semester.  _*Note:*_ Only include completed, working effects in your menu dropdown.

## Reimplement your image effects using ImageEffect as a base class
In completing this milestone, you will be exposed to advanced software design principles.  As part of that, you will be creating a class for each image effect supported by your program.  Each class should be in its own .HPP file.  Take a look at the included RemoveRedEffect.hpp to see how to do this.

Once you create a new class, you will need to add it to the ImageEffectType enum (EffectFactory.hpp line 4) as well as adding it as an option to the crateEffect function on line 14 of EffectFactory.hpp.


# Due date
This assignment is due Wednesday, December 11, 2019. 

# Submission
To submit your assignment, check your code into your repository.  Be sure to include your milestone   as well.  Note, there is no need to make a demo GIF for this deliverable.

# Grading
This assignment is worth 100 points:
* 60 points for reglarly working on the project (demonstrate good progress, regular github checkins, good github comments, maintaining your project board)
* 20 points for correct program output (i.e. all of your image effects work properly)
* 10 points for demonstrating progress during checkins 
* 10 points for your reflection.  For inspiration, see [my prompts](../../docs/sample_reflection.md) 
