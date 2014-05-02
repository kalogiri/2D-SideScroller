#pragma once

#include "ofMain.h"

class enemyOrbitTwo
{
public:
	float theta;
	float diameter;
	float distance;
	float orbitSpeed;
	ofVec2f pos;

	void update();
	void display();
	
	enemyOrbitTwo(void);
	~enemyOrbitTwo(void);
};

