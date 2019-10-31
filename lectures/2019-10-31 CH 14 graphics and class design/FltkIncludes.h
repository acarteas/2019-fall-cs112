#pragma once
#ifndef FLTK_INCLUDES_H
#define FLTK_INCLUDES_H

#ifdef WIN32
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
#include "FL/Fl_Menu_Item.H"
#include "FL/Fl_Sys_Menu_Bar.H"

#else
//Mac / LINUX includes
#endif

#endif // !FLTK_INCLUDES_H
