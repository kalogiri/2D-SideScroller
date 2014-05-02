#pragma once

#include "ofMain.h"

class timer
{
public:
	void timerBarDisplay();
	void timerBarColorUpdate();
	void drawTimerObject();
	void updateTimerObject();
	void reset();
	bool returnCollided();
	bool returnResetBar();
	bool getDead();
	void collisionDetect(ofPoint, int, int);

	ofVec2f vel;
	ofPoint pos;

	//The color variables for the timer bar
	float
		colG, 
		colB, 
		colR, 
		colGDraw,
		colBDraw,
		colRDraw;

	//Dimensions of the timer bar
	float dimX,	dimY;
	bool collided, dead;
	bool resetBar;

	timer(void);
	~timer(void);
};

