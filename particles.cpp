#include "particles.h"

//Class handles the drawing of the background particles

particles::particles(){
	pos.set(600,ofRandom(0,400),0);
	vel.set(ofRandom(-3, -6),0,0);
	//vel.set(ofRandom(-5,-1),0,0);
}

void particles::update(){
	pos +=vel;
	vel.y += ofRandom(-0.1,0.1);
}

void particles::display(){
	//ofSetColor(100,20,50);
	ofSetColor(255,100,0);
	ofFill();
	ofRect(pos.x,pos.y,3,2);
	ofSetColor(0);
	ofFill();
	ofRect(pos.x,pos.y,2,1);
	ofSetColor(255); //Set this so that everything else after the ellipse will return to the default color, in this case white.
}
