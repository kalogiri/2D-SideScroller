#include "enemyOrbitThree.h"

//This class handles the orbiting bodies for the third enemy/core type.

enemyOrbitThree::enemyOrbitThree(void) {
	diameter = 3;
	distance = 0;
	theta = 0;
	orbitSpeed = ofRandom(1,3);
	centerX = 200;
	topY = 0;
	equilibriumY = 200;
	yOffset = 200;
	xOffset = 100;
}

void enemyOrbitThree::update() {
	theta += orbitSpeed;
}


void enemyOrbitThree::display(int y) {
	ofPushMatrix();
	ofTranslate(distance, distance);
	ofSetColor(0,0,0);
	ofFill();
	ofEllipse(7, topY + y, diameter, diameter);
	ofEllipse(-7, topY - y, diameter, diameter);
	ofRotate(theta);
	ofSetColor(254,150,2);
	ofFill();
	ofEllipse(20 , 0, diameter,diameter);
	ofPopMatrix();
}


enemyOrbitThree::~enemyOrbitThree(void) {
}
