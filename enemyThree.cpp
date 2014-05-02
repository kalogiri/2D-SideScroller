#include "enemyThree.h"

//This is the third enemy/core type in the game.

enemyThree::enemyThree(){
	pos.set(700,ofRandom(55,330));
	vel.set(-1,0);
	collided = false;
	width = 20;
	height = 20;
	y = 10;
	dy = 0;
	k = 0.3;
	m = 20;
	theta = 0;
	rotateSpeed = 1;
}

//Draws the orbitting bodies around the enemy
void enemyThree::drawOrbiter() {
	for(int i = 0; i < orbiter.size(); i++) {
		orbiter[i].update();
		orbiter[i].display(y);
	}
}

//Updates the position of the 2 vertically oscillating ellipses around the enemy
void enemyThree::updatePosition() {
	float dyy = (float)(-1 * k * y) / m;
	dy = dy + dyy;
	y = y + dy;
}

void enemyThree::updateOrbiter() {
	for(int i = 0; i < 1; i++) {
		orbiter.push_back(enemyOrbitThree());
		if(orbiter.size() > 8) {
			orbiter.erase(orbiter.begin() + 8);
		}
	}
	updatePosition();
	drawOrbiter();
}

void enemyThree::update() {
	theta += rotateSpeed;
	pos+=vel;
}

//Collision detection with the player
void enemyThree::collisionDetect(ofVec2f playerPos, int playerWidth, int playerHeight) {
	if((pos.x >= playerPos.x && pos.x <= playerPos.x + playerWidth) &&
	   (pos.y >= playerPos.y && pos.y <= playerPos.y + playerHeight)) {
		collided = true;
	} else {
		collided = false;
	}
}

bool enemyThree::returnCollided() {	return collided; }

void enemyThree:: display() {
	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	updateOrbiter();
	ofRotate(theta);
	ofSetColor(254,42,2);
	ofFill();
	ofRect(-5,-5,10,10);
	ofSetColor(255);
	
	ofPopMatrix();

}
enemyThree::~enemyThree(void)
{
}
