Create a new project of type "General", "Empty Project" and add a simple "C++"
file to it. The FLTK "hello" source code is a good base.

Now open the Project Properties dialog and add "Comctl32.lib" and all the FLTK
libraries that you want to use (at least "fltk.lib") to Additional Dependencies
(Configuration Properties > Linker > Additional Dependencies). In the same
dialog, add "WIN32" to the C++ Preprocessor Definitions (Configuration
Properties > C/C++ > Preprocessor > Preprocessor Definitions).
