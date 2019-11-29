#pragma once
#include "ScreenWidget.hpp"
class Ball : public ScreenWidget
{
protected:
	int _diameter = 20;
	int _x_direction = 1;
	int _y_direction = 1;
	int _x_velocity = 1;
	int _y_velocity = 1;
public:

	Ball(int x = 0, int y = 0)
		: ScreenWidget(x, y)
	{

	}

	int getDiameter() const
	{
		return _diameter;
	}

	void setDiameter(int diameter)
	{
		_diameter = diameter;
	}

	int getXDirection() const
	{
		return _x_direction;
	}

	void setXDirection(int dir)
	{
		_x_direction = dir;
	}

	int getYDirection() const
	{
		return _y_direction;
	}

	void setYDirection(int dir)
	{
		_y_direction = dir;
	}

	int getXVelocity() const
	{
		return _x_velocity;
	}

	void setXVelocity(int v)
	{
		_x_velocity = v;
	}

	int getYVelocity() const
	{
		return _y_velocity;
	}

	void setYVelocity(int v)
	{
		_y_velocity = v;
	}
};