#pragma once

#include "ofMain.h"

class player
{
public:

	//Player Image
	ofImage playerImage;

	//fonts
	ofTrueTypeFont health;
	ofTrueTypeFont bulletCount;

	//Variables
	ofVec3f vel;
	ofPoint pos;
	int 
		colorRed,
		colorBlue,
		colorGreen,
		deathCount,
		healthBarWidth,
		width, height;

	bool dead;

	//functions
	void 
		display(),
		update(),
		healthBar(),
		reset(),
		speedCheck(),
		positionCheck(),
		imageLoader(), fontLoader();

	//Setter functions for the bullet
	int 
		returnBulletXps(),
		returnBulletYps();
	
	bool getDead();
	//Constructor
	player();

	//Destructor
	~player();
};

