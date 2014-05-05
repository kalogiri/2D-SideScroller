#include "bullet.h"

bullet::bullet(){
	vel.set(3,0);
	itemPos.set(600, ofRandom(55,330));
	itemVel.set(ofRandom(-1,-3),0);
	collidedWithPlayer = false;
	collided = false;
	theta = 0;
	rotateSpeed += 3;
	totalBullets = 0;
}//Constructor

/*
	*********************************************************************
	Setter functions for the bullet positions so the getter function
	in the player class allows the bullets position to change with the
	players position. Also allows you to change where the bullets starts.

	*********************************************************************
*/

void bullet::fontLoader() {
	bulletstring.loadFont("VCR_OSD_MONO.ttf", 10);
}

void bullet::setBulletXPos(int psX) {
	pos.x = psX;
}//setXPos

void bullet::setBulletYPos(int psY){
	pos.y = psY + 15;
}//setYPos

void bullet::setBulletPosition(ofVec2f setPos) {
	pos.x = setPos.x;
	pos.y = setPos.y;
}

void bullet::collisionDetect(ofVec2f enPos, int enWidth, int enHeight) {
	if((pos.x >= enPos.x && pos.x <= enPos.x + enWidth) &&
	   (pos.y >= enPos.y && pos.y <= enPos.y + enHeight)) {
		collided = true;
		

	}//if
	else {
		collided = false;
	}//else
}

bool bullet::returnCollided(){ return collided; }

//Collision of the bullet pick up item with the player. When the bullet item collides with the player, the total bullet count will go up by one.
void bullet::collisionDetectWithPlayer(ofVec2f enPos, int enWidth, int enHeight) {
	if((itemPos.x >= enPos.x && itemPos.x <= enPos.x + enWidth) &&
	   (itemPos.y >= enPos.y && itemPos.y <= enPos.y + enHeight)) {
		collidedWithPlayer = true;
	}//if
	else {
		collidedWithPlayer = false;
	}//else
}


bool bullet::returnCollidedWithPlayer(){ return collidedWithPlayer; }

void bullet::update() {
	//Adds the velocity vector onto the position so that the bullet can move
	pos += vel;
}//update

void bullet::display() {
	ofSetColor(241,233,17);
	ofFill();
	ofEllipse(pos.x, pos.y, 2,2);
	ofSetColor(255);
}//Display

void bullet::updateBulletItem() {
	itemPos += itemVel;
	theta += rotateSpeed;
	if(totalBullets <= 0) {
		totalBullets = 0;
	}
}
//Display the Total bullets string when the story mode is true
void bullet::displayString() {
	ofSetColor(90,13,218);
	ofFill();
	bulletTotal = "Total Bullets: ";
	bulletTotal += ofToString(getTotalBullets());
	bulletstring.drawString(bulletTotal, 350,30);
}

//Displays the bullet pick up item
void bullet::displayBulletItem() {
	ofPushMatrix();
	ofTranslate(itemPos.x, itemPos.y);
	ofSetColor(203,198,103);
	ofFill();
	ofRect(-2,-2,5,5);
	ofSetColor(241,233,17);
	ofFill();
	ofEllipse(0,0,3,3);
	ofSetColor(0);
	ofPopMatrix();
}

void bullet::reset() {
	totalBullets = 0;
}
int bullet::getTotalBullets() { return totalBullets; }

bullet::~bullet(void){
}//Deconstructor
