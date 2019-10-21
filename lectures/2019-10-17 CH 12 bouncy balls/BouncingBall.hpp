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
	int diameter = 20;
	int x_direction = 1;
	int y_direction = 1;
	int x_velocity = 1;
	int y_velocity = 1;
	Fl_Color ball_color = FL_BLACK;
	vector<Fl_Color> possible_colors;

	static void renderLoop(void* win)
	{
		BouncingBallWindow* window = (BouncingBallWindow*)win;
		
		if (window != nullptr)
		{
			bool did_bounce = false;
			if (window->getBallX() + window->getDiameter() >= window->w()
				||
				window->getBallX() <= 0)
			{
				window->setXVelocity(rand() % 3 + 1);
				window->setXDirection(-1 * window->getXDirection());
				did_bounce = true;

			}
			if (window->getBallY() + window->getDiameter() >= window->h()
				||
				window->getBallY() <= 0
				)
			{
				window->setYVelocity(rand() % 3 + 1);
				window->setYDirection(-1 * window->getYDirection());
				did_bounce = true;
			}

			if (did_bounce == true)
			{
				//change color on bounce
				const vector<Fl_Color>& colors = window->getPossibleColors();
				int index = rand() % colors.size();
				window->setColor(colors[index]);
			}

			int new_x = window->getBallX() + (window->getXDirection() * window->getXVelocity());
			int new_y = window->getBallY() + (window->getYDirection() * window->getYVelocity());
			
			//post processing - don't ever allow ball to go out of window bounds
			if (new_x < 0)
			{
				new_x = 0;
			}
			else if (new_x + window->getDiameter() > window->w())
			{
				new_x = window->w() - window->getDiameter();
			}
			if (new_y < 0)
			{
				new_y = 0;
			}
			if (new_y + window->getDiameter() > window->h())
			{
				new_y = window->h() - window->getDiameter();
			}

			window->setBallX(new_x);
			window->setBallY(new_y);
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
		fl_color(getColor());
		fl_pie(ball_x, ball_y, diameter, diameter, 0, 360);

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
	}

	int getBallX() const
	{
		return ball_x;
	}

	int getBallY() const
	{
		return ball_y;
	}

	int getDiameter() const
	{
		return diameter;
	}

	void setBallX(int x)
	{
		ball_x = x;
	}

	void setBallY(int y)
	{
		ball_y = y;
	}

	int getXDirection() const
	{
		return x_direction;
	}

	int getYDirection() const
	{
		return y_direction;
	}

	void setXDirection(int dir)
	{
		x_direction = dir;
	}

	void setYDirection(int dir)
	{
		y_direction = dir;
	}

	int getXVelocity() const
	{
		return x_velocity;
	}

	int getYVelocity() const
	{
		return y_velocity;
	}

	void setXVelocity(int v)
	{
		x_velocity = v;
	}

	void setYVelocity(int v)
	{
		y_velocity = v;
	}

	Fl_Color getColor() const
	{
		return ball_color;
	}

	void setColor(Fl_Color c)
	{
		ball_color = c;
	}

	const vector<Fl_Color>& getPossibleColors() const
	{
		return possible_colors;
	}
};