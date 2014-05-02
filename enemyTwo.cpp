#include "enemyTwo.h"
//This is the second enemy/core type in the game.

enemyTwo::enemyTwo(){
	pos.set(700,ofRandom(55,330));
	vel.set(-1,0);
	collided = false;
	width = 10;
	height = 10;
}

//Draws the orbitting bodies around the core/enemies
void enemyTwo::drawOrbit() {
	for(int i = 0; i < orbit.size(); i++) {
		orbit[i].display();
		orbit[i].update();
	}
}

void enemyTwo::updateOrbit() {
	for(int i = 0; i < 1; i++) {
		orbit.push_back(enemyOrbitTwo());
		if(orbit.size() > 8) {
			orbit.erase(orbit.begin() + 8);
		}
	}
	drawOrbit();
}

void enemyTwo::update() {
	pos+=vel;
}

//Collision detection with the player
void enemyTwo::collisionDetect(ofVec2f playerPos, int playerWidth, int playerHeight) {
	if((pos.x >= playerPos.x && pos.x <= playerPos.x + playerWidth) &&
	   (pos.y >= playerPos.y && pos.y <= playerPos.y + playerHeight)) {
		collided = true;
	} else {
		collided = false;
	}
}
bool enemyTwo::returnCollided() { return collided; }

void enemyTwo:: display() {
	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofSetColor(0);
	ofFill();
	ofEllipse(0,0,10,10);
	ofSetColor(255,0,0);
	ofFill();
	ofEllipse(0,0,5,5);
	updateOrbit();
	ofPopMatrix();

}


enemyTwo::~enemyTwo(void)
{
}
