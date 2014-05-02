#pragma once

#include "ofMain.h"

class particles
{
public:
	// Methods
	void update();
	void display();

	// Variables
	ofPoint pos;
	ofVec3f vel;

	// Constructor
	particles();

};

