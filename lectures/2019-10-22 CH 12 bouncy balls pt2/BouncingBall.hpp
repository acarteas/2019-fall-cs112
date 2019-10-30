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
#include <random>
#include <ctime>
#include <vector>
#include "Ball.hpp"
#include "BallRenderer.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
using namespace std;
class BouncingBallWindow : public Fl_Double_Window
{
private:
	Fl_Color ball_color = FL_BLACK;
	vector<Fl_Color> possible_colors;
	vector<Ball> _balls;

	static void renderLoop(void* win)
	{
		BouncingBallWindow* window = (BouncingBallWindow*)win;
		
		if (window != nullptr)
		{
			for (auto& ball : window->getBalls())
			{
				//AC: not the best idea: TODO: rewrite!
				BallRenderer r{ ball, window->w(), window->h() };
				r.update();
			}
			
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
		for (auto& ball : _balls)
		{
			//AC: not the best idea: TODO: rewrite!
			BallRenderer r{ ball, w(), h() };
			r.render();
		}
		

	}

	virtual int handle(int event)
	{
		if (event == FL_PUSH)
		{
			//ball_x = Fl::event_x();
			//ball_y = Fl::event_y();
		}
		return 0;
	}

public:
	BouncingBallWindow(int x, int y, int w, int h, const char* l)
		: Fl_Double_Window(x, y, w, h, l) 
	{
		srand(time(NULL));
		Fl::add_timeout(1, renderLoop, this);

		//initialize color list
		possible_colors = vector<Fl_Color>{
		FL_BLACK,
			FL_BLUE,
			FL_CYAN,
			FL_DARK_BLUE,
			FL_DARK_CYAN,
			FL_DARK_GREEN,
			FL_DARK_MAGENTA,
			FL_DARK_RED,
			FL_DARK_YELLOW,
			FL_GREEN,
			FL_MAGENTA,
			FL_RED,
			FL_YELLOW,
		};

		for (int i = 0; i < 15; i++)
		{
			_balls.push_back(Ball{});
		}
	}

	vector<Ball>& getBalls()
	{
		return _balls;
	}

	const vector<Fl_Color>& getPossibleColors() const
	{
		return possible_colors;
	}
};