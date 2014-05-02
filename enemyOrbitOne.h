#pragma once

#include "ofMain.h"

class enemyOrbitOne
{
public:
	float theta;
	float diameter;
	float distance;
	float orbitSpeed;
	ofVec2f pos;

	void update();
	void display();
	
	enemyOrbitOne(void);
	~enemyOrbitOne(void);
};

