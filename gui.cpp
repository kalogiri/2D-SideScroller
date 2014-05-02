#include "gui.h"
//This class draws the borders of the screen
void gui::display() {
	ofSetColor(0);
	ofFill();
	ofRect(0,0,700,50);
	ofRect(0,350,700,50);
}

gui::gui(void)
{
}


gui::~gui(void)
{
}
