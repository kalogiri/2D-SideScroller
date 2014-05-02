#pragma once

#include "ofMain.h"

class enemyOrbitThree
{
public:

	float theta;
	float diameter;
	float distance;
	float orbitSpeed;
	float yOffset;
	float xOffset;
	int centerX;
	int topY;
	int equilibriumY;
	bool enemyTypeOne, enemyTypeTwo, enemyTypeThree;
	ofVec2f pos;

	void update();
	void display(int);
	void collisionDetect(ofVec2f, int, int);
	bool returnCollided();

	enemyOrbitThree(void);
	~enemyOrbitThree(void);
};

