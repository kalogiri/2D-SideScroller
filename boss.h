#pragma once

#include "ofMain.h"
class boss
{
public:
	//General Variables for the boss
	ofVec2f enemy_position;
	ofVec2f enemy_velocity;

	bool collided_with_bullet;
	bool dead;
	bool bossSpawn;

	int enemyWidth;
	int enemyHeight;
	int deathCount;
	int time;

    //General Functions for the boss
	bool getDead();
	int getTime();
	void readTime();
	void display();
	void update();
	void enterBoss();
	void collision_with_bullet(ofVec2f , int , int);
	bool returnBulletCollided();
	void healthSystem();
	void reset();

	//Boss's bullet/beam variables and functions
	ofVec2f beamPos;
	ofVec2f bossBullet;

	float beamHeight;
	float beamWidth;
	float fade;

	int shootCounter;
	int counter;

	bool counterStart;
	bool beamShot;
	bool collided;

	void beamRun();

	void collisionDetect(ofVec2f, int, int);
	bool returnCollided();

	//Image
	void imageLoader();
	ofImage bossImage;
	
	boss(void);
	~boss(void);
};

