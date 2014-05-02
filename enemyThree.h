#pragma once

#include "ofMain.h"
#include "enemyOrbitThree.h"


class enemyThree
{
public:
	//Methods
	void update();
	void display();
	void collisionDetect(ofVec2f, int, int);
	bool returnCollided();
	void updatePosition();
	void drawOrbiter();
	void updateOrbiter();

	//Variables
	ofPoint pos;
	ofVec2f vel;
	bool collided;
	int width, height, theta, rotateSpeed;
	float y, dy, k, m;
	vector<enemyOrbitThree> orbiter;
	

	enemyThree(void);
	~enemyThree(void);
};

