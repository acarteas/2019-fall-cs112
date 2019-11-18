#pragma once
class ScreenWidget
{
protected:
	int _x_position;
	int _y_position;
	int _color;

public:
	//56 is equal to the color Black in FLTK
	ScreenWidget(int x = 0, int y = 0, int color = 56)
		: _x_position(x), _y_position(y), _color(color)
	{
	}

	//necessary for polymorphic behavior to have at least
	//one virtual function
	virtual ~ScreenWidget() {};

	int getXPosition() const
	{
		return _x_position;
	}

	void setXPosition(int x)
	{
		_x_position = x;
	}

	int getYPosition() const
	{
		return _y_position;
	}

	void setYPosition(int y)
	{
		_y_position = y;
	}

	int getColor() const
	{
		return _color;
	}

	void setColor(int c)
	{
		_color = c;
	}
};