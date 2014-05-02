#pragma once

#include "ofMain.h"

class bullet
{
public:
	//Methods
	void update();
	void displayBulletItem();
	void updateBulletItem();
	void display();
	void collisionDetect(ofVec2f, int, int);
	void collisionDetectWithPlayer(ofVec2f, int, int);
	bool returnCollidedWithPlayer();
	bool returnCollided();
	//Getter functions for the bullet
	void setBulletYPos(int);
	void setBulletXPos(int);
	void setBulletPosition(ofVec2f);
	int getTotalBullets();

	//Variables
	ofPoint pos;
	ofVec2f vel, itemPos, itemVel;
	bool collided;
	bool collidedWithPlayer;
	float theta;
	float rotateSpeed;
	int totalBullets;
	//Font
	ofTrueTypeFont bulletstring;
	string bulletTotal;
	void fontLoader();
	void displayString();
	
	bullet(void);
	~bullet(void);
};

