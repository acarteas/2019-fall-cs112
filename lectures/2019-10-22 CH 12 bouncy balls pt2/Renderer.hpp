#pragma once
class Renderer
{
protected:
	int _max_width = 0;
	int _max_height = 0;

public:
	Renderer(int w = 0, int h = 0)
	{
		_max_width = w;
		_max_height = h;
	}

	virtual void update() = 0;
	virtual void render() = 0;
};