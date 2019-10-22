#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Export.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Button.H"
#include "FL/fl_ask.H"
#include "FL/Fl_Widget.H"
#include <string>
#include <exception>
#include <iostream>
#include "BouncingBall.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif

using namespace std;


int main(void)
{
	BouncingBallWindow win{10, 10, 400, 400, "Bouncing Ball"};
	win.end();
	win.show();
	return Fl::run();
}