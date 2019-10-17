#pragma once

#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Export.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Button.H"
#include "FL/fl_ask.H"
#include "FL/Fl_Widget.H"
#include "FL/Fl_Double_Window.H"
#include "FL/fl_draw.H"
#include "FL/math.h"
#include <string>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
using namespace std;
class BouncingBallWindow : public Fl_Double_Window
{
private:
	int ball_x = 0;
	int ball_y = 0;

	static void renderLoop(void* win)
	{
		BouncingBallWindow* window = (BouncingBallWindow*)win;
		if (window != nullptr)
		{
			window->setBallX(window->getBallX() + 1);
			window->setBallY(window->getBallY() + 1);
			window->redraw();
		}
		Fl::repeat_timeout(.016, renderLoop, win);
	}

	void draw()
	{
		//clear background
		fl_color(FL_WHITE);
		fl_rectf(0, 0, w(), h());

		//draw circle
		fl_color(FL_BLACK);
		fl_pie(ball_x, ball_y, 10, 10, 0, 360);

	}

public:
	BouncingBallWindow(int x, int y, int w, int h, const char* l)
		: Fl_Double_Window(x, y, w, h, l) 
	{
		Fl::add_timeout(1, renderLoop, this);
	}

	int getBallX() const
	{
		return ball_x;
	}

	int getBallY() const
	{
		return ball_y;
	}

	void setBallX(int x)
	{
		ball_x = x;
	}

	void setBallY(int y)
	{
		ball_y = y;
	}
};