#include "enemyOrbitTwo.h"

//This class handles the orbiting bodies for the second enemy/core type.

enemyOrbitTwo::enemyOrbitTwo(void) {
	diameter = ofRandom(1,3);
	distance = 5;
	theta = 0;
	orbitSpeed = ofRandom(1,3);
}

void enemyOrbitTwo::update() {
	theta += orbitSpeed;
}
void enemyOrbitTwo::display() {
	ofPushMatrix();
	ofRotate(theta);
	ofTranslate(distance, distance);
	ofSetColor(255,0,0);
	ofFill();
	ofEllipse(distance, distance,diameter, diameter);
	ofSetColor(0);
	ofFill();
	ofLine(0, 0, distance, distance);
	ofPopMatrix();
}

enemyOrbitTwo::~enemyOrbitTwo(void) {
}
