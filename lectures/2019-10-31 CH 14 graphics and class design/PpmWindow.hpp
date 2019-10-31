#pragma once
#include "FltkIncludes.h"
#include "PpmDocument.hpp"

class PpmWindow : public Fl_Double_Window
{
private:
	PpmDocument* _doc = nullptr;

	Fl_RGB_Image* _image = nullptr;

	Fl_Box* _image_box = nullptr;

public:
	PpmWindow(int x, int y, int w, int h, const char* l)
		: Fl_Double_Window(x, y, w, h, l)
	{
		_doc = new PpmDocument{ "bunny.ppm" };
		_image_box = new Fl_Box{ 0, 0, w, h };
		_image = new Fl_RGB_Image{ 
			&_doc->getRawBytes()[0], 
			_doc->getWidth(), 
			_doc->getHeight(), 
			3 
		};
		_image_box->image(_image);
	}
};