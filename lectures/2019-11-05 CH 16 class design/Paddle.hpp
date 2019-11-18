#pragma once
#include "ScreenWidget.hpp"
class Paddle : public ScreenWidget
{
protected:
	int _width;
	int _height;

public:
	Paddle(int x = 0, int y = 0, int w = 20, int h = 75)
		: ScreenWidget(x, y)
		, _width(w), _height(h)
	{

	}

	int getWidth() const
	{
		return _width;
	}

	void setWidth(int w)
	{
		_width = w;
	}

	int getHeight() const
	{
		return _height;
	}

	void setHeight(int h)
	{
		_height = h;
	}
};