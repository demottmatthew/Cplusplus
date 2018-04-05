#include <iostream>
#include "Simple_window.h"    
#include "Graph.h"            
#include "FL/Fl_Button.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Float_Input.H"
using namespace std;

Fl_Button *clearButton, *convertToCelButton, *convertToFButton;
Fl_Float_Input *inputFarenheit, *inputCelsius;


float toCelsius(float val)
{
	
	return (val - 32.0f) * 5.0f / 9.0f;
}

float toFarenheit(float val)
{
	return val * (9.0f / 5.0f) + 32.0f;
}


void ClearFields()
{
	inputFarenheit->value("");
	
	inputCelsius->value("");
}

void DisplayF(float val)
{
	float v = toFarenheit(val);
	string s;
	s = to_string(v);
	inputFarenheit->value(s.c_str());
}

void DisplayC(float val)
{
	float v = toCelsius(val);
	string s;
	s = to_string(v);
	inputCelsius->value(s.c_str());
}

void ButtonCallback(Fl_Widget *widget)
{
	ClearFields();
}
void ConvertToCCallback(Fl_Widget *widget)
{
	string check;
	check = inputFarenheit->value();
	if (check.compare("")) {
		float val = (float)atof(inputFarenheit->value());
		DisplayC(val);
	}
	
}
void ConvertToFCallback(Fl_Widget *widget)
{
	string check;
	check = inputCelsius->value();
	if (check.compare("")) {
		float val = (float)atof(inputCelsius->value());
		DisplayF(val);
	}
}


int main()
{
	Simple_window sw(Point(500, 250), 600, 200, "Temperature Converter");
	inputFarenheit = new Fl_Float_Input(150, 50, 200, 30, "Input Fahrenheit");
	inputCelsius = new Fl_Float_Input(150, 85, 200, 30, "Output Celsius");
	convertToCelButton = new Fl_Button(360, 50, 150, 30, "Convert to Celsius");
	convertToFButton = new Fl_Button(360, 85, 150, 30, "Convert to Fahrenheit");
	clearButton = new Fl_Button(450, 150, 40, 30, "Clear");

	convertToCelButton->callback(&ConvertToCCallback);
	convertToFButton->callback(&ConvertToFCallback);
	clearButton->callback(&ButtonCallback);

	sw.add(inputFarenheit);
	sw.add(inputCelsius);
	sw.add(clearButton);
	sw.add(convertToFButton);
	sw.add(convertToCelButton);
	sw.show();
	return gui_main();
}

