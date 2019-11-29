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
public:
	BallRenderer(Ball* b, int w = 0, int h = 0) 
		: Renderer(b, w, h)
	{
	}

	virtual void update()
	{
		//to convert from a generic widget into a ball,
		//we must use dynamic casting
		Ball* ball = dynamic_cast<Ball*>(_widget);

		//null check to make sure cast succeeded
		//if properly coded, should always succeed
		if (ball != nullptr)
		{
			bool did_bounce = false;
			if (ball->getXPosition() + ball->getDiameter() >= _max_width
				||
				ball->getXPosition() <= 0)
			{
				ball->setXVelocity(rand() % 3 + 1);
				ball->setXDirection(-1 * ball->getXDirection());
				did_bounce = true;

			}
			if (ball->getXPosition() + ball->getDiameter() >= _max_height
				||
				ball->getYPosition() <= 0
				)
			{
				ball->setYVelocity(rand() % 3 + 1);
				ball->setYDirection(-1 * ball->getYDirection());
				did_bounce = true;
			}

			if (did_bounce == true)
			{
				//change color on bounce
				//const vector<Fl_Color>& colors = window->getPossibleColors();
				//int index = rand() % colors.size();
				//ball->setColor(colors[index]);
			}

			int new_x = ball->getXPosition() + (ball->getXDirection() * ball->getXVelocity());
			int new_y = ball->getYPosition() + (ball->getYDirection() * ball->getYVelocity());

			//post processing - don't ever allow _ball to go out of window bounds
			if (new_x < 0)
			{
				new_x = 0;
			}
			else if (new_x + ball->getDiameter() > _max_width)
			{
				new_x = _max_width - ball->getDiameter();
			}
			if (new_y < 0)
			{
				new_y = 0;
			}
			if (new_y + ball->getDiameter() > _max_height)
			{
				new_y = _max_height - ball->getDiameter();
			}

			ball->setXPosition(new_x);
			ball->setYPosition(new_y);
		}
	}
	virtual void render()
	{
		Ball* ball = dynamic_cast<Ball*>(_widget);
		if (ball != nullptr)
		{
			fl_color(ball->getColor());
			fl_pie(
				ball->getXPosition(),
				ball->getYPosition(),
				ball->getDiameter(),
				ball->getDiameter(),
				0,
				360);
		}
	}
};