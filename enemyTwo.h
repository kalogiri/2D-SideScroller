#pragma once

#include "ofMain.h"
#include "enemyOrbitTwo.h"

class enemyTwo
{
public:
	//Methods
	void update();
	void display();
	void collisionDetect(ofVec2f, int, int);
	void updateOrbit();
	void drawOrbit();
	bool returnCollided();
	
	//Variables
	ofPoint pos;
	ofVec2f vel;
	bool collided;
	int width, height;

	vector<enemyOrbitTwo> orbit;

	enemyTwo(void);
	~enemyTwo(void);
};

