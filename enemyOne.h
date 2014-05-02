#pragma once

#include "ofMain.h"
#include "enemyOrbitOne.h"

class enemyOne
{
public:

	//Methods
	void update();
	void display();
	void collisionDetect(ofVec2f, int, int);
	void reset();
	void drawOrbit();
	void updateOrbit();

	bool returnBulletCollided();
	bool returnCollided();

	//Variables
	vector<enemyOrbitOne> orbit;
	ofPoint pos;
	ofVec2f vel;
	int radius;

	bool bulletCollided; 
	bool collided;
	enemyOne(void);
	~enemyOne(void);
};

