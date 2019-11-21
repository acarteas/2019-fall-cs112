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
#include "Renderer.hpp"
#include "Ball.hpp"
class BallRenderer : public Renderer
{
private:
	Ball& _ball;
public:
	BallRenderer(Ball& b, int w = 0, int h = 0) : Renderer(w, h)
		, _ball(b)
	{
	}

	virtual void update()
	{
		bool did_bounce = false;
		if (_ball.getX() + _ball.getDiameter() >= _max_width
			||
			_ball.getX() <= 0)
		{
			_ball.setXVelocity(rand() % 3 + 1);
			_ball.setXDirection(-1 * _ball.getXDirection());
			did_bounce = true;

		}
		if (_ball.getX() + _ball.getDiameter() >= _max_height
			||
			_ball.getY() <= 0
			)
		{
			_ball.setYVelocity(rand() % 3 + 1);
			_ball.setYDirection(-1 * _ball.getYDirection());
			did_bounce = true;
		}

		if (did_bounce == true)
		{
			//change color on bounce
			//const vector<Fl_Color>& colors = window->getPossibleColors();
			//int index = rand() % colors.size();
			//_ball.setColor(colors[index]);
		}

		int new_x = _ball.getX() + (_ball.getXDirection() * _ball.getXVelocity());
		int new_y = _ball.getY() + (_ball.getYDirection() * _ball.getYVelocity());

		//post processing - don't ever allow _ball to go out of window bounds
		if (new_x < 0)
		{
			new_x = 0;
		}
		else if (new_x + _ball.getDiameter() > _max_width)
		{
			new_x = _max_width - _ball.getDiameter();
		}
		if (new_y < 0)
		{
			new_y = 0;
		}
		if (new_y + _ball.getDiameter() > _max_height)
		{
			new_y = _max_height - _ball.getDiameter();
		}

		_ball.setX(new_x);
		_ball.setY(new_y);
	}
	virtual void render()
	{
		fl_color(_ball.getColor());
		fl_pie(
			_ball.getX(),
			_ball.getY(),
			_ball.getDiameter(),
			_ball.getDiameter(),
			0,
			360);
	}
};