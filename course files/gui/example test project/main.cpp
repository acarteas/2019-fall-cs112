#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Export.H"

int main(void)
{
	Fl_Window window(200, 200, "Window title");
	Fl_Box box(0, 0, 200, 200, "Hello, World!");
	window.show();
	return Fl::run();
}