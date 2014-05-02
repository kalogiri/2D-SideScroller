#include "enemyOrbitOne.h"

//The Orbit class for the first enemy. The orbit class displays the orbiting bodies around the enemy/cores.

enemyOrbitOne::enemyOrbitOne(void) {
	diameter = ofRandom(1,3);
	distance = 3;
	theta = 0;
	orbitSpeed = ofRandom(1,3);
}

void enemyOrbitOne::update() {
	theta += orbitSpeed;
}
void enemyOrbitOne::display() {
	ofPushMatrix();
	ofRotate(theta);
	ofTranslate(distance, distance);
	ofSetColor(120,100,20);
	ofFill();
	ofEllipse(distance, distance, diameter,diameter);
	ofPopMatrix();
}

enemyOrbitOne::~enemyOrbitOne(void) {
}
