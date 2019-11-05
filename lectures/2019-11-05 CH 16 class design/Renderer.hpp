#pragma once
#include "ScreenWidget.hpp"
class Renderer
{
protected:
	ScreenWidget* _widget = nullptr;
	int _max_width = 0;
	int _max_height = 0;

public:
	Renderer(ScreenWidget* widget, int w = 0, int h = 0)
	{
		_widget = widget;
		_max_width = w;
		_max_height = h;
	}

	~Renderer()
	{
		//always want to be sure to clean up dynamic memory
		if (_widget != nullptr)
		{
			delete _widget;
		}
	}

	virtual void update() = 0;
	virtual void render() = 0;
};