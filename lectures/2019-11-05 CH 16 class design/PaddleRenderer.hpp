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
#include "Paddle.hpp"
class PaddleRenderer : public Renderer
{
private:
public:
	PaddleRenderer(Paddle* p, int w = 0, int h = 0)
		: Renderer(p, w, h)
	{
	}

	virtual void update()
	{
		
	}
	virtual void render()
	{
		Paddle* paddle = dynamic_cast<Paddle*>(_widget);
		if (paddle != nullptr)
		{
			fl_color(paddle->getColor());
			fl_line_style(FL_SOLID, paddle->getWidth());
			fl_line(
				paddle->getXPosition(),
				paddle->getYPosition(),
				paddle->getXPosition(),
				paddle->getYPosition() + paddle->getHeight()
				);
			fl_line_style(0);
		}
	}
};