#include "player.h"

//The player class where all the movements characteristics of the player, the look and the health system.
//The actual movement of the player is handled by the testApp.cpp class


player::player(){
	pos.set(50,200);
	dead = false;
	deathCount = 0;
	height = 40;
	width = 30;
}//Constructor

void player::imageLoader() {
	playerImage.loadImage("player50.png");
}

void player::fontLoader() {
	health.loadFont("VCR_OSD_MONO.ttf", 10);
}
void player::update() {
	pos += vel;
	
	//The health bar change as the player gets hit
	switch (deathCount) {		
		default:
			healthBarWidth = 100;
			break;

		case 1:
			healthBarWidth = 75;
			break;

		case 2:
			healthBarWidth = 50;
			break;

		case 3:
			healthBarWidth = 25;
			break;
		
		case 4:
			healthBarWidth = 0;
			break;
	}//end switch

	if(deathCount >= 4) {
		dead = true;
	}
	
}//Update

bool player::getDead() { return dead; }

void player::healthBar() {
	ofSetColor(33,143,3);
	ofFill();
	health.drawString("HP", 20, 30);
	ofRect(50, 20, healthBarWidth, 10);
}

void player::speedCheck() {
	if(vel.x >= 2) {
		vel.x = 2;
	}
	if(vel.x <= -2) {
		vel.x = -2;
	}

	if(vel.y >= 2) {
		vel.y = 2;
	}
	if(vel.y <= -2) {
		vel.y = -2;
	}
}


void player::positionCheck() {
	if(pos.x >= 600 && vel.x > 1) {
		pos.x = -25;
	}

	if(pos.x <= 0 && vel.x < 1) {
		pos.x = 0;
		vel.x += 0.1;
	}

	if(pos.y <= 50) {
		pos.y = 50;
		vel.y +=0.1;
	}

	if(pos.y >= 325) {
		pos.y = 325;
		vel.y -= 0.1;
	}

	
}

void player::reset() {
	pos.set(50,200);
	vel.set(0,0);
	dead = false;
	deathCount = 0;
}


void player::display() {
	healthBar();	
	ofSetColor(255);
	playerImage.draw(pos.x,pos.y,width,height);
	positionCheck();
	speedCheck();
}//Display

//Getters for the bullet
int player::returnBulletXps(){
	return pos.x;
}//returnBulletXpos

int player::returnBulletYps(){
	return pos.y;
}//returnBulletYPos

player::~player(void){
}//Deconstructor
