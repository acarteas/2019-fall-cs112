#pragma once
class Ball
{
private:
	int _ball_x = 0;
	int _ball_y = 0;
	int _diameter = 20;
	int _x_direction = 1;
	int _y_direction = 1;
	int _x_velocity = 1;
	int _y_velocity = 1;
	int _color = 56;
public:
	int getX() const
	{
		return _ball_x;
	}

	void setX(int x)
	{
		_ball_x = x;
	}

	int getY() const
	{
		return _ball_y;
	}

	void setY(int y)
	{
		if (y > 0)
		{
			_ball_y = y;
		}
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

	int getColor() const
	{
		return _color;
	}

	void setColor(int c)
	{
		_color = c;
	}
};